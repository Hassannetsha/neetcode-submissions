class Solution {
public:
    int maxProfit(vector<int> &prices)
{
  int mn = prices[0],idx_mn = 0, idx_mx = prices.size() - 1;
  int ans = 0;
  for (int i = 0; i < prices.size(); i++)
  {
    if (prices[i] < mn)
    {
      mn = prices[i];
      idx_mn = i;
    }

    if (idx_mn <= idx_mx)
    {
      ans = max(prices[i] - mn, ans);
    }
  }
  return ans;
}
};
