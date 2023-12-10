#include <map>
#include <vector>
#include <limits>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        int best = std::numeric_limits<int>::max();
        std::map<int, int> current_start;

        for(int idx = 0;idx<cards.size();++idx){

            int number = cards[idx];

            if(current_start.count(number)==0){
                current_start[number] = idx;
                continue;
            }


            int number_steps = idx - current_start[number]+1;
            if(number_steps == 2){
                return number_steps;
            }
            best = std::min(best, number_steps);
            current_start[number] = idx;
        }

        return best == std::numeric_limits<int>::max()? -1: best;
    }
};

int main(){
    Solution s;
    std::vector<int> cards = {3,4,2,3,4,7};
    cout<<s.minimumCardPickup(cards)<<endl;
    cards = {1,0,5,3};
    cout<<s.minimumCardPickup(cards)<<endl;
    cards = {95,11,8,65,5,86,30,27,30,73,15,91,30,7,37,26,55,76,60,43,36,85,47,96,6};
    cout<<s.minimumCardPickup(cards)<<endl;
}
