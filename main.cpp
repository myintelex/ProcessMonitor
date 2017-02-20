#include <iostream>
#include "processmonitor.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    ProcessMonitor proc;
    vector<string> arg(2);
    arg[0] = "-qws";
    arg[1] = "02";
    proc.start("/mnt/nandflash/app/tcu_alarm", arg);

  while(1)
  {
    sleep(1);
    if (proc.getProcessState())
      cout << "alive\n";
    else
      cout << "not alice\n";

  }

  return 0;
}
