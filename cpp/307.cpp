#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        
        copy = nums;
    }
    
    void update(int index, int val) {

        int old = copy[index];
        copy[index] = val;

        for(auto &kv: cache){
            if((kv.first.second - index) * (index - kv.first.first)>=0){
                kv.second -= old;
                kv.second += val;
            }
        }
    }
    
    int sumRange(int left, int right) {
        auto pos = cache.find({left,right});

        if(pos!= cache.end()){
            return pos->second;
        }

        int res = accumulate(copy.begin()+left,copy.begin()+right+1,0);

        cache[{left,right}] = res;

        return res;
        
    }
private:
    vector<int> copy;
    map<pair<int,int>,int> cache;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
