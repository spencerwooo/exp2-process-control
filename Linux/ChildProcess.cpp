#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
  char name[10] = "武上博";
  cout << "Hi, my name is " << name << endl;

  // 延时三秒
  sleep(3);
  return 0;
}
