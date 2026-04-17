class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      set<int> ans(nums.begin(), nums.end());
      return ans.size()!=nums.size();
    }
};