#include <map>
#include <vector>

using namespace std;

int optimalFreelancing(vector<unordered_map<string, int>> jobs) { // Time: O(nlogn) | Space: O(1)
  int payment = 0, deadline;
  vector<int> payments = {0, 0, 0, 0, 0, 0, 0};

  sort(jobs.begin(), jobs.end(), [](
    unordered_map<string, int> a,
    unordered_map<string, int> b
  ) {
    return a["payment"] > b["payment"];
  });

  for(int i = 0; i < jobs.size(); i++) {
    deadline = jobs[i]["deadline"];
    if (deadline > 7) {
      deadline = 7;
    }
    deadline--;
    for(;deadline >= 0; deadline--) {
      if (payments[deadline] == 0) {
        payments[deadline] = jobs[i]["payment"];
        break;
      }
    }
  }

  for(int i = 0; i < payments.size(); i++) {
    payment += payments[i];
  }

  return payment;
}
