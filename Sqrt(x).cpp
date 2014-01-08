//算法思想为二分法查找
//最后那步稍微修正下, 比如2的根号，应该是1
class Solution {
public:
    int sqrt(int x) {
        if(x < 2) return x;
        int smaller=0, biger=x; 
        int root;
        while(biger >= smaller){
            root = ((biger+smaller)>>1);
            if(root > x/root) biger = root-1;
            else if(root < x/root) smaller = root+1;
            else return root;
        }
        return root*root>x? root-1:root;
    }
};