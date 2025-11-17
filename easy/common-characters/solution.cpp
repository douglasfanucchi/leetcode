#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

vector<string> commonCharacters(vector<string> strings) { // Time: O(n * m) | Space: O(c), where "n" is strings.size(), "m" is the length of the longest string and "c" is the amount of unique characters considering every string
  unordered_map<char, int> map;
  vector<string> result;

  for(int i = 0; i < strings.size(); i++) {
    unordered_set<char> uniqueChars(strings[i].begin(), strings[i].end());
    unordered_set<char>::iterator it;

    for(it = uniqueChars.begin(); it != uniqueChars.end(); it++) {
      if (map.find(*it) == map.end()) {
        map[*it] = 0;
      }
      map[*it]++;
    }
  }

  for(auto const&[key, value]: map) {
    if (value == strings.size()) {
      result.push_back(string(1, key));
    }
  }
 
  return result;
}
