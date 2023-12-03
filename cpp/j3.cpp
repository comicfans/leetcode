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


        for(int begin= 0;begin <= word.size()-k;++begin){

            map<char,int> times;

            bool jumpBegin = false;
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

                //string str = word.substr(begin,end - begin);
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
                }

                if(jumpBegin){
                    break;
                }
                
                //if(ok){
                    //cout<<word.substr(begin,end - begin)<<endl;
                //}

                ret += ok;
            }
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        string i ="fffififmfhhmihhifhifzhihizfmmffihzfifmfmizzfzfhmfmiimzffzzifzmziiizfzmfzfiiffffmhiizimmfm";
        assert(s.countCompleteSubstrings(i,2) == 20);

    }
    {

        string i = "igigee";
        assert(s.countCompleteSubstrings(i,2) ==3);

    }
    {
        string i = "aaabbbccc";
        assert(s.countCompleteSubstrings(i,3) ==6);
    }
}
