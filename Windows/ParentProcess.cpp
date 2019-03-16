#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <tchar.h>

using namespace std;

int main(int argc, TCHAR *argv[])
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  SYSTEMTIME stStart, stEnd;

  // 命令使用说明
  if (argc != 2)
  {
    cout << "[INFO] Usage: " << argv[0] << " [cmdline]" << endl;
    return 0;
  }

  // 使用 CreateProcess() 创建进程
  if (CreateProcess(
          NULL,
          argv[1],
          NULL,
          NULL,
          false,
          0,
          NULL,
          NULL,
          &si,
          &pi))
  {
    cout << "[SUCCESS] Successfully created process." << endl;
  }
  else
  {
    cerr << "[ERROR] Failed to create process." << endl;
  }

  GetSystemTime(&stStart);

  // 使用 WaitForSingleObject() 在 ParentProcess 命令和新创建的进程之间同步
  WaitForSingleObject(pi.hProcess, INFINITE);

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  GetSystemTime(&stEnd);
  cout << "[CLOSED] Child process closed." << endl;

  int processStartTime = 60 * 1000 * stStart.wMinute + 1000 * stStart.wSecond + stStart.wMilliseconds;
  int processEndTime = 60 * 1000 * stEnd.wMinute + 1000 * stEnd.wSecond + stEnd.wMilliseconds;
  int processDuration = processEndTime - processStartTime;

  cout << "[INFO] Process start time: " << processStartTime << " ms" << endl;
  cout << "[INFO] Process end time: " << processEndTime << " ms" << endl;
  cout << "[INFO] Process duration: " << processDuration << " ms" << endl;

  return 0;
}
