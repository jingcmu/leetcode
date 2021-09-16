//2015/05/17
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2) {
            return findMedianSortedArrays(nums1, nums2, nums1.size(), nums2.size(), (total + 1) / 2);
        } else {
            return (findMedianSortedArrays(nums1, nums2, nums1.size(), nums2.size(), total / 2 + 1) +
                    findMedianSortedArrays(nums1, nums2, nums1.size(), nums2.size(), total / 2)) / 2;
        }
    }
private:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2, int m, int n, int k) {
        if (m > n) return findMedianSortedArrays(nums2, nums1, nums2.size(), nums1.size(), k);
        if (m == 0) return nums2[k-1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int p1 = min((int)nums1.size(), k/2);
        int p2 = k - p1;
        if (nums1[p1 - 1] < nums2[p2 - 1]) {
            return findMedianSortedArrays(vector<int>(nums1.begin() + p1, nums1.end()), nums2, m - p1, n, k - p1);
        } else if (nums1[p1 - 1] > nums2[p2 - 1]) {
            return findMedianSortedArrays(nums1, vector<int>(nums2.begin() + p2, nums2.end()), m, n - p2, k - p2);
        } else {
            return nums1[p1-1];
        }
        
    }
};

/*
这是一道非常经典的题。这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元
素中第k 大的元素。
O(m + n) 的解法比较直观，直接merge 两个数组，然后求第k 大的元素。
不过我们仅仅需要第k 大的元素，是不需要“排序”这么复杂的操作的。可以用一个计数器，
记录当前已经找到第m 大的元素了。同时我们使用两个指针pA 和pB，分别指向A 和B 数组的第
一个元素，使用类似于merge sort 的原理，如果数组A 当前元素小，那么pA++，同时m++；如果
数组B 当前元素小，那么pB++，同时m++。最终当m 等于k 的时候，就得到了我们的答案，O(k)
时间，O(1) 空间。但是，当k 很接近m + n 的时候，这个方法还是O(m + n) 的。
有没有更好的方案呢？我们可以考虑从k 入手。如果我们每次都能够删除一个一定在第k 大元
素之前的元素，那么我们需要进行k 次。但是如果每次我们都删除一半呢？由于A 和B 都是有序
的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2
个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结
论对于k 是奇数也是成立的）：
• A[k/2-1] == B[k/2-1]
• A[k/2-1] > B[k/2-1]
• A[k/2-1] < B[k/2-1]
如果A[k/2-1] < B[k/2-1]，意味着A[0] 到A[k/2-1 的肯定在A [ B 的top k 元素的范围
内，换句话说，A[k/2-1 不可能大于A [ B 的第k 大元素。留给读者证明。
因此，我们可以放心的删除A 数组的这k/2 个元素。同理，当A[k/2-1] > B[k/2-1] 时，可
以删除B 数组的k/2 个元素。
当A[k/2-1] == B[k/2-1] 时，说明找到了第k 大的元素，直接返回A[k/2-1] 或B[k/2-1]
即可。
因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
• 当A 或B 是空时，直接返回B[k-1] 或A[k-1]；
• 当k=1 是，返回min(A[0], B[0])；
• 当A[k/2-1] == B[k/2-1] 时，返回A[k/2-1] 或B[k/2-1]
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total & 0x1) { //奇数个元素,取中间元素
            return find_kth(A, m, B, n, total/2 + 1);
        }
        else { //偶数个元素,取中间两个元素的平均
            return (find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2 + 1))/2;
        }
    }
private:
    double find_kth(int A[], int m, int B[], int n, int k) {
        if(m > n) return find_kth(B, n, A, m, k); //假定m小于等于n,这样处理更方便
		//按照前面的分析，下面是两个终止的情况
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        //pa取k/2，如果m比k/2小，pa取m
        int pa = min(k/2, m), pb = k - pa; //二分法的变形
        if(A[pa-1] < B[pb-1]) { 
			//这种情况可以放心去掉A的pa个元素（k/2或者全部）
            return find_kth(A+pa, m-pa, B, n, k-pa);
        }
        else if(A[pa-1] > B[pb-1]) { 
			//这种情况可以放心去掉B的pb个元素（k/2或者更多）
            return find_kth(A, m, B+pb, n-pb, k-pb);
        }
        else {
            return A[pa-1];
        }
    }
}; 

//second method: using merge, time:O(m+n), space: O(m+n)
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int pm = 0, pn = 0;
    vector<double> v;
    while(v.size() < m+n) {
        if(pm < m && pn < n) {
            if(A[pm] <= B[pn]) {
                v.push_back(A[pm]);
                pm++;
            }
            else {
                v.push_back(B[pn]);
                pn++;
            }
        }
        else if(pm == m) {
            for(int i=pn; i<n; i++) v.push_back(B[i]);
        }
        else {
            for(int i=pm; i<m; i++) v.push_back(A[i]);
        }
    }
    if((m+n)%2) return v[(m+n)/2];
    else return (v[(m+n)/2-1] + v[(m+n)/2])/2;
}

//third method: using merge, time:O(m+n), space:O()
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int pm = 0, pn = 0, count = 0;
    double a = 0, b = 0;
    while(count++ < (m+n)/2 + 1) {
        a = b;
        if(pm < m || pn < n) {
            if(pm == m) {
                b = B[pn++];
            }
            else if(pn == n) {
                b = A[pm++];
            }
            else if(A[pm] <= B[pn]) {
                b = A[pm++];
            }
            else {
                b = B[pn++];
            }
        }
    }
    if((m+n)%2) return b;
    else return (a+b)/2;
}
