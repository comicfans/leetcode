#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        vector<tuple<int,string,string>> reorder;
        for(int i = 0;i<indices.size();++i){
            reorder.push_back({indices[i], sources[i],targets[i]});
        }

        sort(reorder.begin(),reorder.end());


        int offset = 0;
        for(const auto& tup: reorder){

            const int idx = get<0>(tup);
            const auto& check = get<1>(tup) ;
            const auto& target = get<2>(tup);

            int thisIdx = idx + offset;

            if(equal(s.begin() + thisIdx, min(s.end(), s.begin() + thisIdx + check.size()), check.begin(), check.end())){

                int delta = target.size() - check.size();

                s.replace(thisIdx, check.size(), target);
                offset += delta;
            }


        }

        return s;
    }
};

int main(){
    Solution s;
    {
        string input =
"vmokgggqzp";
        vector<int> indices =
            {3,5,1};
        vector<string> sources ={"kg","ggq","mo"};
        vector<string> targets = {"s","so","bfr"};
        string expected = "vbfrssozp";
        assert(s.findReplaceString(input,indices,sources,targets) == expected);

    }
    {
        string input = "abcd";
        vector<int> indices = {0, 2};
        vector<string> sources = {"a", "cd"};
        vector<string> targets = {"eee", "ffff"};
        string expect  = "eeebffff";

        assert(s.findReplaceString(input,indices,sources,targets) == expect);
    }
    {
        string input = "abcd";
        vector<int> indices = {0, 2};
        vector<string> sources = {"ab","ec"};
        vector<string> targets = {"eee","ffff"};
        string expect  = "eeecd";

        assert(s.findReplaceString(input,indices,sources,targets) == expect);
    }
}
