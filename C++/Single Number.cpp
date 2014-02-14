First Try:
//using exclusive or to remove all bits which appear even times.
class Solution {
public:
   int singleNumber(int A[], int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	   int res = 0;
	   for(int i=0; i<n; i++){
		   res ^= A[i];
	   }
	   return res;
   }
};

Second Try:
//using exclusive or to remove all bits which appear even times.
//totally without extra space
class Solution {
public:
   int singleNumber(int A[], int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	   for(int i=1; i<n; i++){
		   A[0] ^= A[i];
	   }
	   return A[0];
   }
};