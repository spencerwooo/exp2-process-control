#include <windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
  char cWindowsDirectory[MAX_PATH];
  LPTSTR cWinDir = new TCHAR[MAX_PATH];
  GetCurrentDirectory(MAX_PATH, cWinDir);

  LPTSTR sConLin = wcscat(cWinDir, L"\\ChildProcess.exe");

  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  ZeroMemory(&pi, sizeof(pi));

  if (CreateProcess(
          NULL,
          sConLin,
          NULL,
          NULL,
          false,
          0,
          NULL,
          NULL,
          &si,
          &pi))
  {
    cout << "[SUCCESS] Create Process success." << endl;
  }
  else
  {
    cerr << "[ERROR] Failed to create process." << endl;
  }

  Sleep(100);

  TerminateProcess(pi.hProcess, 300);
  ExitProcess(1001);
  return 0;
}
