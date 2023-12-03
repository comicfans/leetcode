#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),[](auto& lhs,auto& rhs){
            return lhs.size() < rhs.size();
        });


        vector<int> longest(words.size(),-1);
        
        int res =recFind(words,0,"",longest);

        return res;

    }

    int recFind(const vector<string>& words, int pos, const string& prev, vector<int>& longest){

        if(pos == words.size()){
            return 0;
        }


        int thisBest = 0;

        int begin = pos;
        int end = words.size();
        if(prev!= ""){
        int thisLength =  prev.size()+1;

        auto eqRange = equal_range(words.begin()+pos,words.end(), string(thisLength,' '),[](auto &lhs,auto& rhs ){
            return lhs.size() < rhs.size();
        });
            begin = eqRange.first - words.begin();
            end = eqRange.second - words.begin();
        }

        


        for(auto i = begin; i< end; ++i){

            const auto& str = words[i];

            //test if this is sub

            bool hasDiff = false;
            bool mismatch = false;
            int targetPos = 0;
            for(int c = 0;c<str.size() && targetPos < prev.size();){

                if(str[c] == prev[targetPos]){
                    ++c;
                    ++targetPos;
                    continue;
                }

                if(hasDiff){
                    mismatch = true;
                    break;
                }

                hasDiff = true;
                ++c;
            }

            if(mismatch){
                continue;
            }

            int sub = 1;
            //this can be chain with prev
            thisBest = max(thisBest, sub);

            if(longest[i]!= -1){
                sub = longest[i];
            }else{
                sub = recFind(words, i+1, str, longest)+1;
            }

            longest[i] = sub;
            thisBest = max(thisBest, longest[i]);
        }


        return thisBest;
    }
};

int main(){
    Solution s;
    {
        vector<string> input= {"a","ab","ac","bd","abc","abd","abdd"};
        assert(s.longestStrChain(input)==4);

    }
    {
        vector<string> input = {"a","b","ba","bca","bda","bdca"};
        assert(s.longestStrChain(input)==4);
    }
    {
        vector<string> input = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
        assert(s.longestStrChain(input)==5);
    }
}
