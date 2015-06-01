// O(n^2)的解法
struct point {
    int x;
    int y;
    bool is_left;
    point(int x_, int y_, bool is_left_)
        : x(x_), y(y_), is_left(is_left_){}
};
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<point> critical_points;
        vector<pair<int, int>> v_res;
        if (buildings.size() == 0) return v_res;
        for (int i = 0; i < buildings.size(); ++i) {
            critical_points.push_back(point(buildings[i][0], buildings[i][2], true)); // left point
            critical_points.push_back(point(buildings[i][1], buildings[i][2], false)); // right point
        }
        for (int i = 0; i < critical_points.size(); ++i) { // for every critical point
            for (int j = 0; j < buildings.size(); ++j) { // for every building
                if (critical_points[i].x >= buildings[j][0] && critical_points[i].x <= buildings[j][1]) {
                    critical_points[i].y = critical_points[i].is_left ? max(critical_points[i].y, buildings[j][2]) :
                                                                        min(critical_points[i].y, buildings[j][2]);
                }
            }
        }
        v_res.push_back(make_pair(critical_points[0].x, critical_points[0].y));
        for (int i = 1; i < critical_points.size(); ++i) { // for every critical point
            if (critical_points[i].y != critical_points[i - 1].y) {
                v_res.push_back(make_pair(critical_points[i].x, critical_points[i].y));
            }
        }
        return v_res;
    }
};
