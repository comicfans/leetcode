#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {

        vector<int> ret;

        for(int i =0;i<variables.size();++i){

            if(ok(variables[i],target)){
                ret.push_back(i);
            }
        }

        return ret;
        
    }

    bool ok(const vector<int>& p, int target){

        if(p[3]<=target){
            return false;
        }

        int prevA = 1;
        int thisA = p[0] % 10;
        for(int b=0; b<p[1];++b){
            long long res = prevA * thisA;
            prevA = res % 10;
        }

        int m = 1;
        int m0 = prevA %  p[3];

        for(int c = 0; c<p[2];++c){
            long long  res = m0 * m;
            m = res % p[3];
        }

        return m == target;
    }
};

int main(
){

    Solution s;
    {
        vector<int> test1 = {2,3,3,10};
        assert(s.ok(test1,2));
        vector<int> test2 = {3,3,3,1};
        assert(!s.ok(test2,2));
        vector<int> test3 = {6,1,1,4};
        assert(s.ok(test3,2));
    }
}
