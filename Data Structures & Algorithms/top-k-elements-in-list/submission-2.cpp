class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
  multimap<int, int, greater<int>> ctn;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
    mp[nums[i]]++;
  }

  for (auto it : mp)
  {
    ctn.insert(make_pair(it.second,it.first));
  }
  auto it = ctn.begin();
  while (ans.size() < k)
  {
    ans.push_back(it->second);
    cout << it->second << " ";
    it++;
  }

  return ans;
    }
};
