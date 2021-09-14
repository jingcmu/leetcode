//��һ���зǳ���Ľ���취
1. ����STL multiset���Զ�����, ����Ҫ�õ����Կռ临�Ӷ�, ʱ�临�Ӷ��Ǻ������O(nlogn)
������Ŀ��˵��Ҫ��stl��sort, ���������װ�
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

2. ��������
��Ϊ��Χ��֪�����ҷ�Χ��С�����Լ�������Ҳ���ԣ�����Ҫ����Ҫɨ��һ�Σ������ʱ��Ҫɨ��һ��
class Solution {
public:
	void sortColors(int A[], int n) {
		const int COLORNUM = 3;
		int counts[COLORNUM] = { 0 }; // ��¼ÿ����ɫ���ֵĴ���
		for (int i = 0; i < n; i++)
			counts[A[i]]++;
		for (int i = 0, index = 0; i < COLORNUM; i++)
			for (int j = 0; j < counts[i]; j++)
				A[index++] = i;
	}
};

3. ˫ָ��
��ߵ�ָ��red����red���ұߵ�ָ��blue����blue
��curָ���������ұ�ɨ�裬�������red�ͻ�����ߣ��������blue�ͻ����ұ�
���������redҲ����blue��cur�������ƶ�
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

4.��patition���� equal_to������bind1st or bind2nd
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

5. ����ʵ��partition(), ����C++11��patitionʹ�õ���ǰ�������, ��C++98ʹ�õ���˫�������
ForwardIterator��ǰ�������ģ�壬pred�Ǻ���ģ�壬Unary��ָֻ����һ��������predicate��ָ
�������������Ԥ��ģ�����bool���ͣ����Կ�����patition�������Ƿ���pred����true��Ԫ��һ��
����������ǰ�벿�֣����ص�λ���Ǻ�벿�ֵĵ�һ��Ԫ�أ�������ǰ�벿�ֵ����һ��Ԫ��
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