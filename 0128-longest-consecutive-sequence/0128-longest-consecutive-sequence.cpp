class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest=0;
        for(int num: nums){
            if(st.find(num-1)==st.end()){
                int count=1;
                while(st.count(num+count)){
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};