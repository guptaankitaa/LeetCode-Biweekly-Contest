class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        // Create two sets to store the elements of each array.
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        // Initialize two variables to c the intersections.
        int c1 = 0, c2 = 0;
        
        // Iterate through each element in nums1.
        for (int num : nums1) {
            // If the element exists in set2, increment count1.
            if (set2.find(num) != set2.end()) {
                c1++;
            }
        }
        
        // Iterate through each element in nums2.
        for (int num : nums2) {
            // If the element exists in set1, increment count2.
            if (set1.find(num) != set1.end()) {
                c2++;
            }
        }
        
        // Return an array containing the two c.
        return {c1, c2};
    }
};
