class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int changesUsingPattern1=0;
        int changesUsingPattern2=0;
        for(int i=0;i<n;i++){

            char expected1=(i%2==0)? '0':'1';
            char expected2=(i%2==0)? '1' : '0';

            if(s[i]!= expected1){
                changesUsingPattern1++;
            }

            if(s[i]!= expected2){
                changesUsingPattern2++;
            }
        }

        return min(changesUsingPattern1, changesUsingPattern2);
    }
};