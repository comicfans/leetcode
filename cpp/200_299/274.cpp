#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(),citations.end());


        return recFind(citations, 0, citations.size());
        
    }

    int recFind(const vector<int>& citations, int begin, int end){

        if(begin == end){
            return 0;
        }

        if(end - begin == 1){
            int rightCount = citations.size()- begin;
            auto res = citations[begin];
            if(res < rightCount){
                return rightCount - 1;
            }else{
                return rightCount;
            }
        }


        int mid = (begin + end)/2;


        auto res = citations[mid];
        int rightCount = citations.size()- mid;
        // 0, 1, 3, 6, 5

        //find left most rightCount <= res
        if(rightCount <= res){
            return recFind(citations, begin, mid);
        }else{
            return recFind(citations,mid, end);
        }
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {3,0,6,1,5};
        assert(s.hIndex(input) == 3);
    }
    {
        vector<int> input = {1,3,1};
        assert(s.hIndex(input) == 1);
    }
}
