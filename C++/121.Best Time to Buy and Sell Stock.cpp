/*
ɨ��һ�飬��¼��������min price���õ�ǰprice��ȥmin price��
��¼������profit
*/
class Solution {
public :
    int maxProfit(vector< int> &prices) {
        int min_price, profit = 0, len = prices.size();
        if(len) min_price = prices[0]; //��ʼ����С�۸�
        for(int i=1; i<len; i++){
			//������С�۸�
			min_price = min(prices[i], min_price);
			//�õ�ǰ��С�۸�����������
            profit = prices[i]-min_price > profit? prices[i]-min_price : profit;
        }
        return profit;
    }
};
