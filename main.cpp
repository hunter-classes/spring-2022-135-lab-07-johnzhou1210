#include <iostream>
#include <fstream>

#include "reformat.h"

void test(std::string fileName)
{
  std::ifstream file; file.open(fileName);
  std::string str;
  int currIndentLevel = 0, nxtIndentLevel = 0, numOpen = 0, numClosed = 0;
  // std::cout << indentLevel << "\n";
  if (file.is_open())
  {
    while (std::getline(file, str))
    {
      std::string adjustedLine = removeLeadingSpaces(str);
      numOpen = countChar(adjustedLine, '{');
      numClosed = countChar(adjustedLine, '}');
      if (numOpen > 0)
      {
        // increase next indentation level
        nxtIndentLevel = nxtIndentLevel + numOpen;
      }
      if (numClosed > 0)
      {
        // decrease current indentation level
        currIndentLevel = currIndentLevel - numClosed;
        nxtIndentLevel = nxtIndentLevel - numClosed;
      }
      // tab by currIndentLevel
      adjustedLine = tabN(currIndentLevel) + adjustedLine;
      currIndentLevel = nxtIndentLevel;
      // std::cout << "currIndentLevel:" << currIndentLevel << ". nextIndentLevel : " << nxtIndentLevel << "\n";
      std::cout << adjustedLine << "\n";
    }
  }
  file.close();
}

void printTxt(std::string fileName)
{
  std::ifstream file; file.open(fileName);
  std::string str;
  if (file.is_open())
  {
    while (std::getline(file, str))
    {
      std::cout << str << "\n";
    }
  }
}

int main()
{
  std::cout << "=====================TEST 1: \"Fixed\" sloppy.cpp============================\n\n"; test("sloppy.cpp");
  std::cout << "=====================TEST 2: \"Fixed\" sloppy2.cpp============================\n\n"; test("sloppy2.cpp");
  std::cout << "=====================TEST 3: \"Fixed\" sloppy3.cpp============================\n\n"; test("sloppy3.cpp");
  std::cout << "================================END TESTS======================================\n";
  return 0;
}
