#include <string>
#include <iostream>
#include <cassert>
#include <set>
#include <algorithm>
using namespace std;

class Solution{
public:
    string removeDigit(string name, char digit){

        string ret = name;
        ret.pop_back();
        fill(ret.begin(), ret.end(), '0');

        for (int i =0 ; i< name.length(); ++i){

            if(name[i] != digit){
                continue;
            }

            string temp = name;
            temp.erase(i,1);

            assert (temp.length() == name.length() -1);

            ret = max(temp, ret);
        }

        return ret;
        
    }
};

int main(){

    Solution s;
    cout<<s.removeDigit(std::string("123"),'3')<<endl;
    cout<<s.removeDigit(std::string("1231"),'1')<<endl;
    cout<<s.removeDigit(std::string("551"),'5')<<endl;
}
