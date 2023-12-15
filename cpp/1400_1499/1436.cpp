#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        
        auto current = paths[0][1];
        while(true){

            auto nextPos = find_if(paths.begin(),paths.end(),[&](auto& v){
                return v[0] == current;
            });

            if(nextPos == paths.end()){
                return current;
            }

            current = (*nextPos)[1];
        }

        assert(false);
    }
};
