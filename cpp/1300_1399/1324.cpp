#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> printVertically(string s) {

        vector<string> vertical;

        int maxLength = 0;
        for(auto c:s){
            if(vertical.empty()){
                vertical.push_back("");
            }
            if(c!=' '){
                vertical.back().push_back(c);
                maxLength = max<int>(maxLength,vertical.back().size());
            }else{
                vertical.push_back("");
            }
        }

        vector<string> ret;
        for(int i =0;i<maxLength;++i){

            string thisOne ="";
            for(int col = 0;col < vertical.size();++col){
                const auto& thisCol = vertical[col];
                if(i>=thisCol.size()){
                    thisOne.push_back(' ');
                }else{
                    thisOne.push_back(thisCol[i]);
                }
            }

            while(thisOne.back()==' '){
                thisOne.pop_back();
            }
            ret.push_back(thisOne);


        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        string input = "HOW ARE YOU";
        vector<string> expect = {"HAY","ORO","WEU"};
        assert(s.printVertically(input) == expect);
    }
    {
        string input = "TO BE OR NOT TO BE";
        vector<string> expect = {"TBONTB","OEROOE","   T"};
        assert(s.printVertically(input)== expect);
    }
}
