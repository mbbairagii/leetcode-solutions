class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>n/3){
                bool alreadypresentinresult=false;
                for(int x:result){
                    if(x==nums[i]){
                        alreadypresentinresult=true;
                        break;
                    }
                }
                if(!alreadypresentinresult){
                    result.push_back(nums[i]);
                }
            }
        }
        return result;
    }
};