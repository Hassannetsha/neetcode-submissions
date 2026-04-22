class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int l = 0,r= 0;
        unordered_map<char,int>mp;
        while(r<s.size()){
            if(mp[s[r]]==1){
                mx = max(mx,r-l);
                while(mp[s[r]]==1){
                    mp[s[l++]]--;
                }
            }
            mp[s[r]]++;
            r++;
        }
        mx = max(mx,r-l);
        return mx;
    }
};
