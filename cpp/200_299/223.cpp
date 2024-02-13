#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
       int xOverlap = min(ax2,bx2) - max(ax1,bx1);
       int yOverlap = min(ay2,by2) - max(ay1,by1);

       if(xOverlap <=0 || yOverlap <= 0){
           return (ax2-ax1) * (ay2-ay1) + (bx2-bx1) * (by2 - by1);
       }   

       int overlapArea = xOverlap * yOverlap;

       return  (ax2-ax1) * (ay2-ay1) + (bx2-bx1) * (by2 - by1) - overlapArea;
    }
};
