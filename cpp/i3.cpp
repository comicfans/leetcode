#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    long long countN(const vector<int>& nums, 
                     const vector<int>& maxIdx,
                     const int fromC,
                     const int toC){

        if(fromC > toC){
            return 0;
        }

        long long ret = 0;
        for(int inc = fromC; inc <= min<int>(toC,maxIdx.size()); ++inc){

            for(int i=0; i<= maxIdx.size() - inc;++i){

                int leftIdx = maxIdx[i];
                int rightIdx = maxIdx[i+inc-1];

                long long leftFree = (i == 0?
                                      (leftIdx+1):
                                      (leftIdx - maxIdx[i - 1]));

                long long rightFree = (i+inc-1 == maxIdx.size()-1?
                                       (nums.size() - rightIdx):
                                       (maxIdx[i+inc] - rightIdx));

                long long poss = leftFree * rightFree;

                ret += poss;
            }
        }
        return ret;
    }

    long long count0(const vector<int>& nums, 
                     const vector<int>& maxIdx){

        long long ret = 0;

        for(int i= 0;i<maxIdx.size();++i){

            long long leftFree = (i==0?maxIdx[i]:maxIdx[i] - maxIdx[i-1] - 1);

            int poss = (1+leftFree) * leftFree / 2;

            ret += poss;
        }

        long long rightFree = nums.size() - maxIdx.back() - 1;
        int poss = (1+rightFree) * rightFree / 2;
        ret += poss;


        return ret;
    }


    long long countSubarrays(vector<int>& nums, int k) {
        
        int firstMax = -1;
        int lastMax = -1;
        int maxValue = -1;
        vector<int> maxIdx ;

        if(k> nums.size()){
            return 0;
        }

        for(int i = 0;i<nums.size();++i){

            int thisV = nums[i];
            if(thisV > maxValue ){
                firstMax = i;
                lastMax = i;
                maxValue = thisV;
                maxIdx.clear();
                maxIdx.push_back(i);
                continue;
            }

            if(thisV == maxValue){
                lastMax = i;
                maxIdx.push_back(i);
                continue;
            }

        }


        long long res = 0;
        for(int left = 0; left<= (int)maxIdx.size()-k;++left){

            int mul = left == 0?(maxIdx[left]+1):(maxIdx[left] - maxIdx[left-1]);


            int rightMin = left + k -1;

            long long thisRes = nums.size() - maxIdx[rightMin] ;

            thisRes *= mul;

            res += thisRes;
        }

        return res;

        //if(k > maxIdx.size() / 2){
        //    long long res = countN(nums,maxIdx,k,maxIdx.size());
        //    return res;
        //}


        //long long total = (1 + nums.size()) * nums.size() / 2;


        //long long size0 = count0(nums,maxIdx);
        //long long remove = countN(nums,maxIdx,1, k-1);


        //long long ret = total - size0 - remove;
        //return ret; 


    }
};

int main(){
    Solution s;
    {
        vector<int> input = {1,3,2,3,3};
        assert(s.countSubarrays(input,2)==6);
    }
    {
        vector<int> input = {1,4,2,1};
        assert(s.countSubarrays(input,3)==0);
    }
}
