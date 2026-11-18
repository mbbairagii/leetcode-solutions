class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //variable sliding window+ 2 pointer
        int left=0;
        int n=s.size();
        int maxLength=0;

        unordered_set<char>st;

        for(int right=0;right<n;right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);

            maxLength=max(maxLength, right-left+1);
        }

        return maxLength;
    }
};