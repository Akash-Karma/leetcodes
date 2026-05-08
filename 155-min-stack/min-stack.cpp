class MinStack {
    vector<pair<int, int>> arr;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min=getMin();
        if(arr.empty() || min>val){
            min=val;
        }
        arr.push_back({val,min});
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.empty()?-1:arr.back().first;
        
    }
    
    int getMin() {
        return arr.empty()?-1:arr.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */