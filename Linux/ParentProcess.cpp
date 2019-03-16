#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

using namespace std;

int main(int argc, char const *argv[])
{
  struct timeval startTime;
  struct timeval endTime;

  // 操作说明
  if (argc != 2)
  {
    cout << "[INFO] Usage: " << argv[0] << " [cmdline]" << endl;
    return 0;
  }

  gettimeofday(&startTime, NULL);
  // fork() 创建进程
  pid_t pid = fork();

  if (pid < 0)
  {
    cout << "[ERROR] Process fork failed." << endl;
    exit(-1);
  }

  if (pid == 0)
  {
    // execv() 执行 ChildProcess 程序
    if (execv(argv[1], NULL) < 0)
    {
      cout << "[ERROR] Execute child process failed." << endl;
      exit(-1);
    }
  }

  // wait() 等待新创建的进程结束
  // 这里使用 waitpid() 为了获取子进程的返回值
  int childProcessReturnStat;
  waitpid(pid, &childProcessReturnStat, 0);
  cout << "[CLOSED] Child process exited with code " << WEXITSTATUS(childProcessReturnStat) << "." << endl;
  gettimeofday(&endTime, NULL);

  long childProcessStartTime = (startTime.tv_sec) * 1000 + (startTime.tv_usec) / 1000;
  long childProcessEndTime = (endTime.tv_sec) * 1000 + (endTime.tv_usec) / 1000;
  cout << "[INFO] Process start time: " << childProcessStartTime << " ms" << endl;
  cout << "[INFO] Process end time: " << childProcessEndTime << " ms" << endl;

  long childProcessDuration = childProcessEndTime - childProcessStartTime;
  cout << "[INFO] Process duration: " << childProcessDuration << " ms" << endl;

  exit(0);

  return 0;
}
