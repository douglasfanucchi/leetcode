#include <vector>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
  int result = 0;

  sort(queries.begin(), queries.end()); // O(nlog(n))

  for(int i = 0; i < queries.size(); i++) { // O(n)
    result += queries[i] * (queries.size() - i - 1);
  }
  
  return result;
}
