/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
先对interval排序（利用sort，需提供一个compare函数），然后不断逐个插入
*/
class Solution {
public:
    static bool compare1 (const Interval &a, const Interval &b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int size = intervals.size();
        vector<Interval> res;
        //res.clear();
        if(size == 0) {
            return res;
        }
		//对interval排序
        sort(intervals.begin(), intervals.end(), compare1);
        res.push_back(intervals[0]);
        for(int i=1; i<size; i++) {
            int temp_size = res.size() - 1;
            if(res[temp_size].end >= intervals[i].start) { //如果有重叠
				//合并interval
                res[temp_size].end = max(res[temp_size].end:intervals[i].end);
            }
            else{ //如果没有重叠，加入一个新的interval
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};