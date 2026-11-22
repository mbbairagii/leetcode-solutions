// You could use an unordered_set to identify unique elements.
// But LC 26 has an important requirement:
// - Modify the original array in-place.
// - Maintain the relative order of unique elements.
// - Use O(1) extra space.
// An unordered_set requires O(n) extra space, so it violates the space requirement.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }

        return i+1;
    }
};