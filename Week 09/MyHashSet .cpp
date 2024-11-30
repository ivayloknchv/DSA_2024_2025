// https://leetcode.com/problems/design-hashset/description/?envType=problem-list-v2&envId=hash-table
class MyHashSet 
{
    vector<bool> nums;
public:
    MyHashSet() 
    {
        nums=vector<bool>(1e6+1);    
    }
    
    void add(int key) 
    {
        nums[key]=true;    
    }
    
    void remove(int key) 
    {
        nums[key]=false;    
    }
    
    bool contains(int key) 
    {
        return nums[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
