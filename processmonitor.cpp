#include "processmonitor.h"

ProcessMonitor::ProcessMonitor()
{
    m_private = new ProcessMonitorPrivate();
}
int ProcessMonitor::start(const string path, vector<string> &argv)
{
  if (m_private)
    m_processPath = path;
    int argc = argv.size();
    m_argv = new char *[argc+2];
    m_argv[0] = new char[m_processPath.size() + 1];
    strncpy(m_argv[0], m_processPath.c_str(), m_processPath.size() + 1);
    for (int i = 0; i < argc; i++)
    {
        m_argv[i+1] = new char[argv[i].size() + 1];
        strncpy(m_argv[i+1], argv[i].c_str(), argv[i].size() + 1);
    }
    m_argv[argc+1] = 0;
    int ret = start();
    for (int i = 0; i < argc+2; i++)
    {
        delete m_argv[i];
    }
    delete m_argv;
    return ret;
}

int ProcessMonitor::start(const string command)
{
    string cmd = command;
    string::size_type pos;
    vector<string> result;
    cmd = cmd + " ";
    int size = cmd.size();

    for(int i=0; i<size; i++)
    {
      pos = cmd.find(" ",i);
      if(pos<size)
      {
        string s = cmd.substr(i,pos-i);
        result.push_back(s);
        i=pos;
      }
    }
    m_processPath = result.at(0);
    result.erase(result.begin());
    int ret = start(m_processPath, result);
    return ret;
}

int ProcessMonitor::waitForExit()
{
    if (m_pid <= 0)
        return 0;
    int ret = waitpid(m_pid, &m_reval, 0);
    if (ret == m_pid)
    {
        return m_reval;
    }
    else
    {
        return -1;
    }
}



int ProcessMonitor::start()
{
  pid_t pid;
  int status;
  if((pid = fork()) < 0)
  {
    m_pid = -1;
  }
  else if(pid == 0)
  {
    if((status = execvp(m_processPath.c_str(), m_argv)) < 0)
    {
      m_pid = -1;
    }
  }
  else
  {
    m_pid = pid;
  }
  return pid;
}

bool ProcessMonitor::getProcessState()
{
  if (m_pid < 0)
    return false;

  int retval;
  int state = waitpid(m_pid, &retval, WNOHANG);

  if (state > 0)
  {
    if (0 != WIFEXITED(retval))
    {
      m_isNormalExit = true;
      m_exitCode = WEXITSTATUS(retval);
    }
    else if (0 != WIFSIGNALED(retval))
    {
      m_isNormalExit = false;
      m_signalCode = WTERMSIG(retval);
    }
    else if (0 != WIFSTOPPED(retval))
    {
      m_isNormalExit = false;
      m_signalCode = WSTOPSIG(retval);
    }
    m_isAlive = false;
  }
  else
  {
    m_isAlive = true;
  }

  return m_isAlive;
}

int ProcessMonitor::getExitCode() const
{
  return m_exitCode;
}

int ProcessMonitor::getSignalCode() const
{
  return m_signalCode;
}

bool ProcessMonitor::getIsALive() const
{
  return m_isAlive;
}

bool ProcessMonitor::getIsNormalExit() const
{
  return m_isNormalExit;
}
