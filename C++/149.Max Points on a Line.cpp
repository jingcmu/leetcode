/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/*
思路：
以每个点为中心，计算其他点与之连线的斜率，斜率相同的就在一条线上
注意重合点的处理，数据结构使用unordered_map便于查找，以每个点为中心
算出来之后都要查找所有其他点到它的斜率，查找频繁！
只需要算当前点之后的点与之的连线斜率，之前的点不需要算
*/
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        unordered_map<float, int> mp; //斜率 点数
        int max_point = 0;
        for(int i=0; i<size; i++) {
            int duplicate = 1;
            mp.clear();
            mp[INT_MIN] = 0;
            for(int j = i+1; j<size; j++) {
                float k;
                //计算重合点数(有可能有重)
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue; //重合点不必算斜率
                }
                //计算斜率
                if(points[i].x == points[j].x) {
                    k = INT_MAX; //y坐标不同，x坐标相同，斜率无穷大
                }
                else {
                    k = (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                }
                mp[k]++; //统计相同斜率的点
            }
            unordered_map<float, int>::iterator it;
            for(it = mp.begin(); it != mp.end(); it++) {
                max_point = max(it->second + duplicate, max_point);
            }
        }
        return max_point;
    }
};