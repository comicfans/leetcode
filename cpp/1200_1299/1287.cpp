#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {


        int minNumber = (arr.size() + 4)/ 4;

        for(int sample = 0;sample < arr.size(); sample+= minNumber){

            int thisValue = arr[sample];

            auto range = equal_range(arr.begin(),arr.end(),thisValue);

            if(range.second - range.first >= minNumber){
                return thisValue;
            }

        }
        assert(false);
        
    }
};
