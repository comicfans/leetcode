#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret(encoded.size()+1);
        ret[0]=first;

        for(int i= 0;i<encoded.size();++i){
            ret[i+1]=ret[i] xor encoded[i];
        }
        return ret;
    }
};
