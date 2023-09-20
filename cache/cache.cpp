#include <unordered_map>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
using namespace std;
typedef std::chrono::duration<int> SecondsType;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<Clock> TimePoint;
template <typename T1, typename T2>
class Cache{
    public:
        T2* Get(const T1& key){
            // 未命中
            if(cacheMap.find(key) == cacheMap.end()){
                return nullptr;
            }
            pair<T2, TimePoint>& value = cacheMap[key];
            TimePoint timeout = value.second;
            TimePoint curTime = std::chrono::system_clock::now();
            // 命中-未超时
            if(curTime < timeout) return &(value.first);
            // 命中-超时
            cacheMap.erase(key);
            return nullptr;
        }

        void Set(T1 key, T2 value, SecondsType timeout){
            TimePoint timeoutPoint = std::chrono::system_clock::now() + timeout;
            pair<T2, TimePoint> newData(value, timeoutPoint);
            cacheMap[key] = newData;
        }
    private:
        unordered_map<T1, pair<T2, TimePoint>> cacheMap;
};

int main(){
    Cache<string, int> cache;
    string key = "testKey";
    int* result = cache.Get(key);
    if(result == nullptr) cout << "empty value" << endl;
    else cout << *result << endl;

    SecondsType timeout(1);
    cache.Set(key, 1, timeout);

    result = cache.Get(key);
    if(result == nullptr) cout << "empty value" << endl;
    else cout << *result << endl;
    
    this_thread::sleep_for(SecondsType(3));

    result = cache.Get(key);
    if(result == nullptr) cout << "empty value" << endl;
    else cout << *result << endl;
}

