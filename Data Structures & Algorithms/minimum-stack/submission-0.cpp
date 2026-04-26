class MinStack {
public:
    stack<int>st;
    vector<int>vec;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!vec.empty()){
            vec.push_back(min(vec.back(),val));
        }
        else{
            vec.push_back(val);
        }
    }
    
    void pop() {
        st.pop();
        vec.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return vec.back();
    }
};
