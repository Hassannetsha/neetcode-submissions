class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int mx_area = 0;
        st.push({heights[0],0});
        for(int i = 1;i<heights.size();i++){
            int top_idx = st.top().second;
            bool entered = false;
            while(!st.empty() && heights[i]<st.top().first){
                top_idx = st.top().second;
                int temp = st.top().first*(i-top_idx);
                mx_area = max(mx_area, temp);
                st.pop();
                entered = true;
            }
            if (entered)
            {
                st.push({heights[i],top_idx});
            }
            else{
                st.push({heights[i],i});
            }
        }
        int i = heights.size();
        while(!st.empty()){
                int top_idx = st.top().second;
                int temp = st.top().first*(i-top_idx);
                mx_area = max(mx_area, temp);
                st.pop();
            }
        
        return mx_area;
    }
};
