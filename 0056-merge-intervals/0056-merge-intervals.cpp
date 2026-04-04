class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(auto &it: intervals){
            if(result.empty() || it[0] > result.back()[1]){
                result.push_back(it);
            }
            else{
                result.back()[1]=max(it[1],result.back()[1]);
            }
        }
        return result;
    }
};