//这一题有非常多的解题办法
1. 利用STL multiset的自动排序, 但是要用到线性空间复杂度, 时间复杂度是红黑树的O(nlogn)
不过题目有说不要用stl的sort, 这样算作弊吧
class Solution {
public:
    void sortColors(int A[], int n) {
        multiset<int> m;
        int i;
        for(i=0; i<n; i++) {
            m.insert(A[i]);
        }
        i=0;
        for(multiset<int>::iterator it = m.begin(); i<n; i++, it++) {
            A[i] = *it;
        }
    }
};

2. 计数排序
因为范围已知，而且范围巨小，所以计数排序也可以，不过要计数要扫描一次，输出的时候还要扫描一次
class Solution {
public:
	void sortColors(int A[], int n) {
		const int COLORNUM = 3;
		int counts[COLORNUM] = { 0 }; // 记录每个颜色出现的次数
		for (int i = 0; i < n; i++)
			counts[A[i]]++;
		for (int i = 0, index = 0; i < COLORNUM; i++)
			for (int j = 0; j < counts[i]; j++)
				A[index++] = i;
	}
};

3. 双指针
左边的指针red跟踪red，右边的指针blue跟踪blue
用cur指针从左边向右边扫描，如果碰到red就换到左边，如果碰到blue就换到右边
如果即不是red也不是blue，cur就往后移动
class Solution {
public:
    void sortColors(int A[], int n) {
        int red =0, blue = n-1, cur = 0;        
        while(cur<=blue){
            if(A[cur] == 0)
				swap(A[cur++],A[red++]); 
            else if(A[cur] == 2){
                swap(A[cur], A[blue--]);
            }
            else cur++;
        }
    }
};

4.用patition函数 equal_to函数和bind1st or bind2nd
class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
                    bind1st(equal_to<int>(), 1));
    }
};

or

class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind2nd(equal_to<int>(), 0)), A + n,
                    bind2nd(equal_to<int>(), 1));
    }
};

5. 重新实现partition(), 这里C++11的patition使用的是前向迭代器, 而C++98使用的是双向迭代器
ForwardIterator是前向迭代器模板，pred是函数模板，Unary是指只接受一个参数，predicate是指
这个函数是用来预测的，返回bool类型，可以看出，patition的作用是凡是pred返回true的元素一律
交换到容器前半部分，返回的位置是后半部分的第一个元素，而不是前半部分的最后一个元素
class Solution {
public:
	void sortColors(int A[], int n) {
		partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
		bind1st(equal_to<int>(), 1));
	}
	private:
	template<typename ForwardIterator, typename UnaryPredicate>
	ForwardIterator partition(ForwardIterator first, ForwardIterator last,UnaryPredicate pred){
		auto pos = first;
		for (; first != last; ++first)
			if (pred(*first))
				swap(*first, *pos++);
		return pos;
	}
};