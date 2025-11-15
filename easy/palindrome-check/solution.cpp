#include <string>

using namespace std;

bool isPalindrome(string str) { // Time: O(n) | Space: O(1)
  int start = 0, end = str.size() - 1;

  while (start < end) {
    if (str[start] != str[end]) {
      return false;
    }
    start++;
    end--;
  }

  return true;
}
