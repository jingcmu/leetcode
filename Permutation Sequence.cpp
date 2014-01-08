class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n_x[10];
        vector<char> v;
        string s = "";
        if(n == 1){
            return "1";
        }
        n_x[0] = 1;
        for(int i=1; i<n; i++){
            n_x[i] = n_x[i-1]*i;
            v.push_back(i+48);
        }
		v.push_back(n+48);
        while(v.size()){
            int i = 0;
            while(k - n_x[n-(n-v.size()+1)] > 0){
                i++;
				k -= n_x[n-(n-v.size()+1)];
            }
            s += v[i];
            v.erase(v.begin()+i);
        }
        return s;
    }
};