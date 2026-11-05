class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==0){
            return 0;
        }

        vector<int> left(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
        }

        long long total=0;
        int right=1;
        for(int i=n-1;i>=0;i--){
            if(i<n-1 && ratings[i]>ratings[i+1]){
                right=right+1;
            }
            else{
                right=1;
            }

            total =total+max(left[i], right);
        }

        return total;


    }
};