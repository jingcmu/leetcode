//貌似如果有重复的词也一律认为是anagram，
//而且，只要是anagram一律存到vector里不用担心顺序问题
//思路：对单词排序，然后存入map，如果map中有，则连同
//原有的词一起push到vector
//技巧：如果map中原来没有，则value存的是第一个出现的词的index
//这是为了找到第二个的时候，连同上一个一起存到vector，
//如果已经有了，就存-1，表明之前已经有了
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int size = strs.size();
        vector<string> res;
        map<string, int> mp_anagram;
        for(int i=0; i<size; i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map<string, int>::iterator it = mp_anagram.find(tmp);
            if(it == mp_anagram.end()){
                mp_anagram[tmp] = i;
            }
            else {
                if(mp_anagram[tmp] == -1) {
                    res.push_back(strs[i]);
                }
                else {
					//mp_anagram[tmp]存的是第一个词的index
                    res.push_back(strs[mp_anagram[tmp]]);
                    mp_anagram[tmp] = -1;
                    res.push_back(strs[i]);
                }
            }
        }
        return res;
    }
};