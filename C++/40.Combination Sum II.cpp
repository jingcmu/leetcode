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

//1.���д��̫�����ˣ�����
//ÿ��Ԫ������ȡ���ٲ�ȡ����ȡ�Ļ���������ֵ��ظ�Ԫ��Ҳ��ȡ
//ȡ�Ļ�������ݹ������һ���ˣ���Ȼ����ȡ�������Ͳ���д���ӵ��ж�
//����Ҫͳ��ÿ��Ԫ�س��ֵĴ�������ȻҲ���ظ���������ȥ�أ�����
//2.��ʵҲ������ͳ��Ԫ�س��ֵĴ�����Ȼ����Combination Sum I��д������
//�����Ļ��ͱ������������ȥ�أ�����������⵫�ǻ�Ƚϳ�
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
	// ʹ��nums[start, nums.size()) ֮���Ԫ�أ����ҵ������п��н�
	void dfs(vector<int> &nums, int target, int start, vector<int> &intermediate){
		if (target == 0) { // �ҵ�һ���Ϸ���
			result.push_back(intermediate);
			return;
		}
		int previous = -1;
		for (size_t i = start; i < nums.size(); i++) {
			//���֮ǰ���ֵ�û��ȡ�Ļ����������ͬԪ��Ҳ����ȡ
			if (previous == nums[i]) continue;
			if (target < nums[i]) return; // ��֦
			previous = nums[i];
			intermediate.push_back(nums[i]);
			dfs(nums, target - nums[i], i + 1, intermediate);
			intermediate.pop_back(); // �ָ�����
		}
	}
};
