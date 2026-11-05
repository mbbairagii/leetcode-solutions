// 1. If the input is empty → return empty list.
// 2. Sort intervals by their start coordinate (ascending).
// 3. Initialise `merged` with the first interval.
// 4. For each interval `i` from the second onward:
//        let `last = merged.back()`.
//        if i.start > last.end          // no overlap
//             push i onto merged
//        else                           // overlap
//             last.end = max(last.end, i.end)   // extend the current merged interval
// 5. Return `merged`.

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