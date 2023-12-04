#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {

        string ret ;
        
        int prevSlashPos = -2;

        int dotCount = 0;
        for(int i =0; i<= path.size();++i){

            char thisC;
            if(i == path.size()){
                thisC = '/';
            }else{
                thisC  = path[i];
            }


            if(thisC == '/'){
                if(i==prevSlashPos+1){
                    prevSlashPos = i;
                    continue;
                }

                //new slash, checking if this is after single dot,or two dot 

                if(dotCount == 0){
                    prevSlashPos = i;
                    ret.push_back(thisC);
                    continue;
                }



                if (dotCount == 1){
                    if(ret.back()=='/'){
                    prevSlashPos = i;
                    dotCount = 0;
                    continue;
                    }
                }

                if(dotCount == 2){
                    if(ret.back()=='/'){
                    //two dot, pop existing one level

                    //remove one slash
                    if(ret.size()!=1){
                        ret.pop_back();
                    }

                    //pop until next slash
                    while(ret.back()!='/'){
                        ret.pop_back();
                    }
                    //not one level poped,but still have slash

                    prevSlashPos = i;
                    dotCount = 0;
                    continue;
                }
                }

                    //this is normal filename
                    ret.resize(ret.size()+dotCount,'.');
                    ret.push_back(thisC);
                    dotCount = 0;
                    continue;
                
            }

            if(thisC == '.'){
                ++dotCount;
                continue;
            }

            if(dotCount > 0){
                ret.resize(ret.size() + dotCount, '.');
                dotCount = 0;
            }

            ret.push_back(thisC);
        }
        
        if(!ret.empty()){
            while(ret.back()=='/'){
                if(ret.size()==1){
                    break;
                }
                ret.pop_back();
            }
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        string input = "/home/";
        assert(s.simplifyPath(input) == "/home");
    }
    {

        string input = "/../";
        assert(s.simplifyPath(input) == "/");
    }
    {
        string input = "/home//foo/";
        assert(s.simplifyPath(input) == "/home/foo");
    }
    {
        string input = "/...";
        assert(s.simplifyPath(input) == "/...");
    }
    {
        string input = "/..hidden";
        assert(s.simplifyPath(input) == "/..hidden");
    }
    {
        string input = "/hello../world";
        assert(s.simplifyPath(input) == input);
    }
}
