class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        map<int,deque<char>>mp;
        unordered_map<char,int>cnt;
        for(int i = 0;i<t.size();i++){
            cnt[t[i]]++;
        }
        int l = 0,r = 0,cntCh = 0,mnSize = s.size()+1;
        unordered_set<char>st(t.begin(),t.end());
        deque<char> temp;
        while(r<s.size()){
            while(cntCh<st.size()&&r<s.size()){
                if(cnt.find(s[r])!=cnt.end()){
                    cnt[s[r]]--;
                    if(cnt[s[r]]==0){
                        cntCh++;
                    }
                }
                temp.push_back(s[r]);
                r++;
            }
            if(cntCh==st.size()){
                mnSize = min(mnSize,r-l);
                mp[r-l] = temp;
            }
            while(cntCh==st.size()){
                if(cnt.find(s[l])!=cnt.end()){
                    cnt[s[l]]++;
                    if(cnt[s[l]]==1){
                        cntCh--;
                    }
                }
                temp.pop_front();
                if(cntCh==st.size()){
                    mnSize = min(mnSize,r-l);
                    mp[r-l] = temp;
                }
                l++;
            }
        }
        if(mnSize==s.size()+1)
        {
            return "";
        }
        string ans;
        temp = mp[mnSize];
        for(auto& it:temp){
            ans.push_back(it);
        }
        return ans;
    }
};
