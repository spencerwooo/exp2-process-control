#include <windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
  cout << "args_num: " << argc << endl;
  for (int i = 0; i < argc; i++)
  {
    cout << "arg " << i << " = " << argv[i] << endl;
  }
  return 0;
}
