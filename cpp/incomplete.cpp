#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    public:

        bool strip2(vector<int>& lhs,vector<int>& rhs){

            vector<int>& removeHeadOne=lhs;
            vector<int>& keepHeadOne=rhs;
            bool removeHead=false;
            int head;
            if (lhs.front()<rhs.front()) {
                removeHead=true;
                removeHeadOne=lhs;
                keepHeadOne=rhs;
                head=rhs.front();
            }else if(lhs.front()>rhs.front()){
                removeHead=true;
                removeHeadOne=rhs;
                keepHeadOne=lhs;
                head=lhs.front();
            }
            
            bool changed=false;

            if (removeHead) {
                vector<int>::iterator pos1= lower_bound(removeHeadOne.begin(),removeHeadOne.end(),head);

                if (pos1==removeHeadOne.end()) {
                    int oldKeepSize=keepHeadOne.size();
                    keepHeadOne.resize(1);
                    if (oldKeepSize!=1) {
                        changed=true;
                    }
                    removeHeadOne[0]=removeHeadOne.back();
                    int oldRemoveSize=removeHeadOne.size();
                    removeHeadOne.resize(1);
                    if (oldRemoveSize!=1) {
                        changed=true;
                    }

                    return changed;
                }

                if(pos1-1>removeHeadOne.begin()){
                    changed=true;
                    vector<int> newRemoveHeadOne(pos1,removeHeadOne.end());
                    removeHeadOne.swap(newRemoveHeadOne);
                }
            }


            int lhsBack=lhs.back();
            int rhsBack=rhs.back();

            bool removeTail=false;
            vector<int> &
            if (lhsBack<rhsBack) {
                
            }



        }

        void strip(vector<vector<int> >& nums){

            bool changed=false;

            while(true)
            {
                for (size_t i = 1; i < nums.size(); ++i) {

                    vector<int> &prevLayer=nums[i-1];
                    bool stripped=strip2(prevLayer,nums[i]);
                    if (stripped) {
                        changed=true;
                    }
                }

                if (!changed) {
                    return;
                }
            }
        }

        vector<int> smallestRange(vector<vector<int> >& nums) {

            vector<int> &firstLayer=nums[0];

            firstLayer.resize(unique(firstLayer.begin(),firstLayer.end())-firstLayer.begin());


            vector<pair<int,int> > prevLayerMin(firstLayer.size());
            for(size_t i=0;i<firstLayer.size();++i){
                prevLayerMin[i]=make_pair(firstLayer[i],firstLayer[i]);
            }

            for (size_t i = 1; i < nums.size(); ++i) {

                vector<int> &thisLayer=nums[i];
                thisLayer.resize(unique(thisLayer.begin(),thisLayer.end())-thisLayer.begin());
                vector<pair<int,int> > thisLayerMin(thisLayer.size());

                for (size_t k = 0;  k < thisLayer.size(); ++k) {

                    int value=thisLayer[k];
                    
                }
                
                prevLayerMin.swap(thisLayerMin);
            }

            pair<int,int> best(-1000000,1000000);

            vector<int> &lastLayer=nums.back();
            for(size_t i=0;i<lastLayer.size();++i){
                pair<int,int> thisTry1(prevLayerMin[i].first,lastLayer[i]);
                pair<int,int> thisTry2(lastLayer[i] ,prevLayerMin[i].second);

                if (better(thisTry1,best)) {
                    best=thisTry1;
                }

                if (better(thisTry2,best)) {
                    best=thisTry2;
                }

            }

            vector<int> res;

            res.push_back(best.first);
            res.push_back(best.second);
            return res;

        }

    private: 

        pair<int,int> best;

        static bool better(pair<int,int> lhs, pair<int,int> rhs){
            int lhsRange=lhs.second-lhs.first;
            int rhsRange=rhs.second-rhs.first;
            if (lhsRange<rhsRange) {
                return true;
            }

            if ((lhsRange==rhsRange)&&(lhs.first<rhs.first) ) {
                return true;
            }

            return false;

        }


};

#define ARRAY(n) vector<int>(n,n+sizeof(n)/sizeof(int))

int main(int argc, char *argv[])
{
    Solution s;



    int 
        num0[]={5,42,43,48,54,64,65},
        num1[]={19,20,32,32,32,33},
        num2[]={6,24,42,49,53,58,58,59},
        num3[]={6,14,28,28,34},
        num4[]={2,39,45,46,49,50},
        num5[]={7,23,23,28,43,44,44,44,44,44,44,44,44,44,44,44,44,45},
        num6[]={70,75,77,87,97,99,99,99,100},
        num7[]={-44,7,20,20,25},
        num8[]={-3,39,62,72,72,73},
        num9[]={-5,13,15,20},
        num10[]={-18,-4,37,61,64},
        num11[]={0,10,17,35,38,41},
        num12[]={42,58,83,86,89,92,100},
        num13[]={-7,15,16},
        num14[]={-9,83,99},
        num15[]={-75,16,24,52,61,93,94,97,97,99,99,100},
        num16[]={37,42,49,56},
        num17[]={-69,92,93,95,95,95,96};
    /*  
    int num0[]={4,10,15,24,26},
        num1[]={0,9,12,20},
        num2[]={5,18,22,30};
        */


    vector<vector<int> > nums;

    nums.push_back(ARRAY(num0));
    nums.push_back(ARRAY(num1));
    nums.push_back(ARRAY(num2));
    nums.push_back(ARRAY(num3));
    nums.push_back(ARRAY(num4));
    nums.push_back(ARRAY(num5));
    nums.push_back(ARRAY(num6));
    nums.push_back(ARRAY(num7));
    nums.push_back(ARRAY(num8));
    nums.push_back(ARRAY(num9));
    nums.push_back(ARRAY(num10));
    nums.push_back(ARRAY(num11));
    nums.push_back(ARRAY(num12));
    nums.push_back(ARRAY(num13));
    nums.push_back(ARRAY(num14));
    nums.push_back(ARRAY(num15));
    nums.push_back(ARRAY(num16));
    nums.push_back(ARRAY(num17));


    auto res=s.smallestRange(nums);

    cout<<res[0]<<","<<res[1]<<endl;
    
    return 0;
}
