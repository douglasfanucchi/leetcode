#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void dfs(
    int i,
    int j,
    vector<vector<int>> matrix,
    vector<vector<int>> &isConnectedToTheBorder
) {
    stack<vector<int>> stack;
    stack.push({i, j});

    while(stack.size()) {
        vector<int> tuple = stack.top();
        stack.pop();
        if (matrix[tuple[0]][tuple[1]] == 0 || isConnectedToTheBorder[tuple[0]][tuple[1]]) {
            continue;
        }
        isConnectedToTheBorder[tuple[0]][tuple[1]] = 1;
        if (tuple[0] > 0) {
            stack.push({tuple[0] - 1, tuple[1]});
        }
        if (tuple[0] < matrix.size() - 1) {
            stack.push({tuple[0] + 1, tuple[1]});
        }
        if (tuple[1] > 0) {
            stack.push({tuple[0], tuple[1] - 1});
        }
        if (tuple[1] < matrix[tuple[0]].size() - 1) {
            stack.push({tuple[0], tuple[1] + 1});
        }
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) { // Time: O(mn) | Space: O(mn) where m = matrix.size() and n = matrix[0].size()
    vector<vector<int>> isConnectedToTheBorder;
    for(int i = 0; i < matrix.size(); i++) {
        isConnectedToTheBorder.push_back({});
        for(int j = 0; j < matrix[i].size(); j++)
            isConnectedToTheBorder[i].push_back(0);
    }

    for(int i = 0; i < matrix[0].size(); i++)
        if (matrix[0][i] == 1)
            dfs(0, i, matrix, isConnectedToTheBorder);
    for(int i = 1; i < matrix.size(); i++)
        if (matrix[i][0] == 1)
           dfs(i, 0, matrix, isConnectedToTheBorder);
    for(int i = 1; i < matrix[matrix.size() - 1].size(); i++)
        if (matrix[matrix.size() - 1][i] == 1)
            dfs(matrix.size() - 1, i, matrix, isConnectedToTheBorder);
    for(int i = 1; i < matrix.size(); i++)
        if (matrix[i][matrix[i].size() - 1])
            dfs(i, matrix[i].size() - 1, matrix, isConnectedToTheBorder);

    for(int i = 0; i < isConnectedToTheBorder.size(); i++) {
        for(int j = 0; j < isConnectedToTheBorder.size(); j++) {
            cout << isConnectedToTheBorder[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}
