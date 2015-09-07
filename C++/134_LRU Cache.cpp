class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        this->capacity = capacity;
        lt.clear();
        mp.clear();
    }

    // @return an integer
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        auto i = mp[key];
        node n = *i;
        lt.erase(i);
        lt.push_front(n);
        mp[key] = lt.begin();
        return n.value;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (lt.size() == capacity) {
                node n = lt.back();
                mp.erase(n.key);
                lt.pop_back();
            }
        } else {
            auto i = mp[key];
            lt.erase(i);
        }
        lt.push_front(node(key, value));
        mp[key] = lt.begin();
    }

private:
    struct node {
        int key, value;
        node(int k, int v): key(k), value(v) {}
    };
    int capacity;
    list<node> lt;
    map<int, list<node>::iterator> mp;
};