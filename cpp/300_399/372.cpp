#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int superPow(int a, vector<int>& b) {

            a%=1337;

            int base = a;
            int ret = 1;
            for(int i = 0; i < b.size(); ++i){
                if(base == 0){
                    return 0;
                }
                

                int thisMode = 1;
                int pw = b[b.size()-1-i];
                if(base != 1){
                    for(int j = 0; j<pw; ++j ){
                        thisMode *= base;
                        thisMode %= 1337;
                        if(thisMode == 0){
                            return 0;
                        }
                    }
                }
                

                ret = (ret * thisMode) % 1337;

                for(int j = 0; j < 10 - pw && i!= b.size()-1; ++j){
                    thisMode *= base;
                    thisMode %= 1337;
                }

                base = thisMode;
            }

            return ret;
            
        }
};

int main(){
    Solution s;
    
    {
        int a  = 3; vector<int> b = {1,0};
        int res = s.superPow(a,b);
        assert(res == 221);
    }
    {
        int a = 2147483647;vector<int> b= {1,0};
        int res = s.superPow(a,b);
        assert(res == 1198);
    }
    {
        int a = 2147483647;vector<int> b= {2};
        int res = s.superPow(a,b);
        assert(res == 911);
    }
    {
        int a = 2147483647;vector<int> b= {2,0};
        int res = s.superPow(a,b);
        assert(res == 603);
    }
    {
        int a = 2147483647;vector<int> b= {2,0,0};
        int res = s.superPow(a,b);
        assert(res == 1198);
    }
    {
        int a  = 2; vector<int> b = {3};
        int expect =  8;
        int res = s.superPow(a,b);
        assert(res==expect);
    }
    {
        int a  = 2; vector<int> b = {1,0};
        int expect =  1024;
        assert(s.superPow(a,b)==expect);
    }
    {
        int a  = 1; vector<int> b = {4,3,3,8,5,2};
        int expect =  1;
        assert(s.superPow(a,b)==expect);
    }
}
