class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size();
        vector<int> v, v_last;
        vector<vector<int> > v_res;
        if(len<3){
            return v_res;
        }
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++){
            int target = 0-num[i];
            int head = i+1, tail = len - 1;
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
            while(head < tail){
                v.clear();
                if(num[head]+num[tail] == target){
                    v.push_back(num[i]);
                    v.push_back(num[head++]);
                    v.push_back(num[tail--]);
                    if(v_last != v){
                        v_res.push_back(v);
                        v_last = v;
                    }
                }
                else if(num[head]+num[tail] < target){
                    head++;
                }
                else if(num[head]+num[tail] > target){
                    tail--;
                }
            }
        }
        return v_res;
    }
};