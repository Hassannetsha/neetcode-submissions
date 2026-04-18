class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>num;
        for(int i = 0;i<nums.size();i++){
          num.emplace_back(nums[i],i);
        }
        sort(num.begin(),num.end());
    int i = 0,j = num.size()-1,sum = num[i].first+num[j].first;
    while (i<j)
    {
      if (sum==target)
      {
        vector<int>ans = {num[i].second,num[j].second};
        sort(ans.begin(),ans.end());
        return ans;
      }
      else if(sum>target){
        sum-=num[j--].first;
        sum+=num[j].first;
      }
      else{
        sum-=num[i++].first;
        sum+=num[i].first;
      }
      
    }
    }
};
