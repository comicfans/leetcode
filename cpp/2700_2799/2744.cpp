#include <algorithm>
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        std::map<string, int> orig;

        int ret = 0;
        for(int i= 0; i< words.size();++i){

            auto as_reverse= words[i];
            std::reverse(as_reverse.begin(),as_reverse.end());

            auto pos = orig.find(as_reverse);
            if(pos == orig.end()){
                orig[words[i]] = 1;
                continue;
            }

            ++ret;

            pos->second --;

            if (pos->second == 0){
                orig.erase(pos);
                continue;
            };
        }
        
        return ret;
}

};


int main(){
    Solution s;
    std::vector<string> input = {"cd","ac","dc","ca","zz"};
    assert(s.maximumNumberOfStringPairs(input) == 2);

    input = {"ab","ba","cc"};
    assert(s.maximumNumberOfStringPairs(input) == 1);
    cout<<"ok"<<endl;
}
