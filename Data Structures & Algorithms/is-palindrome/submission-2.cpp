class Solution {
public:
    bool isPalindrome(string s) {
        int l{},r=s.length()-1;
        while(l<=r){
            while(!isalnum(tolower(s[l]))) l++;
            while(!isalnum(tolower(s[r]))) r--;
            if(l>r) break;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++,r--;
        }
        return true;
    }
};