#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        if(folder.empty()){
            return {};
        }

        multimap<int, string> levelPath;

        for(const auto& path: folder){

            int slashCount = count(path.begin(),path.end(),'/');

            levelPath.insert({slashCount,path});
        }

        //test any folder have same prefix with shorter 

        auto shortest = levelPath.begin()->first;

        auto longerPos = levelPath.lower_bound(shortest+1);

        vector<string> ret;

        for(auto it = levelPath.begin();it != longerPos; ++it){
            ret.push_back(it->second);
        }


        while(longerPos != levelPath.end()){

            auto checkEnd = levelPath.upper_bound(longerPos->first-1);

            bool isSub = false;
            for(auto check = levelPath.begin();check!=checkEnd;++check){
                if(check->second.size()> longerPos->second.size()){
                    continue;
                }

                if(equal(check->second.begin(),check->second.end(), longerPos->second.begin())){
                    isSub = true;
                    break;
                }
            }

            if(!isSub){
                ret.push_back(longerPos->second);
            }

            ++longerPos;
        }
        
        return ret;
    }
};

int main(
){
    Solution s;
    {
vector<string> input = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
        auto res = s.removeSubfolders(input);
    vector<string> expect = {"/a","/c/d","/c/f"};
        assert(res == expect);

    }
}
