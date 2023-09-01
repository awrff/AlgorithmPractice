#include <algorithm>
#include <utility>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     // write code here
    //     vector<pair<int, int>> index_numbers;
    //     for (auto i = 0; i < numbers.size(); i++) {
    //         index_numbers.emplace_back(i + 1, numbers[i]);
    //     }
    //     typedef pair<int, int> p;
    //     sort(index_numbers.begin(), index_numbers.end(), [](p a, p b) {
    //         return a.second < b.second;
    //     });
    //     int i = 0;
    //     int j = numbers.size() - 1;
    //     while (index_numbers[i].second + index_numbers[j].second != target) {
    //         if (index_numbers[i].second + index_numbers[j].second > target) {
    //             --j;
    //         } else {
    //             ++i;
    //         }
    //     }
    //     vector<int> result{index_numbers[i].first, index_numbers[j].first};
    //     sort(result.begin(), result.end());
    //     return result;
    // }
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int, int> mp;
        for (auto i = 0; i < numbers.size(); i++) {
            if (mp.find(target - numbers[i]) != mp.end()) {
                return {mp[target - numbers[i]], i + 1};
            }
            mp[numbers[i]] = i + 1;
        }
        return {};
    }
};