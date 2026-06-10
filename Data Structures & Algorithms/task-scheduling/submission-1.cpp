class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto& it:tasks){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.emplace(it.second,it.first);
        }
        mp.clear();
        int cpuCycles = 0;
        int i = 0;
        queue<pair<pair<int,int>,char>>q;

        while(!pq.empty()||!q.empty()){
            if(pq.empty())
            {
                auto it = q.front();
                pq.emplace(it.first.first,it.second);
                q.pop();
                cpuCycles+=max(0,(n-(i-it.first.second-1)));
                i+=max(0,(n-(i-it.first.second-1)));
            }
            if(!q.empty()){
                auto it = q.front();
                if(i-it.first.second>n){
                    pq.emplace(it.first.first,it.second);
                    q.pop();
                }
            }
            pair<int,char>p = pq.top();
            pq.pop();
            pair<int,int>temp = {p.first-1,i};
            if(temp.first>0)
                q.emplace(temp,p.second);
            cpuCycles++;
            i++;
        }
        return cpuCycles;
    }
};
