//允许重复元素，则上一题中如果A[m]>=A[l], 那么[l,m] 为递增序列的假设就不能成立了，比
//如[1,3,1,1,1]。
//如果A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
//若A[m]>A[l]，则区间[l,m] 一定递增
//若A[m]==A[l] 确定不了，那就l++，即跳过最左边的重复元素
//很显然，这不会影响结果
class Solution {
public:
	bool search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target) return true;		
			if (A[first] < A[mid]) {
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} else if (A[first] > A[mid]) {
				if (A[mid] <= target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			} else
				//跳过重复元素, A[start] == A[mid]
				first++;
		}
		return false;
	}
};