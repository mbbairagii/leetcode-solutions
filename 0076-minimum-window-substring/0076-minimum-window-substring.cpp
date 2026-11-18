class Solution {
public:
    string minWindow(string s, string t) {
        //sliding window+2 pointer
        if(s.size()<t.size()){
            return "";
        }
        int n=s.size();
        unordered_map<char, int>mp;
        for(char c: t){
            mp[c]++;
        }

        int left=0;
        int minLen=INT_MAX;
        int start=0;
        int required=t.size();

        for(int right=0;right<n;right++){
            if(mp[s[right]]>0){
                required--;
            }

            mp[s[right]]--;
            while(required==0){
                if(right-left+1 < minLen){
                    minLen=right-left+1;
                    start=left;
                }
                mp[s[left]]++;

                if(mp[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};