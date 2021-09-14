// O(NlogN)
class Solution {
public:
    struct cmp{
        bool operator ()(const int &a, const int &b){ return a > b;}
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > ret;
        multimap<int, int> critical_points; // x坐标相同的点key相同
        for (int i = 0; i < buildings.size(); ++i) { // 把所有关键点都放入map
            vector<int> &vi = buildings[i];
            critical_points.insert(make_pair(vi[0], vi[2])); // key: x, val: height 左端点
            critical_points.insert(make_pair(vi[1], vi[2] * -1)); // key: x, val: -height 右端点
        }
        multiset<int, cmp> heights; // 追踪当前最大高度
        heights.insert(0);
        while (critical_points.size()) {
            int last_height = *heights.begin();
            int cur = critical_points.begin()->first;
            while (critical_points.begin()->first == cur) { // 对x坐标相同的点循环
                int height = critical_points.begin()->second;
                if (height > 0) { // 如果是左端点
                    heights.insert(height); // enter，加入高度追踪
                } else { // 如果是右端点
                    heights.erase(heights.find(height * -1)); // 离开，终止高度追踪
                }
                critical_points.erase(critical_points.begin()); // 删掉一个关键点
            }
            if (*heights.begin() != last_height) { // 当高度发生变化时记录
                ret.push_back(make_pair(cur, *heights.begin()));
            }
        }
        return ret;
    }
};

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
        // 把所有关键点都放入vector
        for (int i = 0; i < buildings.size(); ++i) {
            critical_points.push_back(point(buildings[i][0], buildings[i][2], true)); // left point
            critical_points.push_back(point(buildings[i][1], buildings[i][2], false)); // right point
        }
        // 对每个关键点查询每个building是否在其上，若是，则更新高度
        for (int i = 0; i < critical_points.size(); ++i) { // for every critical point
            for (int j = 0; j < buildings.size(); ++j) { // for every building
                if (critical_points[i].x >= buildings[j][0] && critical_points[i].x <= buildings[j][1]) {
                    critical_points[i].y = critical_points[i].is_left ? max(critical_points[i].y, buildings[j][2]) :
                                                                        min(critical_points[i].y, buildings[j][2]);
                }
            }
        }
        v_res.push_back(make_pair(critical_points[0].x, critical_points[0].y));
        // 追踪高度变化，若高度变化则记录
        for (int i = 1; i < critical_points.size(); ++i) { // for every critical point
            if (critical_points[i].y != critical_points[i - 1].y) {
                v_res.push_back(make_pair(critical_points[i].x, critical_points[i].y));
            }
        }
        return v_res;
    }
};
