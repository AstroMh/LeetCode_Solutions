#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;

        for (int i = 0; i < nums.size(); ++i) {
            int needed_number = target - nums[i];

            if (myMap.find(needed_number) != myMap.end()) {
                return {myMap[needed_number], i};
            }

            myMap[nums[i]] = i;
        }

        return {};
    }
};
