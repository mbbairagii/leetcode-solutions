class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minProd=nums[0];
        int maxProd=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int tempMin=minProd;
            int tempMax=maxProd;
            maxProd=max({curr,tempMax*curr, tempMin*curr});
            minProd=min({curr,tempMax*curr, tempMin*curr});

            ans=max(ans, maxProd);
        }
        return ans;
    }
};