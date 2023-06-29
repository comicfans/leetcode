#include <iostream>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {


        for (int64_t try_number =1; try_number <= 60; ++try_number){
            int64_t diff = num1 - num2 * try_number;


            // can this diff be divided as sum of try_number count 2^i ? (0<=i <= 60)
            // it can be treated as 10010001
            // if number of 1 is larger than try_number , that is impossible
            // if number of 1 is equal to try_number, just ok
            //
            // if number of 1 is smaller than try_number,is it always possible? 
            // always possible if diff >= try_number because
            //
            // diff represent as binary, which can be represent as 
            // 1+1+1 .... = diff count, and for any try_number = diff-n
            //
            //
            // why 111 is possible for any 7~3 ?
            //
            // 111 7 1,1,1,1,1,1,1
            // 111 6 1,1,1,1,1,2
            // 111 5 1,1,1,2,2
            // 111 4 1,2,2,2
            // 111 3 1,2,4

            // 101 6 impossible
            // 101 1 impossible
            //why 101 is possible for any 5 ~ 2 ?
            // 101 5  1,1,1,1,1
            // 101 4  1,1,1,2
            // 101 3  1,2,2
            // 101 2  4,1
            //
            //
            //because this is like 1024 game
            //for min number just 1 at different binary pos
            //its always possible to split one value to two value (4->2,2, 2->1,1)
            //if no one can be split, it just turned into all 1
            //and every split just increase 1 count

            //count how many 1s of binary represent of diff

            if(diff <1){
                return -1;
            }

            if(diff < try_number){
                continue;
            }

            int binary_1s = 0;
            while((diff >0 ) & (binary_1s < try_number)){
                binary_1s += (diff %2 );
                diff = diff / 2;
            }

            if (diff == 0){
                return try_number;
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.makeTheIntegerZero(3, -2)<<endl;
    cout<<s.makeTheIntegerZero(5, 7)<<endl;
    cout<<s.makeTheIntegerZero(112577768,-501662198)<<endl;
}
