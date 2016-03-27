/*
思路：
用哈希表来建立每个单词和其位置的映射，然后需要一个set来保存出现过的单词的长度，算法的思想是，遍历单词集，
对于遍历到的单词，我们对其翻转一下，然后在哈希表查找翻转后的字符串是否存在，
注意不能和原字符串的坐标位置相同，因为有可能一个单词翻转后和原单词相等，
现在我们只是处理了bat和tab的情况，还存在abcd和cba，dcb和abcd这些情况需要考虑，
这就是我们为啥需要用set，由于set是自动排序的，我们可以找到当前单词长度在set中的iterator，
然后从开头开始遍历set，遍历比当前单词小的长度，比如abcdd翻转后为ddcba，
我们发现set中有长度为3的单词，然后我们dd是否为回文串，若是，再看cba是否存在于哈希表，
若存在，则说明abcdd和cba是回文对，存入结果中，对于dcb和aabcd这类的情况也是同样处理，
我们要在set里找的字符串要在遍历到的字符串的左边和右边分别尝试，
看是否是回文对，这样遍历完单词集，就能得到所有的回文对
*/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        //把单词全部放入字典
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        //遍历每个单词
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            int len = t.size();
            //逆字符串
            reverse(t.begin(), t.end());
            //如果逆字符串就在字典里，则直接输出
            if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }
            //对每一个比len小的长度进行判断
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                //左边len-d长度是否为回文
                if (isValid(t, 0, len - d - 1) && m.count(t.substr(len - d))) {
                    res.push_back({i, m[t.substr(len - d)]});
                }
                //右边len-d长度是否为回文
                if (isValid(t, d, len - 1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }
        return res;
    }
    bool isValid(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) return false;
        }
        return true;
    }
};
