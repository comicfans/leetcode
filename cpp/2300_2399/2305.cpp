#include <limits>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        //try to find k group, min the max group

        sort(cookies.begin(),cookies.end());

        int total = accumulate(cookies.begin(), cookies.end(), 0);


        vector<int> groups;
        int best = numeric_limits<int>::max();
        recFind(cookies, k,groups, true, best, total, 0);
        return best;

    }

    void recFind(vector<int>& cookies, int k, vector<int>& groups, bool newGroup,int& best,int leftTotal,int lastTryValue){

        if(k == 0){
            if(cookies.empty()){
                auto pos = max_element(groups.begin(),groups.end());
                best = min(best, *pos);
                return;
            }else{
                // have cookies left, can't satisfy
                return;
            }
        }

        if(cookies.empty()){
                auto pos = max_element(groups.begin(),groups.end());
                best = min(best, *pos);
                return;
        }

        if(!groups.empty() && groups.back()> best){
            return;
        }
        
        if(newGroup){
            //pick larget one from cookie
            int maxGroupMean = int(double(leftTotal +  k - 1) / k);

            assert(!cookies.empty());
            int newGroup = cookies.back();
            cookies.pop_back();
            groups.push_back(newGroup);
            assert(newGroup<=best);

            recFind(cookies,k,groups,false,best, leftTotal - newGroup, 0);

            groups.pop_back();
            cookies.push_back(newGroup);
            return;
        }

        // test if we need to add to existing group

        int toSplit = leftTotal + groups.back();
        int mean = (toSplit + k - 1)/ k;

        if(mean > best){
            return;
        }

        int delta = mean - groups.back();
        if(delta == 0){
            recFind(cookies,k-1,groups,true,best,leftTotal, 0);
            return;
        }

        auto deltaPos = lower_bound(cookies.begin(),cookies.end(), delta);

        if((deltaPos != cookies.end())&&(*deltaPos == delta)){
            groups.back()+=delta;
            cookies.erase(deltaPos);
            recFind(cookies, k-1,groups,true,best,leftTotal - delta, 0);
            cookies.insert(deltaPos, delta);
            groups.back()-=delta;
            return;
        }

        recFind(cookies,k-1,groups,true,best,leftTotal,0);

        auto deltaIndex = deltaPos - cookies.begin();
        
        auto tryLowerPos = lower_bound(cookies.begin(),cookies.end(), lastTryValue);
        auto tryLowerIndex = tryLowerPos - cookies.begin();
        //not same
        

        for(int idx =  tryLowerIndex;idx  <= min<int>(deltaIndex, cookies.size()-1);++idx){
            int thisValue = cookies[idx];
            groups.back()+=thisValue;
            cookies.erase(cookies.begin()+idx);
            recFind(cookies,k,groups,false,best,leftTotal - thisValue,thisValue);
            cookies.insert(cookies.begin()+idx, thisValue);
            groups.back()-= thisValue;
        }

    }


};

int main(){

    Solution s;
    {
        vector<int> cookies ={8,15,10,20,8};
        assert(s.distributeCookies(cookies,2)==31);
    }
    {
        vector<int> cookies ={6,1,3,2,2,4,1,2};
        assert(s.distributeCookies(cookies,3)==7);
    }
    {
        vector<int> cookies = {20,13,18};
        assert(s.distributeCookies(cookies,2) == 31);
    }
    {
        vector<int> cookies = {15,18,19,5,6,13,15,20};
        assert(s.distributeCookies(cookies,3) == 38);
    }
}
