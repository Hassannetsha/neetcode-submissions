class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for(auto it:piles){
            mx = max(it,mx);
        }
        int l = 1,r = mx;
        
        while(l<r){
            int sum = 0;
            int mid = (l+r)/2;
            for(auto it:piles){
                sum+=ceil((double)it/(double)mid);
            }
            if(sum<=h){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return r;
    }
};
