#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> base = {0,1};

        if(n+1<= base.size()){
            base.resize(n+1);
            return base;
        }

        base.reserve(n+1);
        //                   0
        //                   1
        //               1   0
        //               1   1
        ///          1       0
        //           1       1
        //           1   1   0
        //           1   1   1
        //       1   0   0   0

        int count = 2;
        while(true){

            for(int i =0; i<count && base.size() < n+1;++i){
                base.push_back(base[i]+1);
            }

            if(base.size() == n+1){
                break;
            }

            count *=2;
        }
        return base;
    }
};

int main(){
    Solution s;
    {
        vector<int> expect = {0,1,1};
        auto res = s.countBits(2);
        assert(res == expect);
    }
    {
        vector<int> expect = {0,1,1,2,1,2};
        auto res = s.countBits(5);
        assert(res == expect);
    }
}
