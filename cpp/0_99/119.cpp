#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret = {1};

        for(int i = 1; i < rowIndex; ++i){
            vector<int> thisRow = ret;
            
            thisRow.push_back(1);
            for(int j = 1;j<i;++j){
                thisRow[j] = ret[j-1] + thisRow[j];
            }
            swap(ret,thisRow);
        }
        return ret;
       
    }
};
