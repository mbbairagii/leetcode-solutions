class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=0;
        for(int w: weights){
            high += w;
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShip(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    bool canShip(vector<int>& weights, int capacity, int days){
        int daysNeeded=1;
        int currLoad=0;
        for(int i=0;i<weights.size();i++){
            if(currLoad+weights[i]<=capacity){
                currLoad += weights[i];
            }
            else{
                daysNeeded++;
                currLoad=weights[i];
            }
        }
        return daysNeeded<=days;
    }
};