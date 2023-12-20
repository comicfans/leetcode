#include <vector>
#include <functional>
#include <cassert>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class FooBar {
private:
    int n;
    std::mutex mtx;

public:
    FooBar(int n) {
        this->n = n;
        
    }
    
    condition_variable cond;
    bool shouldFoo = true;

    condition_variable cond2;

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
             {
                unique_lock<mutex> lock(mtx);
                cond.wait(lock,[this](){return this->shouldFoo;});
            }

        	    printFoo();
            unique_lock<mutex> lockAgain(mtx);
                shouldFoo = false;
                cond2.notify_one();
             }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.       
        {
            std::unique_lock<mutex> lock(mtx);
            cond2.wait(lock,[this](){
                return !this->shouldFoo;
            });
}
        	printBar();
            
            std::unique_lock<mutex> lock2(mtx);
            shouldFoo = true;
            cond.notify_one();
            
        }
    }
};

int main(){

    FooBar i(300);

    std::thread t0([&](){
        i.foo([](){
            printf("foo");
        });
    });

    std::thread t1([&](){
        i.bar([](){
            printf("bar");
        });
    });

    t0.join();
    t1.join();

}
