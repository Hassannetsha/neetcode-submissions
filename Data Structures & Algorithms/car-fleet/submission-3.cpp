class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>vec;
        for(int i = 0;i<position.size();i++){
            vec.emplace_back(position[i],speed[i]);
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        stack<double>st;
        for(int i = 0;i<vec.size();i++){
            double time= (double)(target - vec[i].first)/(double)vec[i].second;
            if(!st.empty()&&st.top()<time||st.empty()){
                st.push(time);
            }
        }
        return st.size();
    }
};
