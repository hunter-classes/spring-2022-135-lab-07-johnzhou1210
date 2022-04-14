#include <iostream>

  std::string trapezoid(int width, int height) {
                                      std::string result;
  // check if it is possible first
if (width - (2 * (height - 1)) < 1) {
return "Impossible!";
}
int spaces = 0;
  int stars = width;
for (int i = 0; i < height; i++) {
for (int j = 0 ; j < spaces; j++) {
  result += " ";
}

for (int k = 0; k < stars; k++) {
result += "*";
        }
spaces += 1;
    stars -= 2;
  result += "\n";
  }
      return result;
}
