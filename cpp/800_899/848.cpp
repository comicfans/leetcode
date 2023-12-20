#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int sum = 0;
        for(int i = 0; i < shifts.size(); ++i){
            shifts[shifts.size() -1 - i] = (sum + shifts[shifts.size() - 1 -i]) % 26;
            sum = shifts[shifts.size() -1- i];
        }

        for(int i = 0;i< shifts.size(); ++i){

            int number = shifts[i] % 26;

            char thisChar = s[i];
            char finalChar = (thisChar - 'a' + number )   % 26 + 'a';

            s[i] = finalChar;


        }
        return s;
        
    }
};

int main(){
    Solution s;
    {
        string input = "abc";
        vector<int> shifts = {3,5,9};
        string expect = "rpl";
        assert(s.shiftingLetters(input,shifts) == expect);

    }
}
