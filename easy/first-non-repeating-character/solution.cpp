#include <string>

using namespace std;

int firstNonRepeatingCharacter(string string) { // Time: O(n^2) | Space: O(1)
  bool repeated;

  for(int i = 0; i < string.size(); i++) {
    repeated = false;

    for(int j = 0; j < string.size(); j++) {
      if (string[i] == string[j] && i != j) {
        repeated = true;
      }
    }
    if (!repeated) {
      return i;
    }
  }

  return -1;
}
