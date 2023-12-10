#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> mul(n+1);

        mul[0] = 0;
        mul[1] = 1;

        for(int i = 2;i<=n;++i){
            mul[i] = mul[i-1] * i;
        }

        vector<int> number;
        for(int i =1;i<=n;++i){
            number.push_back(i);
        }


        string ret;
        while(k>1){
            //find which pos this k alive
            auto pos = lower_bound(mul.begin(),mul.end(), k);

            --pos;

            auto digitsIdx = k / (*pos) ;

            ret.push_back(number[digitsIdx] + '0');

            number.erase(number.begin()+digitsIdx);

            k = k % *pos;
        }

        if(k == 1){
            for(auto n:number){
                ret.push_back(n+'0');
            }
        }else{
            for(auto r = number.rbegin();r<number.rend();++r){
                ret.push_back(*r+'0');
            }
        }

        


        return ret;
    }
};

int main(){
    Solution s;
    {
        auto res = s.getPermutation(3,2);
        assert(res == "132");
    }
    {
        auto res = s.getPermutation(3,3);
        assert(res == "213");
    }
    {
        auto res = s.getPermutation(4, 9);
        assert(res == "2314");
    }
    {
        auto res = s.getPermutation(3, 1);
        assert(res == "123");
    }
    {
        auto res = s.getPermutation(2, 2);
        assert(res == "21");
    }
}
