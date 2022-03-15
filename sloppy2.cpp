          #include <iostream>

      std::string determineEarlierDate(std::string date1, std::string date2)
  {
int month1 = std::stoi(date1.substr(0,2));
  int month2 = std::stoi(date2.substr(0,2));
    if (month1 > month2)
                                      {
                                return date2;
                              } else if (month1 != month2) {
            return date1;
}
          // now take care of the month's date
      int monthDay1 = std::stoi(date1.substr(3,2));
    int monthDay2 = std::stoi(date2.substr(3,2));
if (monthDay1 > monthDay2)
  {
                  return date2;
  }
                return date1;
                                  }
