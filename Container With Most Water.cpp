//开始板子处在两端，然后让短的往中间移动
//过程中算出最大的容积，直到两个板子碰头
class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size(), res = 0;
        int i = 0, j=len-1;
        while(i<j){
            res = max(res, min(height[i],height[j])*(j-i));
            height[i]>height[j]? j--:i++;
        }
        return res;
    }
};