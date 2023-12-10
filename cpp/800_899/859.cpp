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

        if(diffPos.empty()){
            //find if any duplicate chars
            vector<int> count(26);
            for(int i=0;i<s.size();++i){
                int idx = s[i] - 'a';
                count[idx]++;
                if(count[idx]>1){
                    return true;
                }
            }
            return false;
        }

        if(diffPos.size()!=2){
            return false;
        }

        return (s[diffPos[0]] == goal[diffPos[1]]) && (s[diffPos[1]] == goal[diffPos[0]]);
        
    }
};
