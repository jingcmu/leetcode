class Solution {
public:
    void swap(vector<int> &num, int i, int j){
        int tmp;
        tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    void permute(vector<vector<int> > &v_res, vector<int> &num, int k, int len){
        vector<int> v;
        if(k == len){
            for(int i=0; i<=len; i++){
                v.push_back(num[i]);
            }
            v_res.push_back(v);
        }
        else{
            for(int i=k; i<=len; i++){
                swap(num, k, i);
                permute(v_res, num, k+1, len);
                swap(num, k, i);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > v_res;
        permute(v_res, num, 0, num.size()-1);
        set<vector<int> > S(v_res.begin(), v_res.end());
        v_res.assign(S.begin(), S.end());
        return v_res;
    }
};