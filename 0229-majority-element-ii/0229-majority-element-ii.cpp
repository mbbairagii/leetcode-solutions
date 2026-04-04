class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0;
        int c2=0;
        int candidate1=0;
        int candidate2=1;
        for(int num: nums){
            if(num==candidate1) c1++;
            else if(num==candidate2) c2++;
            else if(c1==0){
                candidate1=num;
                c1=1;
            }
            else if(c2==0){
                candidate2=num;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }

        }

        c1=0;
        c2=0;
        for(int num: nums){
            if(num==candidate1) c1++;
            else if(num==candidate2) c2++;
        }

        vector<int> result;
        if(c1>n/3) result.push_back(candidate1);
        if(c2>n/3) result.push_back(candidate2);
        return result;
    }
};