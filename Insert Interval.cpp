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
        vector<Interval> res;
        bool merged = false;
        int size = intervals.size();
        for( int i=0; i<size; i++){
            if(!merged && newInterval.start <= intervals[i].end){
                newInterval.start = newInterval.start < intervals[i].start? newInterval.start : intervals[i].start;
                if(newInterval.end >= intervals[i].start){
                    //merge newInterval with intervals[i]
                    newInterval.end = newInterval.end > intervals[i].end? newInterval.end : intervals[i].end;
                    if(i == size-1){
                        merged = true;
                        res.push_back(newInterval);
                    }
                    continue;
                }
                else{
                    merged = true; //marked as "have merged"
                    res.push_back(newInterval);
                }
            }
            res.push_back(intervals[i]);
        }
        if(!merged){
            res.push_back(newInterval);
        }
        return res;
    }
};
