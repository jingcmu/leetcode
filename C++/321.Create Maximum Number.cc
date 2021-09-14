class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res;
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i), k));
        }
        return res;
    }
    vector<int> maxVector(vector<int> nums, int k) {
      // 剩余多少字符
      int remain = nums.size();
      vector<int> res;
      for (int num : nums) {
        // 若剩余的字符大于需要的，则可以用后面大的替换掉前面小的
        while (remain + (int)res.size() > k && res.size() && res.back() < num)
          res.pop_back();
        if ((int)res.size() < k) {
          res.push_back(num);
        }
        remain--;
      }
      return res;
    }
    // 这不是一般的merge算法，要比较的是两个vector大小，比如{6,3}和{6,0,4}
    // 要先push第一个6，因为{6,3} > {6,0,4}
    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        while (nums1.size() + nums2.size()) {
            vector<int> &tmp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
