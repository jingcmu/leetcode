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
        else { //假如在map中找到了key: 1.把节点放到链表头, 2.更新map中的记录, 3.返回value
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            return cacheList.front().value;
        }
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()) {    //没有找到节点: 1.插入节点并更新list和map, 2.要检查是否已满
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
    unordered_map<int, list<CacheNode>::iterator> cacheMap;  
};