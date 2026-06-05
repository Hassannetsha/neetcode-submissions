class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int pq_size = nums.size()-k+1;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i = 1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};
