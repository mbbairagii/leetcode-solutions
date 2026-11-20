class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }

        int n=s.size();
        unordered_map<char,int> mp;
        for(char c:t){
            mp[c]++;
        }

        int left=0;
        int minWinLen=INT_MAX;
        int start=0;
        int req=t.size();

        for(int right=0; right<n; right++){
            if(mp[s[right]]>0){
                req--;
            }
            mp[s[right]]--;
            while(req==0){
                if(right-left+1 < minWinLen){
                    minWinLen=right-left+1;
                    start=left;
                }

                mp[s[left]]++;
                if(mp[s[left]]>0){
                    req++;
                }

                left++;
            }
        }

        return minWinLen == INT_MAX ? "" : s.substr(start, minWinLen);
    }
};