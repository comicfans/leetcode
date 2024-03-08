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

            if(a==0){
                return 0;
            }
            if(a==1){
            return 1;
        }

            int mod = 1;
            for(int i = 0; i < b.size(); ++i){

                int thisMode = 1;
                int pw = b[b.size()-1-i];
                for(int j = 0; j<pw; ++j ){
                    thisMode *= a;
                    thisMode %= 1337;
                    if(thisMode == 0){
                        break;
                    }
                }

                if(thisMode == 0){
                    return 0;
                }

                if(thisMode == 1){
                    continue;
                }

                for(int j =0; j < i; ++j){
                    int mul = thisMode;
                    for(int k = 1; k<10;++k){
                        thisMode = (thisMode * mul) % 1337;
                    }
                }

                mod = (mod * thisMode) % 1337;
            }

            return mod;
            
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
