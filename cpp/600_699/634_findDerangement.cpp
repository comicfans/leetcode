#include <vector>
#include <cstddef>
#include <iostream>

using namespace std;

class Solution {
    public:
            int findDerangement(int n) {

                uint64_t prev=results.back();

                results.reserve(n+1);
                for (int i= results.size(); i <= n; i++) {

                    prev=(prev*i+(i%2==0?1:-1))%1000000007;
                        
                    results.push_back(prev);

                }


                return results[n];
            }

            Solution(){
                results.push_back(0);
                results.push_back(0);
                results.push_back(1);
            }
    private :
            vector<uint64_t> results;
};



int main(int argc, char *argv[])
{
    Solution s;

    cout<<s.findDerangement(23213)<<endl;
    
    return 0;
}
