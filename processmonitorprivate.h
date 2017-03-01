#ifndef PROCESSMONITORPRIVATE_H
#define PROCESSMONITORPRIVATE_H

#include <iostream>
#include <string>

class ProcessMonitorPrivate
{
public:
    ProcessMonitorPrivate();
    virtual ~ProcessMonitorPrivate();

    ProcessMonitor::ExitStatus m_exitStatus;
    ProcessMonitor::ProcessState m_processState;
    string m_workingDIrectory;
    pid_t pid;
};


#endif 
