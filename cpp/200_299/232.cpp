#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        _stack.push_back(x);
    }
    
    int pop() {
        int front = _stack.front();
        _stack.erase(_stack.begin());
        return front;
    }
    
    int peek() {
        return _stack.front();
    }
    
    bool empty() {
        return _stack.empty();
    }

    vector<int> _stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
