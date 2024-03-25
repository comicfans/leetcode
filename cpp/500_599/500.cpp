#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char row1[] = "qwertyuiop",
        row2[]= "asdfghjkl",
        row3[]="zxcvbnm";
        array<set<char>,3> rows = {set<char>(begin(row1),end(row1)),
                                    set<char>{begin(row2),end(row2)},
                                    set<char>{begin(row3),end(row3)}};

        vector<string> ret;
        for(const auto& s: words){
            int row = -1;
            bool ok = true;
            for(auto c: s){
                
                for(int tryRow = 0; tryRow < 3; ++ tryRow){
                    if(rows[tryRow].contains(tolower(c))){
                        if(row==-1){
                            row = tryRow;
                            continue;
                        }
                        if(row != tryRow){
                            ok=false;
                            break;
                        }
                    }
                }
                if(!ok){
                    break;
                }
            }
            if(ok){
                ret.push_back(s);
            }
            
        } 
        return ret;
    }
};
