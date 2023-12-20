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

        int i = 0;
        int j = 0;

        while(i< name.size() || j<typed.size()){

            if(i>=name.size()){
                if(typed[j]!= name.back()){
                    return false;
                }

                ++j;
                continue;
            }

            if(j >= typed.size()){
                return false;
            }


            if(name[i]==typed[j]){
                ++i;
                ++j;
                continue;
            }

            if(i == 0){
                return false;
            }

            if(name[i-1] == typed[j]){
                ++j;
                continue;
            }else{
                return false;
            }
        }
        return true;
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
