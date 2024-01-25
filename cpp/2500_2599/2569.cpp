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
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

        vector<long long> ret;


        int lastType3 = -1;
        for(int i=0;i<queries.size();++i){
            if(queries[i].front()==3){
                lastType3 = i;
            }
        }



        for(int idx = 0;idx <= lastType3 ;++idx){
            const auto& q= queries [idx];

            if(q.front()==1){
                int to = min<int>(q[2], nums1.size()-1);
                for(int i = max(q[1],0);i<=to;++i){
                    nums1[i] = 1 - nums1[i];
                }
                continue;
            }

            if(q.front() == 2){
                for(int i = 0;i< nums2.size();++i){
                    nums2[i] = nums2[i] + nums1[i] * q[1];
                }
                continue;
            }

            if(idx!=0 && (queries[idx-1].front()==3)){
                ret.push_back(ret.back());
                continue;
            }

            auto type3 = accumulate(nums2.begin(),nums2.end(),(long long)0);
            ret.push_back(type3);
        }
        return ret;
        
    }
};
