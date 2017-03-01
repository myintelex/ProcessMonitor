#include "processmonitorprivate.h"

ProcessMonitorPrivate::ProcessMonitorPrivate()
{
  m_processState = ProcessMonitor::NotRunning;
  m_exitStatus = ProcessMonitor::NormalExit;
}