/*二维的等于一维的相加, 一维的最小点必在median点(用反证法可以证明)*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int min_dist = 0;
        vector<int> row, col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        // col需要排序，row本来就是顺序的
        sort(col.begin(), col.end());
        int mid_row = row[row.size()/2], mid_col = col[col.size()/2];
        for(int i = 0; i < row.size(); i++) {
            min_dist += abs(row[i] - mid_row);
        }
        for (int j = 0; j < col.size(); j++) {
            min_dist += abs(col[j] - mid_col);
        }
        return min_dist;
    }
};
