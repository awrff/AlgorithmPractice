#include<bits/stdc++.h>
using namespace std;
#define SIZE 10007


class myHashTable{
    private:
        list<pair<int, string> > table[SIZE];
    public:
        int _hash(int key){
            return key % SIZE;
        }

        void _insert(int key, string val){
            int hash_v = _hash(key);
            bool key_exsits = false;
            for(auto p : table[hash_v]){
                if(p.first == key){
                    p.second = val;
                    key_exsits = true;
                }
            }
            if(!key_exsits) table[hash_v].emplace_back(key, val);
        }

        string _find(int key){
            int hash_v = _hash(key);
            for(auto item: table[hash_v]){
                if(item.first == key) return item.second;
            }
            return "";
        }

        void _delete(int key){
            int hash_v = _hash(key);
            for(auto item = table[hash_v].begin(); item!=table[hash_v].end(); item++){
                if(item->first == key){
                    table[hash_v].erase(item);
                    break;
                }
            }
        }
};

int main(){
    myHashTable ht;
    ht._insert(1, "hello");
    ht._insert(2, "world");

    cout << ht._find(1) << endl;
    cout << ht._find(2) << endl;

    ht._delete(2);
    cout << ht._find(2) << endl;
    return 0;
}