class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size(), target2;
        vector<vector<int> > v_res;
        vector<int> v;
        if(len < 4){
            return v_res;
        }
        sort(num.begin(), num.end());
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                target2 = target - (num[i]+num[j]);
                int head = j+1, tail = len-1;
                while(head < tail){
                    if(num[head]+num[tail] < target2){
                        head++;
                    }
                    else if(num[head]+num[tail] > target2){
                        tail--;
                    }
                    else{
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[head]);
                        v.push_back(num[tail]);
                        v_res.push_back(v);
                        v.clear();
                        head++;
                        tail--;
                    }
                }
            }
        }
        set<vector<int> > s(v_res.begin(), v_res.end());
        v_res.assign(s.begin(), s.end());
        return v_res;
    }
};