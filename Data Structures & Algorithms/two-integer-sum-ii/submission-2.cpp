class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
{
  sort(numbers.begin(), numbers.end());
  int l = 0, r = numbers.size() - 1, sum = numbers[l] + numbers[r];
  vector<int> ans;
  while (l < r)
  {
    if (sum < target)
    {
      sum -= numbers[l++];
      sum += numbers[l];
    }
    else if (sum > target)
    {
      sum -= numbers[r--];
      sum += numbers[r];
    }
    else
    {
      ans.push_back(l + 1);
      ans.push_back(r + 1);
      return ans;
    }
  }

  return ans;
}
};
