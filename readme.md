# ProcessMonitor
这是我自己简单编写的一个进程类，仅用于 Linux 系统。

## 来由
在 TCU 的项目中，之前的代码大量使用了 `system（）` 进行系统调用。当我接手后发现 `system()` 造成了很多出乎意料的问题，很容易被其他进程干扰，而原因却非常难以定位。为了解决这些问题，当然是使用 `exec` 函数族来代替 `system()` 的使用。因此，有了第一版简单的 `ProcessMonitor` 类。

## 功能
`ProcessMonitor` 每一个实现都是一个单独的进程，现在实现了进程的启动、停止、状态查询和出错状态查询等功能。参考了 Qt 的 `QProcess` 类，还期待添加打印输出。并将持续完善进程的相关状态获取等功能。

## 计划
1. 对照相关代码，完善现存的功能
2. 完善打印的相关功能
3. 完善相应的进程状态功能
