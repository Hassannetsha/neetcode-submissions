class Solution {
    bool knowBit(int& num,int& bit){
        return (num>>bit)&1;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int i = 0;i<(1<<nums.size());i++){
            vector<int>temp;
            for(int j = 0;j<nums.size();j++){
                if(knowBit(i,j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
