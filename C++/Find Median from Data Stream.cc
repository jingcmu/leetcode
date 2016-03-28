class MedianFinder {
public:

    // Adds a number into the data structure.
    // 先push到small里面，然后再把small里面最大的放到large里
    // large里面存的是相反数，这样就可以用最大堆了
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size() > large.size() ? small.top() : 0.5 *(small.top() - large.top());
    }

private:
    // 默认是最大堆
    priority_queue<long> small, large;
};
