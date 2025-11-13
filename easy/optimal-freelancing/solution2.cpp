#include <vector>
#include <map>

using namespace std;

int min(int x, int y) {
  if (x < y) {
    return x;
  }
  return y;
}

int optimalFreelancing(vector<unordered_map<string, int>> jobs) { // Time: O(n) | Space: O(1)
  int payment = 0, deadline, tmp;
  vector<int> payments = {0, 0, 0, 0, 0, 0, 0};

  for(int i = 0; i < jobs.size(); i++) {
    deadline = min(jobs[i]["deadline"] - 1, 6);
    for(; deadline >= 0; deadline--) {
      if (payments[deadline] < jobs[i]["payment"]) {
        tmp = payments[deadline];
        payments[deadline] = jobs[i]["payment"];
        jobs[i]["payment"] = tmp;
      }
    }
  }

  for(int i = 0; i < payments.size(); i++) {
    payment += payments[i];
  }

  return payment;
}
