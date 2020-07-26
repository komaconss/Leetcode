class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity){

    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);
        if (iter == cache.end() && kv.size() == cap) {
            eraseKey(lru.back());
        }
        updateLRU(key);
        kv[key] = value;
    }
private:
    void updateLRU(int key) {
        auto iter = cache.find(key);
        if (iter != cache.end()) {
            lru.erase(iter->second);
        }        
        lru.push_front(key);
        cache[key] = lru.begin();
    }

    void eraseKey(int key) {
        lru.pop_back();
        cache.erase(key);
        kv.erase(key);
    }

private:
    int cap;
    list<int> lru;
    unordered_map<int, list<int>::iterator> cache;
    unordered_map<int, int> kv; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
