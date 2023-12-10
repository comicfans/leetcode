#include <limits>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        if(node1==node2){
            return node1;
        }

        vector<array<int,2>> length12(edges.size(), array<int,2>{numeric_limits<int>::max(),numeric_limits<int>::max()});
        


        walk(edges, node1,length12,0);
        walk(edges, node2,length12,1);

        int bestIdx = -1;
        int bestMax = numeric_limits<int>::max();


        for(int i =0;i< length12.size();++i){
            auto p = length12[i];
            int thisRes = max(p[0],p[1]);

            if(thisRes < bestMax){
                bestIdx = i;
                bestMax = thisRes;
            }
            
        }

        return bestIdx;
    }

    void walk(vector<int>& edges, int root, vector<array<int,2>>& length12,int idx ){

        int step = 0;
        while(true){

            if(length12[root][idx]!=numeric_limits<int>::max()){
                return;
            }

            length12[root][idx]             = step;

            root = edges[root];
            if(root == -1){
                return;
            }

            ++step;
        }
    }
};

int main(){
    Solution s;
    {
        vector<int> edges = {2,2,3,-1};
        int node1 = 0, node2 = 1;
        assert(s.closestMeetingNode(edges,node1,node2) == 2);
    }
    {
        vector<int> edges = {1,2,-1};
        int node1 = 0, node2 = 2;
        assert(s.closestMeetingNode(edges,node1,node2)== 2);
    }
    {
        vector<int> edges = {4,3,0,5,3,-1};
        assert(s.closestMeetingNode(edges,4,0)== 4);
    }

}
