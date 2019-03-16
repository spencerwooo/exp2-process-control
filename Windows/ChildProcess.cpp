#include <windows.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  char name[10] = "武上博";
  cout << "Hi, my name is " << name << endl;

  // 延时三秒
  Sleep(3000);
  return 0;
}
