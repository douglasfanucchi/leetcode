#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> riverSizes(vector<vector<int>> matrix) { // Time: O(mn) | Space: O(mn) where m is matrix.size() and n = matrix[0].size()
    vector<vector<bool>> visited;
    queue<vector<int>> queue;
    vector<int> ans;

    for(int i = 0; i < matrix.size(); i++) {
        visited.push_back({});
        for(int j = 0; j < matrix[i].size(); j++) {
            visited[i].push_back(false);
        }
    }

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if (visited[i][j]) {
                continue;
            }
            if (matrix[i][j] == 1) {
                ans.push_back(0);
                queue.push({i, j});
            }
            while(queue.size()) {
                vector<int> tuple = queue.front();
                queue.pop();
                if (visited[tuple[0]][tuple[1]]) {
                    continue;
                }
                visited[tuple[0]][tuple[1]] = true;
                if (matrix[tuple[0]][tuple[1]] == 0) {
                    continue;
                }
                ans[ans.size() - 1]++;
                if (tuple[0] > 0) {
                    queue.push({tuple[0] - 1, tuple[1]});
                }
                if (tuple[0] < matrix.size() - 1) {
                    queue.push({tuple[0] + 1, tuple[1]});
                }
                if (tuple[1] > 0) {
                    queue.push({tuple[0], tuple[1] - 1});
                }
                if (tuple[1] < matrix[tuple[0]].size() - 1) {
                    queue.push({tuple[0], tuple[1] + 1});
                }
            }
        }
    }

    return ans;
}
