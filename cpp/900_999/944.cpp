#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int count = 0;
        for(int i =0;i<strs[0].size();++i){

            char prev = 'a';
            for(const auto& s: strs){

                if(s[i]< prev){
                    ++count;
                    break;
                }

                prev = s[i];

            }

        }

        return count;
    }
};
