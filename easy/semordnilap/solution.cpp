#include <vector>
#include <string>

using namespace std;

vector<vector<string>> semordnilap(vector<string> words) { // Time: O(n^2 * m) | Space: O(n) where n = words.size() and m is the length of the longest string
  vector<vector<string>> result;
  vector<bool> hasPair;
  bool isSemordnilap;

  for(int i = 0; i < words.size(); i++) {
    hasPair.push_back(false);
  }

  for(int i = 0; i < words.size(); i++) {
    for(int j = 0; j < words.size(); j++) {
      if (
        i == j ||
        words[i].size() != words[j].size() ||
        hasPair[i] || hasPair[j]
      ) {
        continue;
      }
      isSemordnilap = true;
      for(int k = 0; k < words[i].size(); k++) {
        if (words[i][k] != words[j][words[j].size() - 1 - k]) {
          isSemordnilap = false;
          break;
        }
      }
      if (isSemordnilap) {
        hasPair[i] = hasPair[j] = true;
        result.push_back({words[i], words[j]});
      }
    }
  }
  return result;
}
