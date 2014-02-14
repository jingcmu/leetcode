//这题其实不难，题意是S中要出现L中所有单词连在一起的字符串起点（不按顺序）
//所以，这题甚至不需要用DFS或者动规
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string,int> words, cur;  
        vector<int> res; 
        int wordNum = L.size();  
        if(!wordNum) return res;
		int wordLen = L[0].size(); //字典中的单词长度都是一样的
        if(S.size() < wordLen*wordNum) return res; //S长度不够

        for(int i = 0; i < wordNum; i++)  
            words[L[i]]++;  //记录下字典中每个单词出现的个数(因为可能有重)

        for(int i = 0; i <= (int)S.size()-wordLen*wordNum; i++) {  
            cur.clear(); //用来存放当前的查找情况
            int j;  
            for(j = 0; j < wordNum; j++) {  
                string word = S.substr(i+j*wordLen, wordLen);  
                if(words.find(word) == words.end())  //找不到
                    break;  
                cur[word]++;  
                if(cur[word]>words[word]) //某个词出现的次数多了
                    break;  
            }  
            if(j == wordNum)  
                res.push_back(i);  
        }  
        return res; 
    }
}; 