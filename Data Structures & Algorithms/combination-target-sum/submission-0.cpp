class Solution {
public:
    vector<vector<int>>res;
    void f(vector<int>& nums,int target,int sum,int i,vector<int>vec){
        if(sum==target){
            res.push_back(vec);
            return;
        }
        if(sum>target||i>=nums.size()){
            return;
        }
        vec.push_back(nums[i]);
        f(nums,target,sum+nums[i],i,vec);
        vec.pop_back();
        f(nums,target,sum,i+1,vec);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        f(nums,target,0,0,vector<int>());
        return res;
    }
};
