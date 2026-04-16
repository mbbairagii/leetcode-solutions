class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int limit){
        int splitCount=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>limit){
                splitCount++;
                sum=nums[i];
            }
            else{
                sum=sum+nums[i];
            }
        }
        return splitCount<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSplit(nums,k,mid)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};