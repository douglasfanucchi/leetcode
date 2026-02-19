#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void dfs(
    int i,
    int j,
    vector<vector<int>> &matrix
)
{
    stack<vector<int>> stack;
    if (matrix[i][j] != 1) {
        return;
    }

    stack.push({i, j});
    while (stack.size()) {
        vector<int> tuple = stack.top();
        stack.pop();
        matrix[tuple[0]][tuple[1]] = 2;

        if (tuple[0] > 0 && matrix[tuple[0] - 1][tuple[1]] == 1) {
            stack.push({tuple[0] - 1, tuple[1]});
        }
        if (tuple[0] < matrix.size() - 1 && matrix[tuple[0] + 1][tuple[1]] == 1) {
            stack.push({tuple[0] + 1, tuple[1]});
        }
        if (tuple[1] > 0 && matrix[tuple[0]][tuple[1] - 1] == 1) {
            stack.push({tuple[0], tuple[1] - 1});
        }
        if (tuple[1] < matrix[tuple[0]].size() - 1 && matrix[tuple[0]][tuple[1] + 1] == 1) {
            stack.push({tuple[0], tuple[1] + 1});
        }
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) { // Time: O(mn) | Space: O(mn) where m = matrix.size() and n = matrix[0].size()
    for(int i = 0; i < matrix[0].size(); i++)
        dfs(0, i, matrix);
    for(int i = 1; i < matrix.size(); i++)
        dfs(i, 0, matrix);
    for(int i = 1; i < matrix[matrix.size() - 1].size(); i++)
        dfs(matrix.size() - 1, i, matrix);
    for(int i = 1; i < matrix.size() - 1; i++)
        dfs(i, matrix[i].size() - 1, matrix);

    for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[i].size(); j++)
            if (matrix[i][j] == 2)
                matrix[i][j] = 1;
            else if(matrix[i][j] == 1)
                matrix[i][j] = 0;

    return matrix;
}
