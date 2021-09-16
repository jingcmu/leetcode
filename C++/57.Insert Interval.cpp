/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public :
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res; //��ʼ�ǿյ�
        bool merged = false; //��ʾ�Ƿ��Ѿ��ɹ�merge
        int size = intervals.size();
        for( int i=0; i<size; i++) {
			//newInterval.start��intervals[i].end֮ǰ���ʹ�����Ҫmerge�ˣ�
            if(!merged && newInterval.start <= intervals[i].end){
				//update��Interval�����
                newInterval.start = newInterval.start < intervals[i].start? newInterval.start : intervals[i].start;
				//newInterval.end �� intervals[i].start֮�������interval���
                if(newInterval.end >= intervals[i].start) {
                    //update��Interval���յ�
                    newInterval.end = newInterval.end > intervals[i].end? newInterval.end : intervals[i].end;
                    if(i == size-1) { //�������û��interval��
                        merged = true;
                        res.push_back(newInterval);
						break��
                    }
                    continue;
                }
                else { //���newInterval.end �� intervals[i].start֮ǰ�������newInterval�����Ϊ��merge
                    merged = true; //marked as "have merged"
                    res.push_back(newInterval);
                }
            }
            res.push_back(intervals[i]); //����û��merge�Ļ�������interval֮ǰ����intervals����push��res��
        }
        if(!merged) {
            res.push_back(newInterval);
        }
        return res;
    }
};
