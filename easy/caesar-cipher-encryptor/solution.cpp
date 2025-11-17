#include <string>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
  char position, newPosition;
  int alphabetLength = ('z' - 'a' + 1);

  for(int i = 0; i < str.length(); i++) {
    position = str[i] - 'a';
    newPosition = ((position + key) % alphabetLength);
    str[i] = newPosition + 'a';
  }

  return str;
}
