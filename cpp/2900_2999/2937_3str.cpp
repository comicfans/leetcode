#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {

        int minSize = min(s1.size(),min(s2.size(),s3.size()));

        int idx = 0;
        for(; idx <minSize;++idx){
            if((s1[idx] != s2[idx]) || (s2[idx] != s3[idx])){
                break;
            }
        }
        int allLength=s1.size() + s2.size() + s3.size();
        return idx == 0? -1: allLength  - idx * 3;
        
    }
};

int main(){
    Solution s;
    {
        assert(s.findMinimumOperations("abc","abb","ab") == 2);
    }

    {
        assert(s.findMinimumOperations("dac","bac","cac") == -1);
    }
}
