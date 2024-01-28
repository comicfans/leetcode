#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {


        vector<int> candies(ratings.size(),1);


        vector<int> idx(ratings.size());
        for(int i = 0;i<ratings.size(); ++i){
            idx[i] = i;
        }

        auto lambda = [&](int lhs,int rhs){
            return ratings[lhs] < ratings[rhs];
        };

        sort(idx.begin(),idx.end(), lambda);

        int pos = 0;
        while(pos < ratings.size()){



            auto endPos = upper_bound(idx.begin(),idx.end(),idx[pos], lambda) - idx.begin();
            if(pos == 0){
                pos = endPos;
                continue;
            }
            int thisRating = ratings[idx[pos]];

            for(int i = pos;i < endPos;++i){

                int oIdx = idx[i];

                if(oIdx >0 && ratings[oIdx]> ratings[oIdx-1]){
                    candies[oIdx] = candies[oIdx-1]+1;
                }

                if(oIdx < ratings.size()-1 && ratings[oIdx]> ratings[oIdx+1]){
                    candies[oIdx] = max(candies[oIdx],candies[oIdx+1]+1);
                }

                pos = endPos;

            }

            
        }

        int total = accumulate(candies.begin(),candies.end(),0);
        return total;


        
    }
};


int main(){
    Solution s;
    {
        vector<int> r = {1,0,2};
        assert(s.candy(r) == 5);
    }
}
