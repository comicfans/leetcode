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
    int numberOfSequence(int n, vector<int>& sick) {


        int prev = -1;
        long long current = 1;
        sick.push_back(n);
        for(int i = 0; i< sick.size();++i){


            int diff = sick[i] - prev -1;

            if(diff <= 1){
                prev = sick[i];
                continue;
            }

            int firstTry = 2;

            while(diff > 1 ){
                --diff;
                current *= 2;
                current = current % (long long)(pow(10,9)+7);
            }
            prev = sick[i];

        }
        return current;
    }
};

int main(
){
    Solution s;
    {
        vector<int> input = {0,4};
        int res = s.numberOfSequence(5,input) ;
        assert(res== 4);
    }
}
