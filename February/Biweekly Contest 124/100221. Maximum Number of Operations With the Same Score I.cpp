class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int count=1, sum=nums[0]+nums[1];
        for(int i=2;i<nums.size()-1;){
            if(nums[i]+nums[i+1]==sum){
                count++;
                i+=2;
            }
            else break;
        }
        return count;
    }
};
