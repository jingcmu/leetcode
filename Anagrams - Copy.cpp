class Solution {
public :
    vector<string> anagrams(vector<string> & strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = strs.size();
        vector<string> res;
        map<string, int> mp_anagram;
        map<string, int>::iterator it;
        for( int i=0; i<size; i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            it = mp_anagram.find(tmp);
            if(it == mp_anagram.end()){
                mp_anagram[tmp] = i;
            }
            else{
                if(mp_anagram[tmp] == -1){
                    res.push_back( strs[i]);
                }
                else{
                    res.push_back( strs[mp_anagram[tmp]]);
                    mp_anagram[tmp] = -1;
                    res.push_back( strs[i]);
                }
            }
        }
        return res;
    }
};
