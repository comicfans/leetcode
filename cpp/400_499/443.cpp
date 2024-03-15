#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {

        int charEnd = 1;
        int repeatCount = 1;
        for(int i = 1; i <= chars.size(); ++ i ){

            if(i< chars.size() &&chars[i] == chars[i-1]){
                ++ repeatCount;
                continue;
            };
            //diff condition

            if(repeatCount == 1){
                if(i == chars.size()){
                    break;
                }

                chars[charEnd] = chars[i];

                charEnd = charEnd + 1;
                continue;
            }

            string countStr = to_string(repeatCount);
            copy(countStr.begin(),countStr.end(), chars.begin() + charEnd);

            repeatCount = 1;
            charEnd = charEnd + countStr.size();
            if(i == chars.size()){
                break;
            }

            chars[charEnd] = chars[i];
            ++charEnd;
        }

        chars.resize(charEnd);
        return charEnd;
    }
};
int main(){
    Solution s;
    {
        vector<char> input = {'a','b','c','d','e','f','g','g','g','g','g','g','g','g','g','g','g','g','a','b','c'};
        vector<char> expect = {'a','b','c','d','e','f','g','1','2','a','b','c'};
        auto res = s.compress(input);
        assert(res==expect.size());
        for(int i = 0; i< res; ++i){
            assert(input[i] == expect[i]);
        }


    }
    {
        vector<char> input = {'a','a','a','a','b','a'};
        vector<char> expect = {'a','4','b','a'};
        auto res = s.compress(input);
        assert(res==4);
        for(int i = 0; i< res; ++i){
            assert(input[i] == expect[i]);
        }


    }
    {
        vector<char> input = {'a','a','b','b','c','c','c'};
        vector<char> expect = {'a','2','b','2','c','3'};
        auto res = s.compress(input);
        assert(res==6);
        for(int i = 0; i< 6; ++i){
            assert(input[i] == expect[i]);
        }
    }
    {
        vector<char> input = {'a'};
        vector<char> expect = {'a'};
        auto res = s.compress(input);
        assert(res==1);
        for(int i = 0; i< res; ++i){
            assert(input[i] == expect[i]);
        }

    }
{
        vector<char> input = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
        vector<char> expect = {'a','b','1','2'};
        auto res = s.compress(input);
        assert(res==4);
        for(int i = 0; i< res; ++i){
            assert(input[i] == expect[i]);
        }

    }
    

}
