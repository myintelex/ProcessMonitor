#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#include <vector>
#include <string>

#include "processsmonitorprivate.h"

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
    virtual ~ProcessMonitor();

    int start(const string path, vector<string> &argv);
    int start(const string path);

    void kill();

private:
    ProcessMonitorPrivate *m_private;
};

#endif // PROCESSMONITOR_H
