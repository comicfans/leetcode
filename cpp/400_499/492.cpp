#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> constructRectangle(int area) {

        double tryValue = sqrt(area);

        int w = (int)tryValue;

        do {

            if(area % w == 0){
                return {area / w, w};
            }

            --w;

        } while(true);

        return vector<int>{area, 1};
    }
};

int main(){
    Solution s;
    {
        auto res = s.constructRectangle(37);
    }
}
