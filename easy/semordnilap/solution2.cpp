#include <vector>
#include <string>
#include <map>

using namespace std;

vector<vector<string>> semordnilap(vector<string> words) { // Time: O(n * m) | Space: O(n * m) where n = words.size() and m is the length of the longest string.
  unordered_map<string, bool> map;
  vector<vector<string>> result;

  for(string word: words) {
    map[word] = false;
  }

  for(string word: words) {
    int left = 0, right = word.size() - 1;
    string palindrom(word);

    while (left < right) {
      char tmp = palindrom[left];
      palindrom[left] = palindrom[right];
      palindrom[right] = tmp;
      left++;
      right--;
    }

    if (map.find(palindrom) != map.end() && !map[palindrom] && word != palindrom) {
      result.push_back({word, palindrom});
      map[palindrom] = map[word] = true;
    }
  }

  return result;
}
