class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing=0;
        int num=0;
        int i=0;
        while(true){
            num++;
            if(i<arr.size() && arr[i]==num){
                i++;
            }
            else{
                missing++;
                if(missing==k){
                    return num;
                }
            }
        }
    }
};