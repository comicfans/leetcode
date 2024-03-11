#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {

        vector<string> ret(arr.size());

        for(int i = 0; i< arr.size(); ++i){

            const string& s = arr[i];
            vector<string> possible;

            for(int trySize = 1; trySize <= s.size(); ++ trySize){
                if(!possible.empty()){
                    break;
                }
                for(int start = 0; start+trySize <= s.size(); ++start){

                    auto sub = s.substr(start, trySize);

                    bool noMatch = true;
                    for(int check = 0; check < arr.size(); ++check){
                        if(check == i){
                            continue;
                        }
                        if(arr[check].find(sub)!= string::npos){
                            noMatch=false;
                            break;
                        }
                    }

                    if(noMatch){
                        possible.push_back(sub);
                    }
                }
            }

            if(possible.empty()){
                ret[i] = "";
            }else{
                sort(possible.begin(),possible.end());
                ret[i] = possible.front();
            }
        }


        return ret;
    }
};

int main(){

    Solution s;
    {
        vector<string> arr = {"cab","ad","bad","c"};
        vector<string> expect=  {"ab","","ba",""};
        auto res = s.shortestSubstrings(arr);
        assert(expect == res);
    }
    {
        vector<string> arr = {"abc","bcd","abcd"};
        vector<string> expect =  {"","","abcd"};
        auto res = s.shortestSubstrings(arr);
        assert(expect == res);
    }
}
