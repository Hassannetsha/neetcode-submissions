class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l =0 ,r = 0;
        map<int,int>mp;
        vector<int>ans;
        while(r<nums.size()){
            while(r-l<k){
                mp[nums[r]]++;
                r++;
            }
            auto it = mp.rbegin();
            ans.push_back(it->first);
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
        }
        return ans;
    }
};
