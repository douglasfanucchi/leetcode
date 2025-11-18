#include <string>
#include <map>

using namespace std;

int firstNonRepeatingCharacter(string string) { // Time: O(n) | Space: O(1)
  unordered_map<char, int> map;

  for(int i = 0; i < string.size(); i++) {
    if (map.find(string[i]) == map.end()) {
      map[string[i]] = 0;
    }
    map[string[i]]++;
  }

  for(int i = 0; i < string.size(); i++) {
    char c = string[i];
    if (map[c] == 1) {
      return i;
    }
  }

  return -1;
}
