class Solution {
public:
    int lengthOfLongestSubstring(string s)
{
  set<char>st;
  map<char,int>idx;
  int mx = 0,start = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (st.empty()||!st.count(s[i]))
    {
      st.insert(s[i]);
      mx = max(mx,(int)st.size());
      idx[s[i]] = i;
    }
    else{
      auto it = st.find(s[i]);
      if (idx[s[i]]>start)
      {
        st.clear();
        idx.clear();
        start = i;
      }
      else{
        st.erase(it);
      }
      
      st.insert(s[i]);
      mx = max(mx,(int)st.size());
      idx[s[i]] = i;
    }
    
  }
  return mx;
}
};
