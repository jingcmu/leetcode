/*
O(n^2)�Ľⷨ����ÿ�����ӣ�������չ��ֱ���������Լ����ģ�
����������ε��������һ��������¼����������ᳬʱ��

ͨ����¼�߶ȵ���ʼindex�����͸��Ӷ�
Actually, we can decrease the complexity by 
using stack to keep track of the height and start indexes. 
Compare the current height with previous one.

Case 1: current > previous (top of height stack)
Push current height and index as candidate rectangle start position.

Case 2: current = previous
Ignore.

Case 3: current < previous
Need keep popping out previous heights, and compute the 
candidate rectangle with height and width
(current index - previous index). Push the height and index to stacks
*/
class Solution {
public :
    int largestRectangleArea( vector< int> & height) {
        int len = height.size();
        if (len == 0) return 0; 
     
        int maxArea = 0; 
        stack< int> stackHeight; 
        stack< int> stackIndex; 
         
        for ( int i = 0; i < len; i++) { 
            //case 1���Ѹ��ߵ�height�ŵ�ջ�indexҲ�ŵ���Ӧ��ջ��
            if (stackHeight.size() == 0 || height[i] > stackHeight.top()) { 
                stackHeight.push( height[i]); 
                stackIndex.push(i); 
            } else if ( height[i] < stackHeight.top()) { 
                // case 3�������͵�height����ʼ����֮ǰ�ľ���
                int lastIndex = 0; 
                while (stackHeight.empty() == false && height[i] < stackHeight.top()) { 
                    lastIndex = stackIndex.top(); 
                    stackIndex.pop();
                    int tempArea = stackHeight.top() * (i - lastIndex); 
                    stackHeight.pop();
                    if (maxArea < tempArea) { 
                        maxArea = tempArea; 
                    } 
                } 
                stackHeight.push( height[i]); 
                stackIndex.push(lastIndex); 
            } 
        } 
         
        while(stackHeight.empty() == false) { 
            int tempArea = stackHeight.top() * (len - stackIndex.top()); 
            stackHeight.pop();
            stackIndex.pop();
            if (tempArea > maxArea) { 
                maxArea = tempArea; 
            } 
        } 
        return maxArea; 
    }
};