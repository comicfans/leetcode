#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        string head;

        vector<int> lastLeft;
        for(int i = 0; i< s.size(); ++i){

            if(s[i]!=']'){
                head.push_back(s[i]);

                if(s[i] == '['){
                    lastLeft.push_back(head.size()-1);
                }
                continue;
            }


            assert(!lastLeft.empty());
            int left = lastLeft.back();
            lastLeft.pop_back();

            string number;
            string inner = head.substr(left + 1);
            int j = left - 1;
            for( ;j>=0; --j){
                if(head[j]>='0' && head[j]<='9'){
                    number.push_back(head[j]);
                    continue;
                }
                break;
            }

            head.resize(j+1);
            reverse(number.begin(),number.end());

            int repeat = atoi(number.c_str());

            for(int j =0; j < repeat; ++j){
                head+= inner;
            }
        }

        return head;
    }
};


int main(){
    Solution s;
    {
        string input = "3[a]2[bc]";
        auto res = s.decodeString(input);
        assert(res == "aaabcbc");
    }
    {
        string input = "3[a2[c]]";
        string expect = "accaccacc";
        auto res = s.decodeString(input);
        assert(res == expect);
    }
    {
        string input = "2[abc]3[cd]ef";
        string expect = "abcabccdcdcdef";
        auto res = s.decodeString(input);
        assert(res == expect);
    }
}
