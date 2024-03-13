#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>



using namespace std;
class Solution {
public:
    string originalDigits(string s) {

        vector<string> eng = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        // n0 * zero + n1 * one .... n9 * nine = input
        //
        //n0*Z  =   z of input ---------------->0
        //(n0 + n1 + 2*n3 + n5 + 2*n7 + n8 + n9)   e  = e of input
        //(n0 + n3 + n4 ) r  =   r of input -------------->3 by (0,4)
        //(n0+n1+n2+n4) o = o -------------------> 1 by (0,2,4)
        //(n1 + n7 + 2*n9) n = n ----------------> 9 by (1,7)
        //(n2 + n3 + n8) * t = t  ------------------------>3 by (2,8)
        //(n2) w = w ------------------------->2
        //(n3+n8)h = h  ---------------------------------> 3 by 8
        //(n3+n4)r = r-----------------------------------> 3 by 4
        //(n4+n5)f = f----------------------------------> 5 by 4
        //(n4) u = u ------------------------->4
        //(n5+n6+n8+n9) i-----------------------------------
        //(n5+n7) v ------------------------------------------------------> 5 by7
        //(n6+n7) s ------------------------------------------->7 by 6
        //(n6) x -----------------------------> 6
        //(n8)g  -----------------------------> 8
        vector< map<char, int>> charCounts(10);

        set<char> allChar ;

        for(int i = 0; i<10;++i){
            for(auto c: eng[i]){
                charCounts[i][c]++;
                allChar.insert(c);
            }
        }

        map<char, int> input;
        for(auto c: s){
            input[c]++;
        }
        vector<vector<int>> mul(allChar.size(), vector<int>(10));
        int row= 0;
        for(auto c: allChar){
            for(int i = 0; i< 10; ++i){
                mul[row][i] = charCounts[i][c];
            }
            ++row;
        }

        auto pos = allChar.begin();
        //for(int i =0;i< allChar.size(); ++i){
        //    cout<< *pos <<": ";
        //    copy(mul[i].begin(),mul[i].end(), ostream_iterator<int>(cout,","));
        //    cout<<endl;
        //    ++pos;
        //}
        
        // now
        //   0,1,2,3,4,5,6,7,8,9    
        //   -------------------
        //e: 1,1,0,2,0,1,0,2,1,1,
        //f: 0,0,0,0,1,1,0,0,0,0,
        //g: 0,0,0,0,0,0,0,0,1,0,
        //h: 0,0,0,1,0,0,0,0,1,0,
        //i: 0,0,0,0,0,1,1,0,1,1,
        //n: 0,1,0,0,0,0,0,1,0,2,
        //o: 1,1,1,0,1,0,0,0,0,0,
        //r: 1,0,0,1,1,0,0,0,0,0,
        //s: 0,0,0,0,0,0,1,1,0,0,
        //t: 0,0,1,1,0,0,0,0,1,0,
        //u: 0,0,0,0,1,0,0,0,0,0,
        //v: 0,0,0,0,0,1,0,1,0,0,
        //w: 0,0,1,0,0,0,0,0,0,0,
        //x: 0,0,0,0,0,0,1,0,0,0,
        //z: 1,0,0,0,0,0,0,0,0,0,

        vector<int> count(10,-1);
        //iterate to find row that only has one variable unknown

        int rr = 0;
        for(auto chPos = allChar.begin(); chPos != allChar.end(); ++chPos ,++rr){
            if(input.count(*chPos) == 0){
                for(int i = 0; i< 10 ; ++i){
                    if(mul[rr][i]!=0){
                        count[i] = 0;
                    }
                }
            }
        }
        while(true){



            bool foundOne = false;
            auto charPos = allChar.begin();
            for(int row = 0;row < mul.size(); ++row, ++charPos){

                auto ch= *charPos;
                const auto& thisRow = mul[row];
                if(!input.count(ch)){
                    continue;
                }

                assert(input[ch]!=0);

                int unknownNumber = 10;

                int knownSum = 0;
                int unknownV = -1;
                for(int i = 0;i <10; ++i){
                    if(thisRow[i] == 0){
                        //coef is zero
                        --unknownNumber;
                    }else if(count[i] != -1){
                        knownSum += count[i] * thisRow[i];
                        --unknownNumber;
                    }else{
                        unknownV = i;
                    }
                }

                if(unknownNumber != 1){
                    continue;
                }

                //unknown number = 1
                int right = input.at(ch) - knownSum;

                assert(right % thisRow[unknownV] == 0);
                count[unknownV] = right / thisRow[unknownV];
                foundOne = true;
                break;
            }

            if(!foundOne){
                break;
            }
        }

        string ret;
        for(int i = 0; i< 10; ++i){
            if(count[i] == -1 || count[i] == 0){
                continue;
            }

            ret+= string(count[i],i+'0');
        }

        return ret;

    }

    


};

int main(){
    Solution s;
    {
        string input = "neo";
        auto res = s.originalDigits(input);
        assert(res== "1");
    }
    {
        string input = "owoztneoer";
        auto res = s.originalDigits(input);
        assert(res== "012");
    }
}
