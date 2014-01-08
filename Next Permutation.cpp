class Solution {
public:
    void swap(vector<int> &num, int i, int j)  
    {  
        int temp = num[i];  
        num[i] = num[j];  
        num[j] = temp;  
    } 
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size(), index = -1;
        //从后往前找出现的第一个升序排列的数对（后一个数大的数对）
        for(int i=len-2; i>=0; i--){
            if(num[i] < num[i+1]){
                index = i;//记录下较小数的位置
                break;
            }
        }
        if(index == -1){
            sort(num.begin(),num.end());
            return;
        }
        //在顺序数对后找最小的那个大于较小数的数，跟较小数交换
        for(int i=len-1; i>index; i--){
            if(num[i]>num[index]){
                swap(num, index, i);
                break;              //记得要break，这里WA了一次
            }
        }
        sort(num.begin()+index+1, num.end());
    }
};