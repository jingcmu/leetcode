//a better solution: easier to understand
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        size = num.size();
        sort(num.begin(), num.end());
        dfs(0, target, path, num);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    int size; 
    void dfs(int cur_index, int target, vector<int> &path, vector<int> &num) {
        if(target < 0) return;
        if(target == 0) {
            res.push_back(path);
            return;
        }
        for(int i=cur_index; i<size; i++) {
            path.push_back(num[i]);
            dfs(i+1, target - num[i], path, num);
            path.pop_back();
            while(i<size-1 && num[i] == num[i+1]) i++; //skip all other same value in this layer
        }
    }
};

//1.这个写法太巧妙了！！！
//每个元素是先取，再不取，不取的话，后面出现的重复元素也不取
//取的话，后面递归进到下一级了，仍然可以取，这样就不必写复杂的判断
//不需要统计每个元素出现的次数，居然也不必给结果排序和去重！！！
//2.其实也可以先统计元素出现的次数，然后按照Combination Sum I的写法来做
//那样的话就必须给结果排序和去重，代码容易理解但是会比较长
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> intermediate;
		dfs(nums, target, 0, intermediate);
		return result;
	}
private:
    vector<vector<int> > result;
	// 使用nums[start, nums.size()) 之间的元素，能找到的所有可行解
	void dfs(vector<int> &nums, int target, int start, vector<int> &intermediate){
		if (target == 0) { // 找到一个合法解
			result.push_back(intermediate);
			return;
		}
		int previous = -1;
		for (size_t i = start; i < nums.size(); i++) {
			//如果之前出现的没有取的话，后面的相同元素也不必取
			if (previous == nums[i]) continue;
			if (target < nums[i]) return; // 剪枝
			previous = nums[i];
			intermediate.push_back(nums[i]);
			dfs(nums, target - nums[i], i + 1, intermediate);
			intermediate.pop_back(); // 恢复环境
		}
	}
};
