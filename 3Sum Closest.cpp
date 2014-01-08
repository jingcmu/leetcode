class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size();
        int sum = 0, target_2sum, head, tail;
        int diff, diff_min = (1<<31)-1;
        if(len<=3){
            for(int i=0; i<len; i++){
                sum += num[i];
            }
            return sum;
        }
        sort(num.begin(),num.end());
        for(int i=0; i<len-2; i++){
            target_2sum = target - num[i];
            head = i+1;
            tail = len-1;
            while(head < tail){
                sum = num[i]+num[head]+num[tail];
                diff = target - sum;
                if(diff == 0){
                    return target;
                }
                if(diff<0){
                    tail--;
                }
                else if(diff>0){
                    head++;
                }
                if(abs(diff_min)>abs(diff)){
                    diff_min = diff;
                }
            }
        }
        return target - diff_min;
    }
};