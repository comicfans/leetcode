#include <numeric>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        vector<int> nums;

        for(int i = 0;i<tokens.size();++i){

            bool isOp = (tokens[i].size()==1 && !isdigit(tokens[i][0]));

            if(!isOp){
                nums.push_back(atoi(tokens[i].c_str()));
                continue;
            }


            int res ;
            switch(tokens[i][0]){
                case '+':{
                    res = nums.back()+nums[nums.size()-2];
                    break;
                }
                case '-':{
                    res = nums[nums.size()-2] - nums.back();
                    break;
                }
                case '*':{
                    res = nums[nums.size()-2] * nums.back();
                    break;
                }
                case '/':{
                    res = nums[nums.size()-2] / nums.back();
                    break;
                }
            }
            nums.pop_back();
            nums.back() = res;

        }

        return nums.front();
        
    }
};
int main(){
    Solution s;

    {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        assert(s.evalRPN(tokens)==22);
//Output: 22
//Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
    }
{
        vector<string> exp = {"4","13","5","/","+"};
        assert(s.evalRPN(exp) == 6);
    }
    {
        vector<string> exp = {"2","1","+","3","*"};
        assert(s.evalRPN(exp) == 9);
    }

}
