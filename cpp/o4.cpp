#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long beautifulSubstrings(string s, int k) {

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
        long long res = 0;
        
        for(auto beginAe = 0;beginAe < aeiouIdx.size(); ++ beginAe){
            for(auto endAe = beginAe;endAe< aeiouIdx.size();++endAe){

                int aeCount = endAe - beginAe + 1;

                if(aeCount* aeCount %k != 0){
                    continue;
                }

                int inbetweenNormal = max(aeiouIdx[endAe] - aeiouIdx[beginAe]+1-aeCount, 0);
                if(inbetweenNormal > aeCount){
                    continue;
                }
                
                if(inbetweenNormal == aeCount){
                    res+= 1;
                    continue;
                }




                //try left possible 
                //
                int possible = aeCount;

                int leftNormalBegin = aeiouIdx[beginAe] - aeCount+inbetweenNormal;

                if(beginAe==0){
                    leftNormalBegin = max(leftNormalBegin, 0);
                }else{
                    leftNormalBegin = max(aeiouIdx[beginAe-1]+1 , leftNormalBegin);
                }

                int rightNormalEnd = aeiouIdx[endAe] + aeCount - inbetweenNormal;
                if(endAe == aeiouIdx.size()-1){
                    rightNormalEnd =  min<int>(rightNormalEnd, s.size()-1);
                }else{
                    rightNormalEnd = min<int>(rightNormalEnd, aeiouIdx[endAe+1]-1);
                }

                
                int totalLength = rightNormalEnd - leftNormalBegin + 1;
                int thisCan = max(totalLength+1 - aeCount * 2,0);


                res+= thisCan;
            }
        }
        

        return res;
    }
};

int main(){
    Solution s;
    {
        string a = "uzuxpzou";
        assert(s.beautifulSubstrings(a,3)==1);
    }
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
