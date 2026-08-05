class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char, int> lastseen;
        int left=0;
        int ans=0;

        for(int right=0; right<n; right++){
            char c=s[right];
            if(lastseen.count(c) && lastseen[c]>=left){
                left=lastseen[c]+1;
            }

            lastseen[c]=right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};