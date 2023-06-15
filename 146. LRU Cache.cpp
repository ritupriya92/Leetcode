class LRUCache {
public:
    map<int, int> m;
    list<int> listofkeys;
    map<int, list<int>::iterator> address;
    int cap, size;
    LRUCache(int capacity) {
        cap= capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        listofkeys.erase(address[key]);
        address.erase(key);
        listofkeys.push_front(key);
        address[key] = listofkeys.begin();
        return m[key];

    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            listofkeys.erase(address[key]);
            address.erase(key);
            m.erase(key);
            size--;
        }
        if(size == cap)
        {
            int todelete =listofkeys.back();
            listofkeys.pop_back();
            address.erase(todelete);
            m.erase(todelete);
            size--;
        }
        listofkeys.push_front(key);
        address[key] = listofkeys.begin();
        m[key] = value;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
