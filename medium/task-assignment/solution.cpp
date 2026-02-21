#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) { // Time: O(nlogn) | Space: O(n) where n is the number of tasks
    vector<vector<int>> ans;
    unordered_map<int, queue<int>> map;

    for(int i = 0; i < tasks.size(); i++) {
        map[tasks[i]].push(i);
    }

    sort(tasks.begin(), tasks.end());

    for(int i = 0; i < k; i++) {
        ans.push_back({
            map[tasks[i]].front(),
            map[tasks[((int)tasks.size()) - i - 1]].front()
        });
        map[tasks[i]].pop();
        map[tasks[((int)tasks.size()) - i - 1]].pop();
    }

    return ans;
}
