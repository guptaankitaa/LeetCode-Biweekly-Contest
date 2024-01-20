class Solution {
private:
    int g(int i, int j) {
        while (j != 0) {
            int temp = j;
            j = i % j;
            i = temp;
        }
        return i;
    }
    
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n > 2 && nums[0] != nums[1])
            return 1;
        int dn = nums[0];
        for (int i : nums) {
            dn = g(dn, i);
        }
        int count = 0;
        for (int i : nums) {
            if (i == dn)
                count++;
        }
        return max(1, (count + 1) / 2);
  
    }
};
