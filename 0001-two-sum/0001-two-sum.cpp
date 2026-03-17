class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int first=nums[i];
            for(int j=i+1;j<n;j++){
                sum=first+nums[j];
                if(sum==target){
                    return vector<int> {i,j};
                }
            }
        }
        return {};
    }
};