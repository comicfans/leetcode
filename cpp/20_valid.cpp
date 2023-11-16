#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isValid(string s) {

        vector<char> stack;

        std::map<char,char> match = {{')','('},{'}','{'},{']','['}};

        for(auto c: s){

            auto pos = match.find(c);
            if(pos == match.end()){
                stack.push_back(c);
                continue;
            }
            

            if(stack.empty()){
                return false;
            }
            
            if(stack.back()!= pos->second){
                return false;
            }

            stack.pop_back();
        }

        return stack.empty();
    }
};
