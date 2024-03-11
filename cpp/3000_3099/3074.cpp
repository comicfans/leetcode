#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int all = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end());

        int i = 0;
        int total = 0;
        for(;i< capacity.size(); ++i){
            total += capacity[capacity.size()-1-i];
            if(total>= all){
                return i+1;
            }
        }

        return capacity.size();
        
    }
};
