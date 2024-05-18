#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {

        auto p = -1;

        while(p!=s.size()){

            auto nextP = find(s.begin()+p+1,s.end(),' ') - s.begin();

            reverse(s.begin()+p+1, s.begin()+nextP);

            p = nextP;
        }

        return s;
        
    }
};

int main(){
    Solution s;
    {
        string i= "Let's take LeetCode contest";
string expect =  "s'teL ekat edoCteeL tsetnoc";
        auto v= s.reverseWords(i);
        assert(v == expect);

}
    {
string in = "Mr Ding";
string expect ="rM gniD";

        auto v= s.reverseWords(in);
        assert(v == expect);
    }


}
