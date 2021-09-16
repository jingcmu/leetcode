Second Try:
//a better solution
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int left, right;
        for(right=size-1, left=right-1; left >=0; left--, right--) {
            if(num[left] < num[right]) {
                break;
            }
        }
        if(left < 0) {
            sort(num.begin(), num.end());
            return;
        }
        for(int i=size-1; i>=right; i--) {
            if(num[i] > num[left]) {
                swap(num[i], num[left]);
                break;
            }
        }
        sort(num.begin()+right, num.end());
    }
};

/*
����ʵ��ԭ��
�ڵ�ǰ�����У���β����ǰѰ����������Ԫ�أ�ǰһ����Ϊ*i����һ����Ϊ*ii����������*i < *ii��
Ȼ���ٴ�β��Ѱ����һ��Ԫ��*j���������*i < *j��������i��Ԫ�����j��Ԫ�ضԵ���
������ii��Ԫ��֮�󣨰���ii��������Ԫ�صߵ����򣬼������һ�������ˡ�
*/
class Solution {
public:
    void swap(vector<int> &num, int i, int j)  
    {  
        int temp = num[i];  
        num[i] = num[j];  
        num[j] = temp;  
    } 
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size(), index = -1;
        //�Ӻ���ǰ�ҳ��ֵĵ�һ���������е�����
        for(int i=len-2; i>=0; i--){
            if(num[i] < num[i+1]){
                index = i;//��¼�½�С����λ��
                break;
            }
        }
        if(index == -1){ //�Ҳ����������е�����,i < ii
            sort(num.begin(),num.end());
            return;
        }
        //��˳�����Ժ󣬴����ұ���һ������i��������i����
        for(int i=len-1; i>index; i--){
            if(num[i] > num[index]){
                swap(num, index, i);
                break;      //�ǵ�Ҫbreak������WA��һ��
            }
        }
		//Ȼ�󣬴�ii��ʼ�������򣬾͵õ�next_permutation��
        sort(num.begin()+index+1, num.end());
    }
};