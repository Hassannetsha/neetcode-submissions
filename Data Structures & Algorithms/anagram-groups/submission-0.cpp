class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
  for (int i = 0; i < strs.size(); i++)
  {
    string temp = strs[i];
    sort(temp.begin(),temp.end());
    mp[temp].push_back(strs[i]);
  }
  vector<vector<string>>vec;
  for (auto it:mp)
  {
    cout<<it.first<<":\n";
    for (size_t i = 0; i < it.second.size(); i++)
    {
      cout<<it.second[i]<<" ";
    }
    cout<<'\n';
    vec.push_back(it.second);
  }
  return vec;
    }
};
