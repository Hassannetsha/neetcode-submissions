class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i].size()>1||isdigit(tokens[i][0])){
                st.push(stoi(tokens[i]));
            }
            else{
                int num = st.top();
                st.pop();
                if(tokens[i]=="+")
                    num=st.top() + num;
                else if(tokens[i]=="-")
                    num = st.top() - num;
                else if(tokens[i]=="*")
                    num=st.top() * num;
                else
                    num=st.top() / num;
                st.pop();
                st.push(num);
            }
        }
        return st.top();
    }
};
