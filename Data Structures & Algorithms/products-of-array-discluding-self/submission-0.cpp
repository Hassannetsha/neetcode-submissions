class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int num = 1;
  bool hasZero = false;
  int ctn = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 0)
    {
      hasZero = true;
      ctn++;
    }
    else
    {
      num *= nums[i];
    }
  }
  vector<int> ans(nums.size());
  for (int i = 0; i < nums.size(); i++)
  {
    if (hasZero && nums[i] == 0 && ctn < 2)
    {
      ans[i] = num;
    }
    else if (ctn >= 2)
    {
      ans[i] = 0;
    }
    else if (hasZero)
    {
      ans[i] = 0;
    }
    else
    {
      ans[i] = num / nums[i];
    }
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return ans;
    }
};
