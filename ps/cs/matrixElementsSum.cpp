int solution(vector<vector<int>> matrix) {
  // exclude rooms
  int n(matrix.size()), m(matrix[0].size()), sm(0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        for (int k = i; k < n; k++) {
          matrix[k][j] = 0;
        }
      }
      sm += matrix[i][j];
    }
  }
  return sm;
}
