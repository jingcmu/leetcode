class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once.  
        map<string,int> words, cur;  
        vector<int> res; 
        int wordNum = L.size();  
        if(!wordNum) return res;
		int wordLen = L[0].size();
        if(S.size() < wordLen*wordNum)return res; 

        for(int i = 0; i < wordNum; i++)  
            words[L[i]]++;  //记录下每个单词出现的个数

        for(int i = 0; i <= (int)S.size()-wordLen*wordNum; i++)  
        {  
            cur.clear(); //用来存放当前的查找情况
            int j;  
            for(j = 0; j < wordNum; j++)  
            {  
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