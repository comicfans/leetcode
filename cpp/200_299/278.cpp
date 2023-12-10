#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return recFind(1,n);
    }

    int recFind(int begin, int end){

        if( begin == end){
            return end;
        }

        if(begin == end - 1){
            if(isBadVersion(begin)){
                return begin;
            }else{
                return end;
            }

        }


        int mid = ((long long)begin + (long long)end) / 2;
        
        

        if(isBadVersion(mid)){
            return recFind(begin, mid);
        }

        return recFind(mid, end);
    }

    int bad;

  
};
