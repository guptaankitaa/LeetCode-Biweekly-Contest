class Solution {
public:
   
        bool canSortArray(vector<int>& nums) {
        vector<int> count(101);
        int j = 0, n = nums.size(), k = 0;
        for (int i : nums) {
            count[j++] = setbits(i);
        }
        while (k < nums.size()) {
            for (int i = 1; i < n; i++) {
                if (count[i] == count[i - 1] && nums[i] < nums[i - 1]) {
                    int temp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                }
            }
            if (check(nums))
                return true;
            k++;
        }
        return false;
    }
    
    bool check(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
    
    int setbits(int num) {
        int c = 0;
        for (int i = 31; i >= 0; i--) {
            if (((num >> i) & 1) == 1)
                c++;
        }
        return c;
    
    }
};
