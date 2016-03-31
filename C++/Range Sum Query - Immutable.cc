class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        sum_i.push_back(sum);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum_i.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sum_i[j+1] - sum_i[i];
    }
private:
    vector<int> sum_i;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
