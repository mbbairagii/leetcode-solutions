class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //brute approach with tc:o(n^2), sc:o(1)
        //for evry index, calc sum of ele on the left nd on the right nand comapre

        //optimized sol: prefix sum
        //totalsum=leftsum+pivot sum +right sum
        //so, leftsum=totalsum-rightsum-nums[i]
        //rightsum=totalsum-leftsum-nums[i]
        int totalSum=0;
        for(int num: nums){
            totalSum=totalSum+num;
        }

        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            int rightSum=totalSum-leftSum-nums[i];

            if(leftSum==rightSum){
                return i;
            }

            leftSum = leftSum+nums[i];
        }

        return -1;
    }
};