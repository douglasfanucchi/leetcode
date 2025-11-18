#include <string>
#include <map>

using namespace std;

bool generateDocument(string characters, string document) { // Time: O(n + m) | Space: O(c), n = characters.size(), m = document.size() and c is the unique values in characters variable
  unordered_map<char, int> map;

  for(char c: characters) {
    if (map.find(c) == map.end()) {
      map[c] = 0;
    }
    map[c]++;
  }

  for(char c: document) {
    if (map.find(c) == map.end() || map[c] == 0) {
      return false;
    }
    map[c]--;
  }

  return true;
}
