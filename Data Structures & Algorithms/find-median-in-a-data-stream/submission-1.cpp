class MedianFinder {
public:
    priority_queue<double>mx;
    priority_queue<double,vector<double>,greater<double>>mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty()){
            mx.push(num);
        }
        else if(mn.empty()&&num>mx.top()){
            mn.push(num);
        }
        else if(mn.empty()&&num<=mx.top()){
            mn.push(mx.top());
            mx.pop();
            mx.push(num);
        }
        else{
            if(num<mn.top()){
                mx.push(num);
            }
            else{
                mn.push(num);
            }
            if(mn.size()==mx.size()+1){
                mx.push(mn.top());
                mn.pop();
            }
            else if(mx.size()==mn.size()+2){
                mn.push(mx.top());
                mx.pop();
            }
        }
    }
    
    double findMedian() {
        // if(mn.empty()){
        //     return mx.top();
        // }
        // else{
        if(mn.size()==mx.size()){
            return (mx.top() + mn.top())/2.0;
        }
        else{
            return mx.top();
        }
        // }
    }
};
