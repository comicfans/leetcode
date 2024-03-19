#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumDeletions(string word, int k) {

        map<char, int> charCount;
        for(auto c:word){
            charCount[c] ++;
        }

        vector<int> counts;
        for(auto kv: charCount){
            counts.push_back(kv.second);
        }

        sort(counts.begin(),counts.end());

        if(counts.empty() || (counts.back() - counts.front() <= k)){
            return 0;
        }

        return rec(counts, 0 , counts.size() - 1, k);
    }

    int rec(vector<int>& counts, int begin , int last, const int k){

        assert(begin <= last);
        if(counts[last] - counts[begin] <= k ){
            return 0;
        }

        //try 1. remove head
        int removeHead = rec(counts, begin+1, last, k) + counts[begin];

        
        int removeTail = INT_MAX;
        {
            
            //try 2, decrease last
            //
            int delta = counts[last] - (counts[begin] + k);
            assert(delta > 0);
            counts[last] -= delta;
            removeTail = delta;
            int subRes = rec(counts,begin, last - 1, k);
            counts[last] += delta;
            removeTail += subRes;
        }

        return min(removeHead, removeTail);
    }
};

int main(){
    Solution s;
    {
        string word = "vnnppvvbbn";
        int k = 0;
        auto res = s.minimumDeletions(word,k);
        assert(res == 2);
    }
    {
        string word = "ahahnhahhah";
        int k = 1;
        auto res = s.minimumDeletions(word,k);
        assert(res == 2);
    }
    {
        string word = "aabcaba";
        int k = 0;
        auto res = s.minimumDeletions(word,k);
        assert(res == 3);
    }
    {
        string word = "dabdcbdcdcd";
        int k = 2;
        auto res = s.minimumDeletions(word,k);
        assert(res == 2);
    }
    
}
