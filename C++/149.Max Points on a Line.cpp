/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/*
˼·��
��ÿ����Ϊ���ģ�������������֮���ߵ�б�ʣ�б����ͬ�ľ���һ������
ע���غϵ�Ĵ������ݽṹʹ��unordered_map���ڲ��ң���ÿ����Ϊ����
�����֮��Ҫ�������������㵽����б�ʣ�����Ƶ����
ֻ��Ҫ�㵱ǰ��֮��ĵ���֮������б�ʣ�֮ǰ�ĵ㲻��Ҫ��
*/
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        unordered_map<float, int> mp; //б�� ����
        int max_point = 0;
        for(int i=0; i<size; i++) {
            int duplicate = 1;
            mp.clear();
            mp[INT_MIN] = 0;
            for(int j = i+1; j<size; j++) {
                float k;
                //�����غϵ���(�п�������)
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue; //�غϵ㲻����б��
                }
                //����б��
                if(points[i].x == points[j].x) {
                    k = INT_MAX; //y���겻ͬ��x������ͬ��б�������
                }
                else {
                    k = (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                }
                mp[k]++; //ͳ����ͬб�ʵĵ�
            }
            unordered_map<float, int>::iterator it;
            for(it = mp.begin(); it != mp.end(); it++) {
                max_point = max(it->second + duplicate, max_point);
            }
        }
        return max_point;
    }
};