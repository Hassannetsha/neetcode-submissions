class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> temp;
  for (int i = 0; i < nums.size(); i++)
  {
    temp.emplace_back(nums[i],i);
  }
  sort(temp.begin(), temp.end());
  int i = 0, j = temp.size() - 1, sum = temp[i].first + temp[j].first;
  vector<int> ans;
  while (sum != target)
  {
    if (sum>target)
    {
      sum-=temp[j--].first;
      sum+=temp[j].first;
    }
    else{
      sum-=temp[i++].first;
      sum+=temp[i].first;
    }
  }
  i = temp[i].second;
  j = temp[j].second;
  ans.push_back(i);
  ans.push_back(j);
  sort(ans.begin(), ans.end());
  cout << i << " " << j;
  return ans;
    }
};
