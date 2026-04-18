class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> arr(2002,0);
        set<pair<int,int>,greater<>>st;
        for(int i = 0;i<nums.size();i++){
          arr[nums[i]+1000]+=1;  
        }
        for(int i = 0;i<nums.size();i++){
          st.insert(make_pair(arr[nums[i]+1000],nums[i]));
        }
        vector<int>ans;
        for(auto it:st){
          ans.push_back(it.second);
          k--;
          if(k==0)
            break;
        }
        return ans;
    }
};
