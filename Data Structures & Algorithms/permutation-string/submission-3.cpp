class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        int l = 0,r = 0;
        for(int i= 0;i<s1.size();++i){
            mp[s1[i]]++;
        }
        unordered_set<char>st(s1.begin(),s1.end());
        while(r<s2.size()){
            while(r<l+s1.size()){
                mp[s2[r]]--;
                r++;
            }
            int cnt = 0;
            for(auto& it:st){
                if(mp[it]==0){
                    cnt++;
                }
            }
            if(cnt==st.size())
                return true;
            mp[s2[l]]++;
            l++;
        }
        return false;
    }
};
