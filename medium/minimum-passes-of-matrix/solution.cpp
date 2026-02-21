#include <vector>
#include <queue>

using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> matrix) { // Time: O(mn) | Space: O(mn)
    queue<vector<int>> queue;
    int ans = 0, positives;

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] > 0) {
                queue.push({i ,j});
            }
        }
    }

    positives = queue.size();
    while(queue.size()) {
        vector<int> pos = queue.front();
        queue.pop();
        positives--;

        if (pos[0] > 0 && matrix[pos[0] - 1][pos[1]] < 0) {
            matrix[pos[0] - 1][pos[1]] *= -1;
            queue.push({pos[0] - 1, pos[1]});
        }

        if (pos[0] < matrix.size() - 1 && matrix[pos[0] + 1][pos[1]] < 0) {
            matrix[pos[0] + 1][pos[1]] *= -1;
            queue.push({pos[0] + 1, pos[1]});
        }

        if (pos[1] > 0 && matrix[pos[0]][pos[1] - 1] < 0) {
            matrix[pos[0]][pos[1] - 1] *= -1;
            queue.push({pos[0], pos[1] - 1});
        }

        if (pos[1] < matrix[pos[0]].size() - 1 && matrix[pos[0]][pos[1] + 1] < 0) {
            matrix[pos[0]][pos[1] + 1] *= -1;
            queue.push({pos[0], pos[1] + 1});
        }

        if (!positives) {
            ans++;
            positives = queue.size();
        }
    }

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < 0) {
                return -1;
            }
        }
    }

    return ans - 1;
}
