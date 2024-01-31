#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {

        int dot1Prev = -1;
        int dot2Prev = -1;

        int dot1 = find(version1.begin(),version1.end(),'.')-version1.begin();
        int dot2 = find(version2.begin(),version2.end(),'.')-version2.begin();

        while(true){

            string part1 = (dot1Prev == version1.size()? string("0"): version1.substr(dot1Prev+1, dot1 - dot1Prev - 1));
            string part2 = (dot2Prev == version2.size()? string("0"): version2.substr(dot2Prev+1,dot2 -dot2Prev - 1));

            int v1 = 0;
            int v2 = 0;
            if(!part1.empty()){
                v1 = atoi(part1.c_str());
            }

            if(!part2.empty()){
                v2 = atoi(part2.c_str());
            }


            if(v1 <v2){
                return -1;
            }

            if(v1 > v2){
                return 1;
            }

            if(dot1 == version1.size() && dot2 == version2.size()){
                return 0;
            }

            dot1Prev = dot1;
            dot2Prev = dot2;


            dot1 = find(version1.begin()+dot1Prev+1,version1.end(),'.')-version1.begin();
            dot2 = find(version2.begin()+dot2Prev + 1,version2.end(),'.')-version2.begin();
        }
        
        return 0;
    }
};

int main(){
    Solution s;
    {
        string version1 = "1.01", version2 = "1.001";
        assert(s.compareVersion(version1,version2) == 0);
}

    {
        string version1 = "1.0", version2 = "1.0.0";
        assert(s.compareVersion(version1,version2) == 0);
}

    {
        string  version1 = "0.1", version2 = "1.1";
        assert(s.compareVersion(version1,version2) == -1);
}
}
