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
    string countAndSay(int n) {

        string prev = "1";

        for(int i = 1;i<n;++i){

            std::vector<pair<char,int>> next;

            for(auto c:prev){

                if(next.empty() || (c!= next.back().first)){
                    next.push_back({c,1});
                    continue;
                }

                next.back().second++;

            }
                //turn it to string
                string str;
                for(auto kv: next){
                    stringstream temp;
                    temp<<kv.second;
                    string countStr;
                    temp>>countStr;

                    stringstream temp2;
                    temp2<<kv.first;
                    string valueStr;
                    temp2>>valueStr;

                    str = str+ countStr + valueStr;
                }

                prev = str;

        }

        return prev;
    }
};

int main(){
    Solution s;
    assert(s.countAndSay(4) == "1211");
}
