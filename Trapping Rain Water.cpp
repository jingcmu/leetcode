/*
两种解法：
对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的水就是
min(max_left,max_right) - height。所以，
1. 从左往右扫描一遍，对于每个柱子，求取左边最大值；
2. 从右往左扫描一遍，对于每个柱子，求最大右值；
3. 再扫描一遍，把每个柱子能容纳的水累加起来就行了
也可以，
1. 扫描一遍，找到最高的柱子，这个柱子将数组分为两半；
2. 处理左边一半；
3. 处理右边一半。
*/
class Solution {
public:
    int trap(int A[], int n) {
        int maxIdx=0, max=A[0], max_bar, rain = 0;
        //获取最长板的位置
        for(int i=1; i<n; i++){
            if(A[i] > max){
                max = A[i];
                maxIdx = i;
            }
        }
        //左侧逼近
        max_bar = A[0];
        for(int i=1; i<maxIdx; i++){
            if(A[i] < max_bar){
                rain += (max_bar - A[i]);
            } 
            else{
                max_bar = A[i];
            }
        }
        //右侧逼近
        max_bar = A[n-1];
        for(int i=n-2; i>maxIdx; i--){
            if(A[i] < max_bar){
                rain += (max_bar - A[i]);
            } 
            else{
                max_bar = A[i];
            }
        }
        return rain;
    }
};