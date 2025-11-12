#include <vector>
using namespace std;

int max(int n1, int n2) {
  if (n1 > n2) {
    return n1;
  }
  return n2;
}

int tandemBicycle(
  vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest
) {
  int result = 0;

  sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
  sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());

    for(int i = 0; i < redShirtSpeeds.size(); i++) {
      if (fastest) {
        result += max(
          redShirtSpeeds[i],
          blueShirtSpeeds[blueShirtSpeeds.size() - 1 - i]
        );
      } else {
        result += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
      }
    }

  return result;
}

