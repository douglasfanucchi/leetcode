#include <string>

using namespace std;

string runLengthEncoding(string str) {
  string result(str + str);
  int len = 0, runLength;

  for(int i = 0; i < str.size(); i++) {
    runLength = 1;

    while (str[i + 1] && str[i] == str[i + 1] && runLength < 9) {
      i++;
      runLength++;
    }

    result[len] = runLength + '0';
    result[len + 1] = str[i];
    len += 2;
  }

  return result.substr(0, len);
}
