class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int midRow=low+(high-low)/2;
            int maxCol=max_element(mat[midRow].begin(),mat[midRow].end())-mat[midRow].begin();
            if(mat[midRow][maxCol]>mat[midRow+1][maxCol]){
                high=midRow;
            }
            else{
                low=midRow+1;
            }
        }
        int peakCol=max_element(mat[low].begin(), mat[low].end())-mat[low].begin();
        return{low, peakCol};
    }
};