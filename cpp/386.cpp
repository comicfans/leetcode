#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int> ret;
        
        ret.reserve(n);



        recFill(ret,n,0);


        return ret;

    }

    void recFill(vector<int>& ret, int n, int prev){

        int moreBase = prev * 10;
        
        if(moreBase <= n){
        for(int i = 0;i <= 9;++i){

            int thisValue = moreBase + i;
            if(thisValue == 0){
                continue;
            }

            if(thisValue>n){
                    break;
            }

            ret.push_back(thisValue);
            recFill(ret, n, thisValue);
        }
        }
    }



};

int main(){

    

    Solution s;
    {
        vector<int> expect = {1,10,11,12,13,2,3,4,5,6,7,8,9};
        auto output = s.lexicalOrder(13);
        assert(output == expect);
    }
    {

        vector<int> expect = {1,2};
        auto output = s.lexicalOrder(2);
        assert(output == expect);
    }
    {

        int n = 5656;
    vector<string> vec;
    for(int i = 1;i<=n;++i){
        stringstream ss;
        ss<<i;
        string str;
        ss>>str;
        vec.push_back(str);
    }
    sort(vec.begin(),vec.end());
        vector<int> expect;
        for(auto v: vec){
            stringstream ss;
            ss<<v;
            int intV;
            ss>>intV;
            expect.push_back(intV);
        }
        auto res = s.lexicalOrder(n);
        assert(res == expect);
    
    }
}
