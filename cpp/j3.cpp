#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {


        int ret = 0;


        bool foundOk = false;
        bool firstTime = true;

        for(int begin= 0;begin <= word.size()-k;++begin){


            bool jumpBegin = false;

            map<char,int> times;
           for(int i = 0;i<k;++i){
                times[word[i+begin]]++;

                if(i>0){
                    if(abs(word[begin + i] - word[begin+i-1]) > 2){
                        jumpBegin = true;
                        break;
                    }
                }
            }
            


            if(jumpBegin){
                continue;
            }


            for(int end = begin+k;end <= word.size();++end){

                //if(str == "hifhif"){
                //    int a = 4;
                //}

                if(end - begin != k){
                    times[word[end - 1]]++;
                    // new add

                    if(abs(word[end - 1] - word[end-2])>2){
                        jumpBegin = true;
                        break;
                    }

                }



                //test if adjust

                int prev = times.begin()->first;

                if(!foundOk){

                bool ok = true;
                for(auto kv: times){
                    if(kv.second > k){
                        jumpBegin = true;
                        ok = false;
                        break;
                    }
                    if(kv.second < k){
                        ok = false;
                        break;
                    }
                        prev = kv.first;
                }
                    foundOk = ok;
                }else{
                    //just check this
                    if(times[word[end-1]]!= k){
                        foundOk=false;
                    }
                }

                if(jumpBegin){
                    break;
                }
                

                ret += foundOk;
            }
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    
    {

        string i = "igigee";
        assert(s.countCompleteSubstrings(i,2) ==3);

    }
    {
        string i = "aaabbbccc";
        assert(s.countCompleteSubstrings(i,3) ==6);
    }
    {
        string i ="fffififmfhhmihhifhifzhihizfmmffihzfifmfmizzfzfhmfmiimzffzzifzmziiizfzmfzfiiffffmhiizimmfm";
        assert(s.countCompleteSubstrings(i,2) == 20);

    }
}
