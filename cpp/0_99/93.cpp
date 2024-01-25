#include <vector>
#include <sstream>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> ret;

        vector<pair<string,int>> idx;
        recTry(s, idx ,ret);


        return ret;
        
    }

    void recTry(const string& s,vector<pair<string,int>>& dotAt,vector<string>& ret){

        if(dotAt.size()== 3){
            auto lastStr = s.substr(dotAt.back().second);
            if(lastStr.size()>1 && lastStr.front() == '0'){
                return;
            }
            stringstream last ;
            last<<lastStr;
            int readBack;
            last>>readBack;
            if(readBack >255){
                return;
            }

            string all;
            for(int i = 0; i< dotAt.size();++i){
                all = all+ string(i==0? "": ".")+ dotAt[i].first;
            }
            all=all+"."+lastStr;

            ret.push_back(all);
            return;
        }

        int prev = (dotAt.empty()?0:dotAt.back().second);
        for(int i = 1 ; i < 4 && prev +i <= (int)s.size()-(3 - (int)dotAt.size());++i){

            string thisStr = s.substr(prev, i);

            if(thisStr.size() > 1 && thisStr.front() == '0'){
                return;
            }

            stringstream part;
            part<<thisStr;
            int readBack ;
            part>>readBack;
            if(readBack > 255){
                return;
            }

            dotAt.push_back({thisStr, prev+i});
            recTry(s,dotAt, ret);

            dotAt.pop_back();
        }

    }
};

int main() {
  Solution s;
  {

    string input = "0";

    auto res = s.restoreIpAddresses(input);
    assert(res.empty());
  }
  {
    string input = "25525511135";
    auto res = s.restoreIpAddresses(input);
    sort(res.begin(), res.end());
    vector<string> expect = {"255.255.11.135", "255.255.111.35"};
    sort(expect.begin(), expect.end());
    assert(res == expect);
  }
  {

    string input = "0000";
    auto res = s.restoreIpAddresses(input);
    assert(res == vector<string>{"0.0.0.0"});
  }
  {

    string input = "101023";

    auto res = s.restoreIpAddresses(input);
    sort(res.begin(), res.end());
    vector<string> expect = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3",
                             "101.0.2.3"};
    sort(expect.begin(), expect.end());
    assert(res == expect);
  }

}
