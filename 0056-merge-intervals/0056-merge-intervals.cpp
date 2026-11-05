class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0){
            return {};
        }

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            vector<int>& last=merged.back();
            vector<int>& curr=intervals[i];

            if(curr[0]>last[1]){
                merged.push_back(curr);
            }
            else{
                last[1]=max(last[1],curr[1]);
            }
        }

        return merged;
    }
};