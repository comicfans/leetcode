#include <vector>
#include <memory>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Comp{
    map<string,unique_ptr<Comp>> sub;

    string name;
    int hash;

    int insert(const vector<string>& path,int currentPos = 0){

        if(currentPos == path.size()){
            return 0;
        }

        assert(name == path[currentPos]);

        auto matchPos = sub.find(path[currentPos]);

        if(matchPos== sub.end()){
            matchPos = sub.insert({path[currentPos], unique_ptr<Comp>(new Comp())}).first;
        }

        int subRes = matchPos->second->insert(path, currentPos + 1);

        hash ^= std::hash<int>{}(subRes) + 0x9e3779b9 + (hash << 6) + (hash >> 2);

        return hash;
    }

    void collect(std::map<int, vector<string>>& res, vector<string>& parent){

    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {

       
        Comp root;

        for(auto &path : paths){
            root.insert(path);
        }

        std::map<int,vector<string>> hashDir;

        vector<string> parent;
        root.collect(hashDir,parent);
        
    }
};
