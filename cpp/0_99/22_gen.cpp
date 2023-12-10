#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> ret;

        string existing;
        recAdd(n,n,existing, true, ret);

        return ret;
    }

    void recAdd(int left,int right,string& existing,bool tryLeft,vector<string>& ret){

        if((left==0) && (right == 0)){
            ret.push_back(existing);
            return;
        }

        assert(left <= right);

        if(tryLeft){
            for(int putLeft = 1; putLeft <= left; ++putLeft){
                existing.resize(existing.size() + putLeft);
                fill_n(existing.end()- putLeft,putLeft,'(' );
                recAdd(left - putLeft, right, existing, false, ret);
                existing.resize(existing.size()  - putLeft);
            }

            return;
        }

        //try right
        
        for(int putRight = 1; putRight <= right - left;++putRight){
                existing.resize(existing.size() + putRight);
                fill_n(existing.end()- putRight,putRight,')' );
                recAdd(left , right - putRight, existing, true,ret);
                existing.resize(existing.size()  - putRight);
        }
    }
};

int main(){
    Solution s;
    {
        auto res = s.generateParenthesis(3);
        for(auto v:res){
            cout<<v<<endl;
        }
    }
}
