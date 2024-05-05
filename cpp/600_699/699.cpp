#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {

        map<int,pair<int,int>> x_width_height = {{-1,{1,0}}, {INT_MAX,{0,0}}};

        int heighest = 0;

        vector<int> ret;
        for(const auto& drop: positions){

            int x = drop[0];
            int side = drop[1];

            auto left_less = x_width_height.lower_bound(x);
            auto right_less = x_width_height.lower_bound(x+side);

            assert(left_less != x_width_height.begin());
            --left_less;

            assert(right_less!= x_width_height.end());

            //from left_less up to right_less (exclude)

            int maxHeight = 0;

            bool hasOverlap = false;
            for(auto it=left_less; it!= right_less; ++it){
                if (min(it->first + it->second.first, x+side) - max(it->first, x)<=0 && !hasOverlap){
                    //no overlap
                    ++left_less;
                    continue;
                }
                //has overlap
                maxHeight = max(maxHeight, it->second.second);
                hasOverlap = true;
            }

            int thisRes = ret.empty()? (maxHeight + side):max(maxHeight+side, ret.back());
            ret.push_back(thisRes);

            if(x == left_less->first){

                if(side == left_less->second.first){
                    left_less->second.second = maxHeight+side;
                    continue;
                }

                if(side < left_less->second.first){
                    //insert new node at new pos

                    x_width_height.insert(left_less, { left_less->first + side,
                        {left_less->first + left_less->second.first - (x+side),left_less->second.second}});
                    left_less->second.first = side;
                    left_less->second.second = maxHeight+side;
                    continue;
                }

                left_less->second.first = side;
                left_less->second.second = maxHeight + side;
                ++left_less;
            }

            if(x < left_less->first){
                auto newPos = x_width_height.insert({x,{side, maxHeight+ side}});


                if(x+side <= left_less->first){
                    continue;
                }

                pair<int,pair<int,int>> value = *left_less;


                x_width_height.erase(left_less);

                left_less = newPos.first;

                if(x+side < value.first + value.second.first){
                    x_width_height.insert({x+side, { value.first+ value.second.first - (x+side),  value.second.second}});
                    continue;
                }

                if(x + side == value.first + value.second.first){
                    //do nothing
                    continue;
                }
                ++left_less;

            }else{
                // x> left_less->first

                pair<int,pair<int,int>> oldValue = *left_less;

                left_less->second.first = x - left_less->first;

                auto newPos =x_width_height.insert({x,{side,maxHeight + side}});

                if(x+side == oldValue.first + oldValue.second.first){
                    continue;
                }

                if(x + side < oldValue.first + oldValue.second.first){
                    x_width_height.insert({x+side, {oldValue.first + oldValue.second.first - (x+side), oldValue.second.second}});
                    continue;
                }
                // x+side > 
                left_less = newPos.first;
                ++left_less;
            }

            //delete any value between left_less ~ right_less

            auto del_begin = left_less;

            auto del_end = right_less;
            --del_end;

            pair<int,pair<int,int>> oldValue = *del_end;

            auto hint = del_begin;
            --hint;
            if(del_end->first >= left_less->first){
                x_width_height.erase(del_begin, right_less);
            }

            if(oldValue.first+ oldValue.second.first <= x+side){
                continue;
            }

            int newWidth = oldValue.first + oldValue.second.first - (x+side);
            oldValue.first = x+side;
            oldValue.second.first = newWidth;

            x_width_height.insert(hint, oldValue);
        }

        return ret;
    }
};

#ifdef LEETCODE
int main(){

    Solution s;
    {
        vector<vector<int>> input ={{9,1},{6,5},{6,7}};
        vector<int> expect={1,6,13};

        auto res = s.fallingSquares(input);
        assert(res == expect);
        //13|                       +---------------------------+
        //  |                       |                           |
        //12|                       |                           |
        //  |                       |                           |
        //11|                       |                           |
        //  |                       |                           |
        //10|                       |                           |
        //  |                       |                           |
        // 9|                       |                           |
        //  |                       |                           |
        // 8|                       |                           |
        //  |                       |                           |
        // 7|                       |                           |
        //  |                       |                           |
        // 6|                       +-------------------+-------+
        //  |                       |                   |       13
        // 5|                       |                   |
        //  |                       |                   |
        // 4|                       |                   |
        //  |                       |                   |
        // 3|                       |        2          |
        //  |                       |                   |
        // 2|                       |                   |
        //  |                       |                   |
        // 1|                       +-----------+---+---+
        //  |                                   | 1 |   11
        //  +-----------------------+-----------+---+--------------------
        //  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14
    }                               
    {                               
        //34|                                   +-------------------------------+
        //  |                                   |                               |
        //33|                                   |                               |
        //  |                                   |                               |
        //32|                                   |                               |
        //  |                                   |                               |
        //31|                                   |                               |
        //  |                                   |                5              |
        //30|                                   |                               |
        //  |                                   |                               |
        //29|                                   |                               |
        //  |                                   |                               |
        //28|                                   |                               |
        //  |                                   |                               |
        //27|                                   |                               |
        //  |                                   |                               |
        //26|    +------------------------------+---+---------------------------+
        //  |    |                              9   |                          17
        //25|                                       |
        //  |    |                                  |
        //24|    |                                  |
        //  |    |                                  |
        //23|    |                                  |
        //  |    |                                  |
        //22|    |               4                  |
        //  |    |                                  |
        //21|    |                                  |
        //  |    |                                  |
        //20|    |                                  |
        //  |    |                                  |
        //19|    |                                  |
        //  |    |                                  |
        //18|    |                                  |
        //  |    |                  6               |
        //17|    +------------------+---------------+---------------+
        //  |                       |              10               |       
        //16|                       |                               |       
        //  |                       |                               |       
        //15|                       |                               |       
        //  |                       |                               |       
        //14|                       |                               |       
        //  |                       |                               |       
        //13|                       |                     3         |       
        //  |                       |                               |       
        //12|                       |                               |       
        //  |                       |                               |       
        //11|                       |                               |       
        //  |                       |                               |       
        //10|                       |                               |       
        //  |                       |                               |       
        //9 |                       +-------------------------------+---+
        //  |                       |                              14   |     
        //8 |                       |                                   |       
        //  |                       |                                   |       
        //7 |                       |                                   |       
        //  |                       |                                   |       
        //6 |                       |                                   |       
        //  |                       |                                   |       
        //5 |                       |                                   |       
        //  |                       |                     2             |       
        //4 |                       |                                   |       
        //  |                       |                                   |       
        //3 |                       |                                   |       
        //  |                       |                                   |       
        //2 |                       |                                   |       
        //  |                       |                                   |       
        //1 |               +---+   |                                   |       
        //  |               | 1 |   |                                   |       
        //  +---------------+---+---+-----------------------------------+-------+-------
        //  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18
        //
        //
        //
        //
        //
        vector<vector<int>> input ={{4,1},{6,9},{6,8},{1,9},{9,8}};
        vector<int> expect ={1,9,17,26,34};

        auto res = s.fallingSquares(input);
        assert(res == expect);
    }
{
        vector<vector<int>> input = {{4,9},{8,8},{6,8},{8,2},{1,2}};
        auto res = s.fallingSquares(input);
    }
    {
        vector<vector<int>> input ={{1,2},{2,3},{6,1}};
        vector<int> expect =  {2,5,5};
        auto res = s.fallingSquares(input);
        assert(res == expect);
    }
    {
        vector<vector<int>> input ={{100,100},{200,100}};
        vector<int> expect =  {100,100};
        auto res = s.fallingSquares(input);
        assert(res == expect);
    }
}

#endif
