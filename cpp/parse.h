#include<vector>
#include<sstream>
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

        if((v[i] == '[') || (v[i] == ' ') || (v[i] == '"')){
            continue;
        }

        if(((v[i] == '"') && (prevStart != -1))){
            stringstream ss;
            ss<< v.substr(prevStart, i-prevStart);
            string value;
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
