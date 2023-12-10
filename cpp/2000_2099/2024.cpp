#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        if(k>=answerKey.size()){
            return answerKey.size();
        }

        int tNumber = count(answerKey.begin(),answerKey.end(),'T');
        int nNumber = answerKey.size() - tNumber;
        if(k >= min(tNumber,nNumber)){
            return answerKey.size();
        }

        vector<int> rle;
        int prev = ' ';
        for(int i =0;i< answerKey.size();++i){
            if(answerKey[i] == prev){
                rle.back()++;
                continue;
            }else{
                rle.push_back(1);
                prev = answerKey[i];
                continue;
            }
        }

        int best = 0;

        int consumeIdx = 0;
        int sums[2] = {0};

        int reachEndTries = 0;
        for(int i = 0;i< rle.size();++i){

            sums[i%2] += rle[i];

            // consume at 0, should check sums[0]
            int testIdx = (consumeIdx % 2);

            bool notEnough = (sums[testIdx] > k);
            bool reachEnd = (i == (rle.size()-1));
            if(!notEnough && !reachEnd){
                continue;
            }
            //consume too much, traceback, connect part 
            //will switch

            if(notEnough){
                assert( (i - consumeIdx) % 2 == 0);
                sums[testIdx] -= rle[i];
            }

            int thisRes = sums[0]+sums[1];
            int leftCanExtend = 0;
            if(consumeIdx-2>=0){
                leftCanExtend = rle[consumeIdx-2]-1;
            }
            int rightCanExtend = rle[i];

            int fillLeftRight = min(leftCanExtend + rightCanExtend, k - sums[testIdx]);

            thisRes += fillLeftRight;
            best = max(thisRes, best);
            if(best == answerKey.size()){
                return best;
            }

            if(reachEnd){
                if(reachEndTries==1){
                    break;
                }else{
                    ++reachEndTries;
                }
            }

            ++consumeIdx;
            if(consumeIdx-2>=0){
                sums[consumeIdx%2] -= rle[consumeIdx-2];
                assert(sums[0]>=0);
                assert(sums[1]>=0);
            }
            --i;
            {
                //from consume index up to i (as exclusive end)
                //0-2-4 sum should be sum[0]
                //1-3-5 sum should be sum[1]
            }
            //int check0 = 0;
            //for(int j = consumeIdx-1;j <= i;j+=2){
            //    if(i>=0){
            //        check0 += rle[j];
            //    }
            //}
            //assert(check0 == sums[1-(consumeIdx % 2)]);
            //int check1 = 0;
            //for(int j = consumeIdx;j <= i;j+=2){
            //    if(j>=0){
            //        check1 += rle[j];
            //    }
            //}
            //assert(check1 == sums[consumeIdx %2]);
        }
        
        return best;
    }
};

int main(){
    Solution s;
    {
        string ans = "FFFTTFTTFT";
        assert(s.maxConsecutiveAnswers(ans,3) == 8);
    }
    {

        string ans = "TFTFFFTFTT";
        assert(s.maxConsecutiveAnswers(ans,6) == 10);
    }
    {
        string ans = "FFTFTFTFFT";
        assert(s.maxConsecutiveAnswers(ans,6) == 10);
    }
    
    {
        string ans = "TTFF";
        assert(s.maxConsecutiveAnswers(ans,2) == 4);
    }
    {
        string ans = "TFFT";
        assert(s.maxConsecutiveAnswers(ans,1) == 3);
    }
    {
        string ans = "TTFTTFTT";
        assert(s.maxConsecutiveAnswers(ans,1) == 5);
    }
    {
        string ans = "FTFFTFTFTTFTTFTTFFTTFFTTTTTFTTTFTFFTTFFFFFTTTTFTTTTTTTTTFTTFFTTFTFFTTTFFFFFTTTFFTTTTFTFTFFTTFTTTTTTF";
        assert(s.maxConsecutiveAnswers(ans,32) == 85);
    }
    
}
