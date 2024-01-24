#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }

        return recFind(s3,0,s1,0,s2,0);
        
    }

    bool recFind(const std::string& s3, int p3,
                 const std::string& s1, int p1,
                 const std::string& s2, int p2
                 ){

        if(p3 == s3.size() && p1 == s1.size() && p2 == s2.size()){
            return true;
        }

        char c = s3[p3];

        if(p1 != s1.size() && c==s1[p1]){

            if(recFind(s3,p3+1,s1,p1+1,s2,p2)){
                return true;
            }
        }

        if(p2 != s2.size() && c== s2[p2]){

            return recFind(s3,p3+1,s1,p1,s2,p2+1);
        }
       
        return false;
    }
};

int main(){
    Solution s;
    assert(!s.isInterleave("a","b","a"));
    {
string s1 = "abababababababababababababababababababababababababababababababababababababababababababababababababbb";
        string s2 = "babababababababababababababababababababababababababababababababababababababababababababababababaaaba";
        string s3 = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb";
    }
}
