#include <iostream>
#include <vector>
using namespace std;

vector<int> zigzagprint(vector<vector<int> > &m) {
  vector<int> res;
  int height = m.size();
  if (!height) return res;
  int width = m[0].size();
  if (!width) return res;
  bool dir = true; //true: down |  false: up
  int x = 0, y = 0; //start point
  res.push_back(m[x][y]);
  while (true) {
    if (y == width-1 && x == height-1) break;
    if (dir) {
      (y == width - 1)? res.push_back(m[++x][y]) : res.push_back(m[x][++y]);
      while (y > 0 && x < height-1) {
        res.push_back(m[++x][--y]);
      }
      dir = !dir;
    } else {
      (x == height - 1)? res.push_back(m[x][++y]) : res.push_back(m[++x][y]);
      while (x > 0 && y < width-1) {
        res.push_back(m[--x][++y]);
      }
      dir = !dir;
    }
  }
  return res;
}

int main() {
  vector<vector<int> > matrix(4, vector<int>(5));
  int height = matrix.size();
  int width = matrix[0].size();
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      matrix[i][j] = i * width + j;
    }
  }

  vector<int> res = zigzagprint(matrix);
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
}
