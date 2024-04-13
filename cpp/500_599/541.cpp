#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {

        for(int i = 0; ; ++i){

            int head = i * k;

            if(head >= s.size()){
                break;
            }

            if(i % 2== 1){
                continue;
            }

            int tail = min((i+1) * k,(int)s.size());

            reverse(s.begin()+head, s.begin()+tail);

        }

        return s;
        
    }
};
