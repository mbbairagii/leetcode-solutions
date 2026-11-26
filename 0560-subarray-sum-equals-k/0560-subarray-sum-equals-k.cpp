class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //brute force: gen every subarray and calc its sum
        //tc: O(n^2), sc:O(1)

        //optimized approach with o(n): prefix sum with hashmap
        unordered_map<int,int> mp;
        mp[0]=1;

        int prefix=0;
        int count=0;
        for(int num: nums){
            prefix += num;
            int needed=prefix-k;

            if(mp.find(needed)!=mp.end()){
                count += mp[needed];
            }

            mp[prefix]++;
        }

        return count;

    }
};