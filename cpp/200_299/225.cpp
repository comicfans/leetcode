#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class MyStack {
public:

    vector<int> impl;
    MyStack() {
        
    }
    
    void push(int x) {
        impl.push_back(x);
    }
    
    int pop() {
        int res = impl.back();
        impl.pop_back();
        return res;
    }
    
    int top() {
        return impl.back();
        
    }
    
    bool empty() {
        return impl.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
