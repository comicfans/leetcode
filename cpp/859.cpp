#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.size()!=  goal.size()){
            return false;
        }

        if(s == goal){
            //find if any duplicate chars

            sort(s.begin(),s.end());
            auto end = unique(s.begin(),s.end());
            if(end == s.end()){
                return false;
            }
            return true;
        }


        vector<int> diffPos ;
        for(int i =0;i<s.size();++i){
            if(s[i] != goal[i]){
                diffPos.push_back(i);
                if(diffPos.size()>2){
                    return false;
                }
                continue;
            }
        }

        if(diffPos.size()!=2){
            return false;
        }

        return (s[diffPos[0]] == goal[diffPos[1]]) && (s[diffPos[1]] == goal[diffPos[0]]);
        
    }
};
