#include<bits/stdc++.h>
using namespace std;
template<typename T>
class myVector{
    public:
        myVector(){
            cout << "constructor default" << endl;
            arr = new T[10];
            first = arr;
            last = arr;
            endOfArray = arr + 10;
        }
        myVector(int n){
            cout << "constructor with capacity" << endl;
            arr = new T[n];
            first = arr;
            last = arr;
            endOfArray = arr + n;
        }
        myVector(const myVector& vec){
            cout << "constructor copy" << endl;
            int n = vec.size();
            int cap = vec.capacity();
            arr = new T[cap];
            first = arr;
            last = arr + n;
            endOfArray = arr + cap;
            for(int i=0; i<n; i++) *(arr + i) = vec[i];
        }
        myVector(myVector&& vec){
            cout << "constructor move" << endl;
            arr = vec.arr;
            first = vec.first;
            last = vec.last;
            endOfArray = vec.endOfArray;
            // 移动构造，置空原指针
            vec.arr = nullptr;
        }
        ~myVector(){
            delete arr;
        }
        int size() const { return last - first; }
        int capacity() const { return endOfArray - first; }
        void push_back(T value){
            if(size() == capacity()){
                cout << "double the capacity" << endl;
                int newCapacity = 2 * capacity();
                int oldSize = size();
                T* newArr = new T[newCapacity];
                // 这里拷贝注意是T的字节数 * size，直接sizeof(arr)计算不出arr数组的大小，只会得到指针大小(64位8字节)
                memcpy(newArr, arr, sizeof(T) * oldSize);
                delete arr;
                arr = newArr;
                first = arr;
                last = arr + oldSize;
                endOfArray = arr + newCapacity;
            }
            *last++ = value;
        }
        void pop_back(){
            if(size() == 0) return ;
            --last;
        }
        T& operator[](int index) const {
            if(index >= size()) throw "out of range";
            return *(arr + index);
        }
    private:
        T* arr;
        T* first;
        T* last; // 指向最后一个元素之后的地址
        T* endOfArray; // 指向整个数组arr之后的地址
};
int main(){
    myVector<int> v1;
    cout << "initial size: " << v1.size() << ", capacity: " << v1.capacity() << endl;
    v1.push_back(1);
    v1.push_back(2);
    cout << "after push size: " << v1.size() << ", capacity: " << v1.capacity() << endl;
    cout << "v1[0]: " << v1[0] << ", v1[1]: " << v1[1] << endl; 
    v1.pop_back();
    cout << "v1[0]: " << v1[0] << endl; 
    try{
        cout << "after pop v1[1]: " << v1[1] << endl;
    }catch(const char* s){
        cout << s << endl;
    }
    cout << "after pop size: " << v1.size() << ", capacity: " << v1.capacity() << endl;

    myVector<int> v2(20);
    cout << "initial(with parameter) size: " << v2.size() << ", capacity: " << v2.capacity() << endl;

    v2.push_back(1);
    myVector<int> v3(v2);
    cout << "copy construtor size: " << v3.size() << ", capacity: " << v3.capacity() << endl;
    
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(105);
    v3.push_back(144);
    cout << "v3: ";
    for(int i=0; i<v3.size(); i++) cout << v3[i] << " "; cout << endl;

    myVector v4(move(v3));
    cout << "move construtor size: " << v4.size() << ", capacity: " << v4.capacity() << endl;

    cout << "v4: ";
    for(int i=0; i<v4.size(); i++) cout << v4[i] << " "; cout << endl;

    myVector<int> v5(3);
    v5.push_back(5); cout << "add 1 " << endl;
    v5.push_back(5); cout << "add 2 " << endl;
    v5.push_back(5); cout << "add 3 " << endl;
    v5.push_back(5); cout << "add 4 " << endl;

    cout << "v5: ";
    for(int i=0; i<v5.size(); i++) cout << v5[i] << " "; cout << endl;
}