#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());


        auto cvt = [](vector<int>& input, int x){
        vector<int> ret;
        ret.resize(input.size()+1);
        int prev = 1;
        for(int i=0;i<input.size();++i){
            ret[i] = input[i] - prev;
            prev = input[i];
        }
            ret.back() = x + 2 - input.back();
            return ret;
        };

        auto h = cvt(hBars,n);
        auto v = cvt(vBars,m);

        auto hPossible = possible(h);
        auto vPossible = possible(v);

        vector<int> inter;
         set_intersection(hPossible.begin(),hPossible.end(),vPossible.begin(),vPossible.end(),back_inserter(inter));

        return inter.back() * inter.back();

    }

    set<int> possible(const vector<int>& input){

        set<int> ret ;

        for(int begin = 0;begin< input.size();++begin){
            auto prev = input[begin];
            for(int end = begin+1;end < input.size();++end){
                auto res = prev + input[end];
                ret.insert(res);
                prev = res;
            }
        }

        return ret;

    }


};

int main(){
    Solution s;
    {
        int n = 2;
        int m = 4;
        vector<int> h = {3,2};
        vector<int> v = {4,2};
        assert(s.maximizeSquareHoleArea(n,m,h,v) == 4);
    }
    {
        int n = 2;
        int m = 1;
        vector<int> h = {2,3};
        vector<int> v = {2};

        assert(s.maximizeSquareHoleArea(n,m,h,v) == 4);

    }
    {
        int n = 1;
        int m = 1;
        vector<int> h = {2};
        vector<int> v = {2};
        assert(s.maximizeSquareHoleArea(n,m,h,v) == 4);
    }
    
}
