#include <vector>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  vector<vector<int>> transposed;

  int rows = matrix[0].size();
  int columns = matrix.size();

  for (int i = 0; i < rows; i++) {
    vector<int> row;
    for(int j = 0; j < columns; j++) {
      row.push_back(0);
    }
    transposed.push_back(row);
  }

  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
      transposed[j][i] = matrix[i][j];
    }
  }
  
  return transposed;
}
