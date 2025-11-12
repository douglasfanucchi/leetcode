#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());

  int sum = 0;
  for(int i = 0; i < coins.size(); i++) {
    if (coins[i] > sum + 1) {
      break;
    }

    sum += coins[i];
  }
  return sum + 1;
}
