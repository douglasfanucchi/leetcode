#include <vector>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
  vector<int> waiting;
  int waitingTime = 0, result = 0;

  sort(queries.begin(), queries.end());

  for(int i = 1; i < queries.size(); i++) {
    waitingTime += queries[i - 1];
    result += waitingTime;
  }

  return result;
}
