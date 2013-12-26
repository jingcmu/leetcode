//这题跪了, 下面列出2个方法, 第一个方法好写好记, 2个方法没有数量级上的差别
//第一个方法：
//创建一个长度为sizeof(int) 的数组count[sizeof(int)]，count[i] 表示所有元
//素的1 在i 位出现的次数。如果count[i] 是3 的整数倍，则忽略；
//否则就把该位取出来组成答案。
class Solution {
public:
	int singleNumber(int A[], int n) {
		const int W = sizeof(int) * 8; // 整数字长
		int count[W]; // 每个位上1 出现的次数
		fill_n(&count[0], W, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < W; j++) {
				count[j] += (A[i] >> j) & 1;
				count[j] %= 3;
			}
		}
		int result = 0;
		for (int i = 0; i < W; i++) 
		    if(count[i]) result += (1 << i);
		return result;
	}
};

//方法2：用ones 记录到当前处理的元素为止，二进制1 出现“1 次”（mod 3 之后的1）的
//有哪些二进制位；用twos 记录到当前计算的变量为止，二进制1 出现“2 次”（mod 3 之后的2）
//的有哪些二进制位。当ones 和twos 中的某一位同时为1 时表示该二进制位上1 出现了3 次，
//此时需要清零。即用二进制模拟三进制运算。最终ones 记录的是最终结果。
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int twos = 0, ones = 0, xthrees;
        for(int i=0; i<n; i++){
            twos |= ones&A[i];
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};