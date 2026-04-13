class Solution {
public:
    int sumOfDivisions(vector<int>& nums, int d){
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total += (nums[i] + d-1)/d;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sumOfDivisions(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};