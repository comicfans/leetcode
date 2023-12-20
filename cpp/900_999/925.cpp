#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int lastCharPos = -1;
        for(int i = 0;i< name.size();++i){
            auto c=name[i];
            int thisPos = typed.find(c,lastCharPos+1);
            if(thisPos == string::npos){
                return false;
            }

            //during lastCharPos+1 ~ thisPos must be repeat of prev char
            //
            if(i == 0){
                if(thisPos!=0){
                    return false;
                }
                lastCharPos = thisPos;
                continue;
            }
            
            for(int j = lastCharPos +1;j<thisPos;++j){
                if(typed[j]!= name[i - 1]){
                    return false;
                }
            }


            lastCharPos = thisPos;
        }

        if(lastCharPos == typed.size()-1){
            return true;
        }

        auto nonRepeat = typed.find_first_not_of(name.back(),lastCharPos+1);

        return nonRepeat == string::npos;
        
    }
};

int main(){
    Solution s;
    {
        assert(!s.isLongPressedName("ppyplrza","pyypllrza"));
    }
    {
        assert(!s.isLongPressedName("alex","aaleelx"));
    }
}
