class Solution {
public:
    int reverse(int x) {
        int revNumber = 0;
        while(x!=0){
            int digit = x % 10;
            x = x/10;
            if(revNumber > INT_MAX/10 || revNumber<INT_MIN/10){
                return 0;
            }
            revNumber=(revNumber*10)+digit;
        }
        return revNumber;
    }
};