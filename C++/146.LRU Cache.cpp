/*
这一题主要考察对数据结构特性的了解
get函数显然应该以O(1)的复杂度实现，那么只能用unordered_map
而且 这里map里面存的是list的迭代器！！！
get函数要做的事情是：在map里查找key，如果找不到就返回-1；
如果找到了，就把当前访问的节点放到list最前面，返回当前值
set函数需要经常删除、插入，所以需要一个链表，在stl中当然是list了
set函数要做的事情是：
*/
class LRUCache{
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        //假如在map中找到了key: 1.把节点放到链表头, 2.返回value
        else {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return cacheMap[key]->second;
        }
    }
    
    void set(int key, int value) {
        //找到节点，更新list位置和值
        if(cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheList.begin()->second = value;
        }
        //否则，
        else {
            //若cache已满，则删除最后一个节点（List and Map）
            if(cacheList.size() == capacity) {
                int key = cacheList.back().first;
                cacheMap.erase(key);
                cacheList.pop_back();
            }
            //将新节点插入List和Map
            cacheList.push_front(make_pair(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
    
private:
    int capacity;
    list<pair<int,int>> cacheList;
    unordered_map<int, list<pair<int,int>>::iterator> cacheMap;
};
