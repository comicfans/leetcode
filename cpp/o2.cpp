#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int beautifulSubstrings(string s, int k) {

        vector<int> aeiouIdx;
        string aeiouStr = "aeiou";
        for(int i =0;i< s.size();++i){
            if(aeiouStr.find(s[i])!= string::npos){
                aeiouIdx.push_back(i);
            }
        }

        if(aeiouIdx.empty()){
            return 0;
        }
        //  0, 1, 2, 3

        int leftMost = max<int>(aeiouIdx[0] - aeiouIdx.size(),0);
        int rightMost = min(aeiouIdx.back() + aeiouIdx.size(), s.size()-1);
        int res = 0;
        for(int tryLeft = leftMost; tryLeft <= aeiouIdx.back(); ++tryLeft){
            for(int tryRight=tryLeft + 1;tryRight <= rightMost;tryRight+=2){

                auto inAeBegin = lower_bound(aeiouIdx.begin(),aeiouIdx.end(),tryLeft);
                int leftAeCount = inAeBegin - aeiouIdx.begin();



                auto inAePos = lower_bound(aeiouIdx.begin(),aeiouIdx.end(),tryRight);
                //how many ae in it
                int aeCount = inAePos - aeiouIdx.begin();
                if(inAePos!=aeiouIdx.end()){
                    if(*inAePos == tryRight){
                        ++aeCount;
                    }
                }

                aeCount -= leftAeCount;

                int normal = tryRight - tryLeft+1 - aeCount ; 
                
                if((normal == aeCount) && (normal * normal % k == 0)){
                    ++res;
                }
            }
        }
        

        return res;
    }
};

int main(){
    Solution s;
{
        string a = "ouuoeqd";
        assert(s.beautifulSubstrings(a,2) == 1);
    }
    {
        string a="baeyh";
        assert(s.beautifulSubstrings(a,2) == 2);
    }
    {
        string a="abba";
        assert(s.beautifulSubstrings(a,1) == 3);
    }
    {
        string a="bcdf";
        assert(s.beautifulSubstrings(a,1) == 0);
    }
    
}
