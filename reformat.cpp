#include <iostream>
#include <iostream>
#include <fstream>

int getFront(std::string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] != ' ')
    {
      return i;
    }
  }
  return -1;
}

std::string removeLeadingSpaces(std::string line)
{
  if (getFront(line) == -1)
  {
    return "";
  }
  // get indices of first and last non space characters
  return line.substr(getFront(line), line.length() - getFront(line) + 1);
}

int countChar(std::string line, char c)
{
  int count = 0;
  for (int i = 0; i < line.length(); i++)
  {
    if (line[i] == c)
    {
      count++;
    }
  }
  return count;
}

std::string tabN(int N)
{
  std::string result = "";
  for (int i = 1; i <= N; i++)
  {
    result = result + "\t";
  }
  return result;
}

void testA(std::string fileName)
{
  std::ifstream file; file.open(fileName);
  std::string str;
  if (file.is_open())
  {
    while (std::getline(file, str))
    {
      std::string adjustedLine = removeLeadingSpaces(str);
      std::cout << adjustedLine << std::endl;
    }
  }
  file.close();
}

void testB(std::string fileName)
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
      std::cout << adjustedLine << std::endl;
    }
  }
  file.close();
}
