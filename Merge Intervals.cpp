/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
using namespace std;

class Solution {
public:
    static bool compare1 (const Interval &a, const Interval &b) {
        return a.start < b.start;   
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int size = intervals.size();
        vector<Interval> res;
        //res.clear();
        if(size == 0){
            return res;
        }
        sort(intervals.begin(), intervals.end(), compare1);
        res.push_back(intervals[0]);
        for(int i=1; i<size; i++){
            int temp_size = res.size() - 1;
            if(res[temp_size].end >= intervals[i].start){
                res[temp_size].end = res[temp_size].end>intervals[i].end? res[temp_size].end:intervals[i].end;
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};