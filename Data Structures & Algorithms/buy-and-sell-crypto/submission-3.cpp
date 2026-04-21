class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0,l = 0,r =1;
        while(r<prices.size()){
            if(prices[r]<prices[l]){
                l = r;
            }
            else{
                ans= max(ans,prices[r]-prices[l]);
            }
            r++;
        }
        return ans;
    }
};
