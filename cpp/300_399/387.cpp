#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {


        vector<int> count(26,numeric_limits<int>::max());
        for(int i =0;i<s.size();++i){
            
            int idx = s[i]- 'a';
            if(count[idx]==numeric_limits<int>::max()){
                count[idx]=i;
            }else{
                count[idx] = numeric_limits<int>::max()-1;
            }
        }

        auto minOne = *min_element(count.begin(),count.end()) ;

        return minOne>= s.size()?-1:minOne;

        

        
    }
};
