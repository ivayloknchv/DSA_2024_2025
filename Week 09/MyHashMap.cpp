// https://leetcode.com/problems/design-hashmap/?source=submission-ac

class MyHashMap 
{
    pair<int, bool> data[(int)1e6+1]{}; 
    
public:

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        data[key].first=value;
        data[key].second=true;
    }
    
    int get(int key) {
        if(data[key].second)
        {
            return data[key].first;
        }
        return -1;
    }
    
    void remove(int key) {
        data[key].second=false;
        data[key].first=0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
