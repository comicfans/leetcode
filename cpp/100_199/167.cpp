#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i = 0;i<numbers.size();++i){

            int first = numbers[i];
            int expect = target - first;

            auto pos = lower_bound(numbers.begin()+i+1,numbers.end(),expect);
            if(pos == numbers.end()){
                continue;
            }

            if(*pos!= expect){
                continue;
            }

            return vector<int>{int(i+1),(int)(pos- numbers.begin()+1)};

        }

        return vector<int>{0,0};
    }
};
