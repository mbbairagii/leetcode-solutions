class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int totalsum=0;

        for(int i=0;i<n;i++){
            totalsum=totalsum+cardPoints[i];
        }

        int windowSize=n-k;

        int windowSum=0;

        for(int i=0; i<windowSize;i++){
            windowSum=windowSum+cardPoints[i];
        }

        int minSum=windowSum;

        int left=0;

        for(int right=windowSize; right<n;right++){
            windowSum=windowSum+cardPoints[right];
            windowSum=windowSum-cardPoints[left];
            left++;
            minSum=min(minSum, windowSum);
        }

        return totalsum-minSum;
    }
};