#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


string map1[]= {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};

string map10[] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

class Solution {
public:
    string numberToWords(int num) {

        if(num == 0){
            return "Zero";
        }


        

        string ret;
        recConstruct9(num, ret);
        
        return ret;
    }

    void recConstruct9(int num, string& toAppend){

        int bil =num / 1000/1000/1000;
        if(bil > 0){
            recConstruct6(bil, toAppend);
            toAppend += " Billion";
        }

        num = num - bil * 1000 * 1000 * 1000;
        recConstruct6(num, toAppend);
    }

    void recConstruct6(int num, string& toAppend){
        assert(num < 1000000000);
        int mill = num / 1000/1000;

        if(mill>0){
            recConstruct3(mill, toAppend);
            toAppend += " Million";
        }

        num = num  - mill * 1000000;

        recConstruct3(num, toAppend);

    }

    void recConstruct3(int num, string& toAppend){
        assert(num < 1000000);

        int thsound = num / 1000;
        if(thsound>0){
            recConstruct2(thsound, toAppend);
            toAppend += " Thousand";
        }

        num = num - thsound * 1000;
        recConstruct2(num,toAppend);
    }

    void recConstruct2(int number, string& toAppend){
        assert(number < 1000);

        int hund = number / 100;

        if(hund > 0){
            if(!toAppend.empty()){
                toAppend+=" ";
            }

            toAppend+= (map1[hund] +" Hundred");
        }

        int tens = number - hund * 100;

        if(tens >= 20){
            auto tensStr = map10[tens / 10];
            if(!toAppend.empty()){
                toAppend.push_back(' ');
            }

            int tensV = tens/ 10;
            toAppend += map10[tensV];

            int left = tens - (tens/10) * 10;
            if(left){

                if(!toAppend.empty()){
                    toAppend.push_back(' ');
                }

                toAppend+=map1[left];
            }

            return ;
        }

        if(tens){
            if(!toAppend.empty()){
                toAppend.push_back(' ');
            }
            toAppend += map1[tens];
        }


    }
    
};

int main(){
    Solution s;
    {
        auto res =s.numberToWords(123);
        assert(res=="One Hundred Twenty Three");
    }
    {
        auto res =s.numberToWords(12345);
        assert(res == "Twelve Thousand Three Hundred Forty Five");
    }
    {
        auto res = s.numberToWords(1234567);
        assert(res == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    }
    {
        auto res = s.numberToWords(1234567891);
        assert(res == "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");
    }
    {
        auto res = s.numberToWords(17);
        assert(res == "Seventeen");
    }
}
