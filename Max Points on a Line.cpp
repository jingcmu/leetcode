/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = points.size();
        unordered_map<float, int> mp;
        int max = 0;
        for(int i=0; i<size; i++){
            int duplicate = 1;
            mp.clear();       //防止重复计算的情况  
            mp[INT_MIN] = 0;  //防止出现只有一个点的情况
            for(int j = i+1; j<size; j++){
                float k;
                //计算重合点数
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    duplicate++;
                    continue;
                }
                //计算斜率
                if(points[i].x == points[j].x){
                    k = INT_MAX;   //避免0作为除数
                }
                else{
                    k = (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                }
                mp[k]++;
            }
            unordered_map<float, int>::iterator it = mp.begin();
            for(; it != mp.end(); it++){
                max = it->second + duplicate > max?it->second + duplicate : max;
            }
        }
        return max;
    }
};