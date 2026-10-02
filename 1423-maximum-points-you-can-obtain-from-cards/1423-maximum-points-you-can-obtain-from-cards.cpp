class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=total+cardPoints[i];
        }

        int cardsNotTaken=n-k;
        int left=0;
        int windowSum=0;
        for(int i=0;i<cardsNotTaken;i++){
            windowSum=windowSum+cardPoints[i];
        }

        int minWindowSum=windowSum;
        for(int right=cardsNotTaken; right<n; right++){
            windowSum += cardPoints[right];
            windowSum -= cardPoints[left];
            left++;

            minWindowSum=min(minWindowSum, windowSum);
        }

        return total-minWindowSum;
    }
};