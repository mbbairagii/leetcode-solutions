class Solution {
public:
    bool canMake(vector<int>& bloomDay, int day, int m, int k){
        int n=bloomDay.size();
        int bouquets=0;
        int consecutive=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day) consecutive++;
            else{
                bouquets += consecutive/k;
                consecutive=0;
            }
        }
        bouquets += consecutive/k;
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canMake(bloomDay,mid,m,k)){
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