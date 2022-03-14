#include <iostream>

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
