/*
用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置,，
由于map的特性一对一的映射关系，就决定了count函数的返回值只有两个，
要么是0，要么是1，出现的情况，当然是返回1了
unordered_map不允许有重复元素，但是输入的vector却可能有，因此在
初始化的时候，需要先判断num[i]是否出现过
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int len = num.size();
		//因为vector可能有重复元素，而unordered_map不能有
        for(int i=0; i<len; i++){
            if(map.count(num[i])){
                map[num[i]]++;
            }
            else{
                map[num[i]] = 1;
            }
        }
        int max_len = 0;
        for(int i=0; i<len; i++){
            int element1 = num[i]+1, element2 = num[i]-1;
            int count_biger = 0;//记录向右延伸的结果
            int count_smaller = 0;//记录向左延伸的结果
			//向右边延伸
            while(map.count(element1)){
                count_biger++;
                map.erase(element1++); //要从map中去掉
            }
			//向左边延伸
            while(map.count(element2)){
                count_smaller++;
                map.erase(element2--); //要从map中去掉
            }
            map.erase(num[i]);
            max_len = max(max_len, count_biger + count_smaller + 1);
        }
        return max_len;
    }
};

/*
如果允许O(n log n) 的复杂度，那么可以先排序，可是本题要求O(n)。
由于序列里的元素是无序的，又要求O(n)，首先要想到用哈希表。
用一个哈希表unordered_map<int, bool> used 记录每个元素是否使用，对每个元素，以该
元素为中心，往左右扩张，直到不连续为止，记录下最长的长度。
*/
class Solution {
public:
	int longestConsecutive(vector<int> const& num) {
		unordered_map<int, bool> used;
		for (auto i : num) used[i] = false;
		int longest = 0;
		for (auto i : num) {
			if (used[i]) continue; //如果访问过了就continue
			int length = 1;
			used[i] = true;
			//对unordered_map调用find可以不增加成员！！！
			for (int j = i + 1; used.find(j) != used.end(); ++j) {
				used[j] = true;
				++length;
			}
			for (int j = i - 1; used.find(j) != used.end(); --j) {
				used[j] = true;
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};