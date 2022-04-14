#include <iostream>
#include <fstream>

#include "reformat.h"

int main()
{
  std::cout << "=====================TEST 1 TASK A: \"Unindented\" sloppy.cpp============================\n" << std::endl;
  testA("sloppy.cpp");
  std::cout << "=====================TEST 1 TASK B: \"Fixed\" sloppy.cpp============================\n" << std::endl;
  testB("sloppy.cpp");
  std::cout << "=====================TEST 2 TASK A: \"Unindented\" sloppy2.cpp============================\n" << std::endl;
  testA("sloppy2.cpp");
  std::cout << "=====================TEST 2 TASK B: \"Fixed\" sloppy2.cpp============================\n" << std::endl;
  testB("sloppy2.cpp");
  std::cout << "=====================TEST 3 TASK A: \"Unindented\" sloppy3.cpp============================\n" << std::endl;
  testA("sloppy3.cpp");
  std::cout << "=====================TEST 3 TASK B: \"Fixed\" sloppy3.cpp============================\n" << std::endl;
  testB("sloppy3.cpp");
  std::cout << "================================END TESTS======================================" << std::endl;
  return 0;
}
