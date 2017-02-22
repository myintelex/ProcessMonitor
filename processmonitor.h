#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#include <vector>
#include <string>

using std::string;
using std::vector;

class ProcessMonitor
{
public:
    enum ProcessState {
        NotRunning,
        Starting,
        Running
    };

    enum ExitStatus {
        NormalExit,
        CrashExit
    };

    ProcessMonitor();
    int start(const string path, vector<string> &argv);
    int start(const string path);
    void kill();

    int waitForExit();
    bool getProcessState();
    int getExitCode() const;
    int getSignalCode() const;
    bool getIsALive() const;
    bool getIsNormalExit() const;
private:
    int start();

private:
    string m_processPath;
    char **m_argv;
    int m_pid;
    int m_reval;

    int m_exitCode;
    int m_signalCode;

    bool m_isAlive;
    bool m_isNormalExit;
};

#endif // PROCESSMONITOR_H
