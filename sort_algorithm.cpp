#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        // selectSort(arr);
        // mergeSort(arr, 0, arr.size()-1);
        // quickSort(arr, 0, arr.size()-1);
        heapSort(arr);
        return arr;
    }

    // 选择，归并，快排，堆排

    void selectSort(vector<int>& arr){
        int sorted = 0;
        for(; sorted < arr.size(); sorted++){
            int minV = arr[sorted];
            int minId = sorted;
            for(int i=sorted+1; i<arr.size(); i++){
                if(arr[i] < minV){
                    minId = i;
                    minV = arr[i];
                }
            }
            swap(arr[sorted], arr[minId]);
        }
    }

    void mergeSort(vector<int>& arr, int start, int end){
        if(start >= end) return ;
        int mid = start + ((end-start) >> 1);
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        vector<int> temp;
        int left = start;
        int right = mid + 1;
        while(left <= mid && right <= end){
            if(arr[left] < arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid) temp.push_back(arr[left++]);
        while(right <= end) temp.push_back(arr[right++]);
        for(auto i = start; i <= end; i++){
            arr[i] = temp[i-start];
        }
    }

    void quickSort(vector<int>& arr, int start, int end){
        if(start >= end) return ;
        int key = partition(arr, start, end);
        quickSort(arr, start, key-1);
        quickSort(arr, key+1, end);
    }

    int partition(vector<int>& arr, int start, int end){
        int pivot = arr[end];
        int i = start;
        for(int j=start; j<end; j++){
            if(arr[j] < pivot){
                swap(arr[i++], arr[j]);
            }
        }
        swap(arr[i], arr[end]);
        return i;
    }

    void heapSort(vector<int>& arr){
        int n = arr.size();
        // 建堆
        for(int i=n/2-1; i>=0; i--){
            maxHeapify(arr, n, i);
        }
        // 排序
        for(int i=n-1; i>0; i--){
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
    void maxHeapify(vector<int>& arr, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }
};