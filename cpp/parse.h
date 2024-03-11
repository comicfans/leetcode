#include<vector>
#include<algorithm>
#include<sstream>
#include<memory>
#include<cassert>
#include<fstream>
#include<string>

using namespace std;
vector<double> pvd(const std::string& v){

    vector<double> ret;

    int prevStart = -1;
    for(int i=0;i<v.size();++i){

        if((v[i] == '[') || (v[i] == ' ')){
            continue;
        }

        if((v[i] == ']') || (v[i] == ',')){
            stringstream ss;
            ss<< v.substr(prevStart, i-prevStart);
            double value;
            ss>>value;
            ret.push_back(value);
            prevStart = -1;
            continue;
        }

        if(prevStart == -1){
            prevStart = i;
            continue;
        }
    }


    return ret;
}
vector<int> pvi(const std::string& v){

    vector<int> ret;

    int prevStart = -1;
    for(int i=0;i<v.size();++i){

        if((v[i] == '[') || (v[i] == ' ')){
            continue;
        }

        if((v[i] == ']') || (v[i] == ',')){

            if(prevStart == -1){
                break;
            }

            stringstream ss;
            ss<< v.substr(prevStart, i-prevStart);
            int value;
            ss>>value;
            ret.push_back(value);
            prevStart = -1;
            continue;
        }

        if(prevStart == -1){
            prevStart = i;
            continue;
        }
    }


    return ret;
}

vector<string> pvs(const std::string& v){

    vector<string> ret;

    int prevStart = -1;
    for(int i=0;i<v.size();++i){
        if(((v[i] == '"') && (prevStart != -1))){
            ret.push_back(v.substr(prevStart, i-prevStart));
            prevStart = -1;
            continue;
        }
        if((v[i] == '[') || (v[i] == ' ') || (v[i] == '"' && prevStart == -1)||(v[i] == ',')){
            continue;
        }

        

        if(prevStart == -1){
            prevStart = i;
            continue;
        }
    }


    return ret;
}

vector<vector<string>> pvvs(const std::string& v){

    vector<vector<string>> ret;

    for(int i = 1;i< v.size();){
        
        if(v[i] == '['){
            int closePos = v.find(']',i+1);
            assert(closePos != string::npos);
            ;
            auto sub = pvs(v.substr(i, closePos-i+1));
            i = closePos + 2;
            continue;
        }
    }

    return ret;
}

vector<vector<double>> pvvd(const std::string& v){

    vector<vector<double>> ret;

    for(int i = 1;i< v.size();){
        
        if(v[i] == '['){
            int closePos = v.find(']',i+1);
            assert(closePos != string::npos);
            ;
            auto sub = pvd(v.substr(i, closePos-i+1));
            i = closePos + 2;
            continue;
        }
    }

    return ret;
}

vector<vector<int>> pvvi(const std::string& v){

    vector<vector<int>> ret;

    for(int i = 1;i< v.size();){
        
        if(v[i] == '['){
            int closePos = v.find(']',i+1);
            assert(closePos != string::npos);
            ;
            auto sub = pvi(v.substr(i, closePos-i+1));
            ret.push_back(sub);
            i = closePos + 2;
            continue;
        }
    }

    return ret;
}

vector<int> pvi(const std::string file,int lineno){

    ifstream f(file);

    std::string line;
    int i= 0;
    while(getline(f, line)){
        if ( i == lineno){
            break;
        }
        ++i;
    }

    return pvi(line);

}

vector<string> pvs(const std::string file,int lineno){

    ifstream f(file);

    std::string line;
    int i= 0;
    while(getline(f, line)){
        if ( i == lineno){
            break;
        }
        ++i;
    }

    return pvs(line);
}
vector<double> pvd(const std::string file,int lineno){

    ifstream f(file);

    std::string line;
    int i= 0;
    while(getline(f, line)){
        if ( i == lineno){
            break;
        }
        ++i;
    }

    return pvd(line);
}

vector<vector<double>> pvvd(const std::string file,int lineno){

    ifstream f(file);

    std::string line;
    int i = 0;
    while(getline(f, line)){
        if ( i== lineno){
            break;
        }
        ++i;
    }

    return pvvd(line);

}

vector<vector<string>> pvvs(const std::string file,int lineno){

    ifstream f(file);

    std::string line;
    int i = 0;
    while(getline(f, line)){
        if ( i== lineno){
            break;
        }
        ++i;
    }

    assert(f.good());
    return pvvs(line);

}

vector<vector<int>> pvvi(const std::string file,int lineno){

    ifstream f(file);

    std::string line;
    int i = 0;
    while(getline(f, line)){
        if ( i== lineno){
            break;
        }
        ++i;
    }

    assert(f.good());
    return pvvi(line);

}

int pi(const std::string s){
    stringstream line(s);
    int i;
    line>>i;
    return i;
}

int pi(const std::string file, int lineno){
    ifstream f(file);

    std::string line;
    int i = 0;
    while(getline(f, line)){
        if ( i== lineno){
            break;
        }
        ++i;
    }

    return pi(line);

}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }
};

vector<string> pin(const string& tree){
    assert(tree.front()=='[');
    assert(tree.back()==']');

    int pos = 1;

    vector<string> ret;
    while(pos < tree.size()-1){
        int nextPos = find(tree.begin()+pos, tree.end()-1,',') - tree.begin();
        ret.push_back(tree.substr(pos, nextPos - pos));
        pos = nextPos+1;
    }

    return ret;
}

void recConstructTree(TreeNode* root, const vector<string>& strs, int rootNode, vector<TreeNode*>& vec){


    // 0
    // 1,   2
    // 3,   4     5,6
    // 7,8  9,10  11,12, 13,14
    int lNode = rootNode * 2 + 1;

    if(lNode< strs.size() && strs[lNode]!= "null"){
        root->left = new TreeNode(atoi(strs[lNode].c_str()));
        vec[lNode] = root->left;
        recConstructTree(root->left, strs, lNode,vec);
    }
    
    int rNode = lNode +1;
    if(rNode < strs.size() && strs[rNode]!= "null"){
        root->right = new TreeNode(atoi(strs[rNode].c_str()));
        vec[rNode] = root->right;
        recConstructTree(root->right, strs,rNode,vec);
    }
}

std::pair<std::unique_ptr<TreeNode>, vector<TreeNode*>> pt(const string& tree){

    auto strs = pin(tree);
    vector<TreeNode*> vec(strs.size());

    if(strs.empty() || strs.front() == "null"){
        return {nullptr,vec};
    }

    unique_ptr<TreeNode> root(new TreeNode(atoi(strs.front().c_str())));

    recConstructTree(root.get(), strs, 0,vec);

    return std::move(std::pair<std::unique_ptr<TreeNode>, vector<TreeNode*>>{root.release(),vec});
}
