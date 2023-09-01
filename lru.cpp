#include <list>
#include <map>
#include <utility>
class Solution {
public:
 Solution(int capacity){
 // write code here
    this->capacity = capacity;
 }
 
 int get(int key) {
 // write code here
    if(mp.find(key) == mp.end()) return -1;
    auto iter = mp[key];
    cache.emplace_front(key, iter->second);
    cache.erase(iter);
    mp[key] = cache.begin();
    return mp[key]->second;
 }
 
 void set(int key, int value){
 // write code here
    if(mp.find(key) != mp.end()){
        auto iter = mp[key];
        cache.erase(iter);
        cache.emplace_front(key, value);
        mp[key] = cache.begin();
    }else{
        if(cache.size() >= this->capacity){
            auto iter = --cache.end();
            int old_key = iter->first;
            mp.erase(old_key);
            cache.erase(iter);
        }
        cache.emplace_front(key, value);
        mp[key] = cache.begin();
    }
 }
private:
    int capacity;
    list<pair<int, int>> cache;
    map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */