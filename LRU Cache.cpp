/*
这一题主要考察对数据结构特性的了解
get函数显然应该以O(1)的复杂度实现，那么只能用unordered_map
而且 这里map里面存的是list的迭代器！！！
get函数要做的事情是：在map里查找key，如果找不到就返回-1；
如果找到了，就把当前访问的节点放到list最前面，返回当前值
set函数需要经常删除、插入，所以需要一个链表，在stl中当然是list了
set函数要做的事情是：
*/
struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v): key(k), value(v) {}
};

class LRUCache{
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){ //cacheMap[key] == 0
            return -1;
        }
		//假如在map中找到了key: 1.把节点放到链表头, 2.更新map中的记录, 3.返回value
        else { 
			//把cacheList的cacheMap[key]位置的点插入到cacheList.begin()
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); 
            cacheMap[key] = cacheList.begin();//更新map中的记录
            return cacheList.front().value; //返回value
        }
    }
    
    void set(int key, int value) {
		//没有找到节点: 1.插入节点并更新list和map, 2.要检查是否已满
        if(cacheMap.find(key) == cacheMap.end()) {    
            if(cacheList.size() == capacity){ //已满, 删除末尾的节点
                cacheMap.erase(cacheList.back().key); //map要先调整
                cacheList.pop_back();   
            }
            //新节点插到头部, 调整map
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin(); //更新节点位置
        }
        else{   //找到节点的话, 只需要把节点调整到头部, 更新map
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin(); //更新map
            cacheMap[key]->value = value;   //更新value
        }
    }
private:
    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;  //map里面存的是<key, 节点位置(迭代器)>
};