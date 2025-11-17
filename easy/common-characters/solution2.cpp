#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> commonCharacters(vector<string> strings) { // Time: O(n * m) | Space: O(m) where "n" is the strings.size() and "m" is the length of the longest string
  vector<string> resultVector;
  int min = 0;

  for(int i = 0; i < strings.size(); i++) {
    if (strings[i].size() < strings[min].size()) {
      min = i;
    }
  }

  unordered_set<char> result(strings[min].begin(), strings[min].end());

  for(int i = 0; i < strings.size(); i++) {
    vector<char> toErase;
    unordered_set<char> unique(strings[i].begin(), strings[i].end());
    for(unordered_set<char>::iterator itr = result.begin(); itr != result.end(); itr++) {
      if (unique.find(*itr) == unique.end()) {
        toErase.push_back(*itr);
      }
    }
    for(int i = 0; i < toErase.size(); i++) {
      result.erase(toErase[i]);
    }
  }

  for(auto value: result) {
    resultVector.push_back(string(1, value));
  }

  return resultVector;
}
