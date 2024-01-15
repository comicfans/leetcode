#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {

        vector<string> ret;

        for(const auto s:words){


            int prevPos = -1;

            while(prevPos != s.size()){
                int thisPos = s.find(separator,prevPos + 1);
                if(thisPos == string::npos){
                    thisPos = s.size();
                }

            int thisSize = thisPos - prevPos-1;
            if(thisSize > 0){
                ret.push_back(s.substr(prevPos+1,thisSize));
            }

            prevPos = thisPos;
            

}

        }
        return ret;
        
    }
};
