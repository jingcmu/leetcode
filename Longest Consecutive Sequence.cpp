class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<int, int> map;
        int len = num.size();
        for(int i=0; i<len; i++){
            if(map.count(num[i])){
                map[num[i]]++;
            }
            else{
                map.emplace(num[i],1);
            }
        }
        int max_len = 0;
        for(int i=0; i<len; i++){
            int element1 = num[i]+1, element2 = num[i]-1;
            int count_biger = 0;
            int count_smaller = 0;
            while(map.count(element1)){
                count_biger++;
                map.erase(element1++);
            }
            while(map.count(element2)){
                count_smaller++;
                map.erase(element2--);
            }
            map.erase(num[i]);
            max_len = max(max_len, count_biger + count_smaller + 1);
        }
        return max_len;
    }
};