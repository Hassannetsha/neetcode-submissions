class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int x = pq.top(),y;
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x!=y){
                if(x>y){
                    swap(x,y);
                }
                y-=x;
                pq.push(y);
            }
        }
        return pq.empty()?0:pq.top();
    }
};
