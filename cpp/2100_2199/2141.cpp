#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        


        long long ret = 0;

        while(true){

            sort(batteries.begin(),batteries.end());

            auto nonZero = upper_bound(batteries.begin(),batteries.end(),0);

            auto nonZeroSize = batteries.end () - nonZero;

            if(nonZeroSize < n){
                return ret;
            }

            //from nonZero up to n, consume firstelement-1

            //at least consume 1
            //
            //
            int runtime = max(1, *(batteries.end() - n ) - 1);
            ret+= runtime;

            for(int i=0;i<n;++i){
                *(batteries.end() - n+i) -= runtime;
            }
        }
        
        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> b= {3,3,3};
        assert(s.maxRunTime(2,b) == 4);
    }
    {
        vector<int> b= {1,1,1,1};
        assert(s.maxRunTime(2,b) == 2);
    }
}
