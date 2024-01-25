#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> ret = {0};

        int maxValue = 1<<n;


        while(ret.size()< maxValue){

            int prev = ret.back();

            bool found = false;
            for(int i = 0;i<n;++i){
                int shift = 1<<i;
                int tryValue = prev xor shift;

                if(find(ret.begin(),ret.end(),tryValue) == ret.end()){
                    ret.push_back(tryValue);
                    found=true;
                    break;
                }
            }

            assert(found);
        }


        return ret;
        
    }
};

int main(){
    Solution s;
    {
        auto res = s.grayCode(4);
    }
}
