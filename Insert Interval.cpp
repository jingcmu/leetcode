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
        vector<Interval> res; //开始是空的
        bool merged = false; //标示是否已经成功merge
        int size = intervals.size();
        for( int i=0; i<size; i++) {
			//newInterval.start在intervals[i].end之前，就代表需要merge了，
            if(!merged && newInterval.start <= intervals[i].end){
				//update新Interval的起点
                newInterval.start = newInterval.start < intervals[i].start? newInterval.start : intervals[i].start;
				//newInterval.end 在 intervals[i].start之后，则把新interval变大
                if(newInterval.end >= intervals[i].start) {
                    //update新Interval的终点
                    newInterval.end = newInterval.end > intervals[i].end? newInterval.end : intervals[i].end;
                    if(i == size-1) { //如果后面没有interval了
                        merged = true;
                        res.push_back(newInterval);
						break；
                    }
                    continue;
                }
                else { //如果newInterval.end 在 intervals[i].start之前，则插入newInterval，标记为已merge
                    merged = true; //marked as "have merged"
                    res.push_back(newInterval);
                }
            }
            res.push_back(intervals[i]); //对于没有merge的或者在新interval之前的老intervals，都push到res中
        }
        if(!merged) {
            res.push_back(newInterval);
        }
        return res;
    }
};
