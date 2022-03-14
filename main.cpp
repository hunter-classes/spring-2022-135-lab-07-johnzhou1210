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

int main()
{
  test("sloppy.cpp");
  return 0;
}
