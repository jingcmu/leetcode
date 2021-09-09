class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> pair;
        int len = dominoes.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
            if (pair.find(dominoes[i]) != pair.end()) {
                res += pair[dominoes[i]];
                pair[dominoes[i]]++;
            } else {
                pair[dominoes[i]] = 1;
            }
        }
        return res;
    }
};