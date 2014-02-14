//二分法查找的变形, 时间复杂度log n
//分别讨论各种情况
//与普通二分查找的区别是：普通二分法只需要将target和mid位置的数比较就可以排除一半元素
//而此题首先判断出那边是连续的段，然后判断target是否在连续的段中，进而排除一半元素
//因为如果不得到连续的段，就没法进行判断
class Solution {
public:
	int search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target)
				return mid;
			//左半边是连续的
			if (A[first] <= A[mid]) {
				//判断target是否在左段
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} 
			//右边是连续的
			else {
				//判断target是否在右段
				if (A[mid] < target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};