#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> addOperators(string num, int target) {


        //for every pos, can be + - * nop and finally eval expr
        //

        // + = 3
        // - = 2
        // * = 1
        // _  = 0
        // so we have 4^ (num-1) combine

        vector<string> ret;
        string init ;
        vector<string> stack;
        recEval(num, ret, target,0,stack);
        return ret;
    }

    void recEval(string num, vector<string>& ret,  int target,  int currentPos, vector<string>& stack){

        if(currentPos == num.size()){

            while(stack.size()>1){
                int last = stack.back();
                stack.pop_back();
                int prev = stack.back();
                stack.pop_back();
                int mul = last * prev;
            }
        }



    }



    
};
