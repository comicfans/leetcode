#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {

        string best = "";

        string current = "";

        for(int pos = 0;pos < num.size();++pos){
            char digits = num[pos];
            if(current.empty()){
                current.push_back(digits);
            }else{
                if(digits == current.back()){
                    current.push_back(current.back());
                    if(current.size() == 3){
                        if(best.empty()){
                            best = current;
                            current = "";
                        }else{
                            best = max(best, current);
                            if(best == "999"){
                                return best;
                            }
                        }
                    }
                }else{
                    current.clear();
                    current.push_back(digits);
                }
            }

        }

        return best;
        
    }
};

int main(){
    Solution s;
    {
        assert(s.largestGoodInteger("6777133339") == "777");
    }
}
