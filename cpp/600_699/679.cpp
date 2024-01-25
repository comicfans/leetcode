#include <vector>
#include <array>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Num{
    int up;
    int down;

    Num(int number){
        up = number;
        down = 1;
    }

    static long long gcd(long long a,long long b){
        long long minV = min(a,b);
        long long maxV = max(a,b);

        if(maxV % minV == 0){
            return minV;
        }

        auto mod = maxV % minV;
        return gcd(minV, mod);
    }

    bool isNan()const{
        return down == 0;
    }

    Num operator+(const Num& rhs)const{
        long long commonDown = down * rhs.down;
        long long thisUp = up * rhs.down;
        long long rhsUp = rhs.up * down;
        long long tempUp = thisUp + rhsUp;
        long long tempDown = commonDown;
        Num ret(0);

        if(tempUp == 0){
            return ret;
        }

        long long div = gcd(abs(tempUp), abs(tempDown));

        ret.up = tempUp/ div;
        ret.down = tempDown/div;
            
        return ret;
    }

    Num operator-(const Num& rhs)const{
        long long commonDown = down * rhs.down;
        long long thisUp = up * rhs.down;
        long long rhsUp = rhs.up * down;
        long long tempUp = thisUp - rhsUp;
        long long tempDown = commonDown;

        Num ret(0);
        if(tempUp == 0){
            return 0;
        }


        long long div = gcd(abs(tempUp), abs(tempDown));

        ret.up = tempUp/ div;
        ret.down = tempDown/div;
            
        return ret;
    }

    Num operator*(const Num& rhs)const{
        long long tempUp =up* rhs.up; 
        long long tempDown = down * rhs.down;
        Num ret(0);

        if(tempUp == 0){
            return ret;
        }

        long long div = gcd(abs(tempUp), abs(tempDown));
        ret.up = tempUp/ div;
        ret.down = tempDown/div;
            
        return ret;
    }

    Num operator/(const Num& rhs)const{

        long long tempUp = up * rhs.down;
        long long tempDown = rhs.up * down;
        Num ret(0);

        if(tempUp == 0){
            return ret;
        }

        if(tempDown == 0){
            ret.down = 0;
            return ret;
        }

        long long div = gcd(abs(tempUp),abs(tempDown));
        ret.up = tempUp/ div;
        ret.down = tempDown/div;
            
        return ret;
    }

    bool is24(){
        return !isNan()&& up%down == 0 && up / down == 24;
    }
    Num op(int op, const Num& rhs){

        if(isNan() || rhs.isNan()){
            Num nan(0);
            nan.down = 0;
            return nan;
        }

        switch(op){
            case 0:{
                return (*this)+(rhs);
            }
            case 1:{
                return (*this)-(rhs);
            }
            case 2:{
                return (*this)*(rhs);
            }
            case 3:{
                return (*this)/(rhs);
            }
            default:{
                assert(false);
            }
        }
    }
};



class Solution {
public:
    bool judgePoint24(vector<int>& cards) {

        //insert 3 operator, and choose different priority to get result
        
        // +/*/ 0,1,2,3  4^3 
        int maxV = 4*4*4;
        for(int i = 0; i< maxV;++i){

            int div = i;
            

            array<int,3> operators;

            for(int i =0;i<3;++i){
                operators[i] = div % 4;
                div /= 4;
            }

            // 3 operator, different priority
            // 1,2,3
            // 1,3,2
            // 3,2,1
            
            {
                // 1,2,3
                Num res12 = Num(cards[0]).op(operators[0], Num(cards[1]));
                Num res123 = res12.op(operators[1], Num(cards[2]));
                Num res1234 = res123.op(operators[2],Num(cards[3]));

                if(res1234.is24()){
                    return true;
                }
            }

            {
                Num res12 = Num(cards[0]).op(operators[0], Num(cards[1]));
                Num res34 = Num(cards[2]).op(operators[2], Num(cards[3]));
                Num res1234 = res12.op(operators[1], res34);
                if(res1234.is24()){
                    return true;
                }
            }

            {
                Num res43 = Num(cards[2]).op(operators[2], Num(cards[3]));
                Num res432 = Num(cards[1]).op(operators[1], res43);
                Num res4321 = Num(cards[0]).op(operators[0],res432);
                if(res4321.is24()){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {4,1,8,7};
        assert(s.judgePoint24(input));
    }
{
        vector<int> input = {1,2,1,2};
        assert(!s.judgePoint24(input));
    }
}
