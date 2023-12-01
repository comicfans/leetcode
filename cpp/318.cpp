#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {

        sort(words.begin(),words.end(),[](auto &lhs, auto &rhs){
            return lhs.size() < rhs.size();
        });

        if(words.size()<2){
            return 0;
        }

        int currentMax = 0;
        for(int i =words.size()-1;i>=0;--i){
            for(int j = i-1; j>=0;--j){

                int possibleRes = words[i].size() * words[j].size();

                if(possibleRes < currentMax){
                    continue;
                }

                auto& lhs = words[i];
                auto& rhs = words[j];
                bool common = false;

                char searched[26] = {0};
                for(auto c: lhs){

                    if(searched[c-'a']>0){
                        continue;
                    }

                    searched[c-'a']++;
                    if(rhs.find(c)!= string::npos){
                        common = true;
                        break;
                    }
                }
                if(common){
                    continue;
                }

                currentMax = possibleRes;
            }
        }


        return currentMax;
    }
};

int main(){
    Solution s;
    {
        vector<string> input = {"abcw","baz","foo","bar","xtfn","abcdef"};
        assert(s.maxProduct(input) == 16);
    }
}
