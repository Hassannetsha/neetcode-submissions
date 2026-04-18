class Solution {
public:
  int longestConsecutive(vector<int> &nums)
  { 
      set<int>st(nums.begin(),nums.end());
      int mxCnt = 0;
      for(int i =0;i<nums.size();i++){
        // check start
        if(st.contains(nums[i]-1)){
          continue;
        }
        int cnt = 1,num = nums[i] + 1;
        while(st.contains(num)){
          cnt++;
          num++;
        }
        mxCnt = max(mxCnt,cnt);
      }
      return mxCnt;
  }
};
