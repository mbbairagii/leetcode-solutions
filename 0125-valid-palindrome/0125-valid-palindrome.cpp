class Solution {
public:
    bool helper(string &s, int i, int j) {
        if (i >= j) return true;

        if (!isalnum(s[i])) return helper(s, i+1, j);
        if (!isalnum(s[j])) return helper(s, i, j-1);

        if (tolower(s[i]) != tolower(s[j])) return false;

        return helper(s, i+1, j-1);
    }

    bool isPalindrome(string s) {
        return helper(s, 0, s.size()-1);
    }
};
