
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrue(const vector<int>& arr) {
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    vector<int> concatArrays(const vector<int>& arr1, const vector<int>& arr2) {
        vector<int> concatenated;
        concatenated.reserve(arr1.size() + arr2.size());
        concatenated.insert(concatenated.end(), arr1.begin(), arr1.end());
        concatenated.insert(concatenated.end(), arr2.begin(), arr2.end());
        return concatenated;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                vector<int> subarray(nums.begin() + i, nums.begin() + j + 1);
                vector<int> prefix(nums.begin(), nums.begin() + i);
                vector<int> suffix(nums.begin() + j + 1, nums.end());

                vector<int> concatenated = concatArrays(prefix, suffix);

                if (isTrue(concatenated) && subarray.size() > 0) {
                    result += 1;
                }
            }
        }

        return result;
    }
};

 
