#includestack
class MyQueue {
public
stackint a, b;
    MyQueue() {
    }
    
    void func(){
        if (b.empty()){
            while (!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
    }

    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        func();
        int res = b.top();
        b.pop();
        return res;
    }
    
    int peek() {
        func();
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};