#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {

        vector<int> index;

        for(int i = 0;i < text.size(); ++i){
            if(text[i] == pattern[0]){
                index.push_back(0);
            }else if(text[i] == pattern[1]){
                index.push_back(1);
            }
        }

        if(pattern[0] == pattern[1]){
            long long total = index.size()+1;

            return total * (total - 1) / 2;


        }


        // 1,1,1,1,1,1,1,1,0  --> 0 as head
        // 1, 0, 0,0,0,0,0,0 ---> 1 as tail
        // 0 as head, or 1 as tail
        long long zeroAsHeadRes = 0;
        long long oneAsTailRes = 0;

        int oneCount = accumulate(index.begin(),index.end(),0);
        int zeroCount = index.size() - oneCount;

        int existingOne = 0;
        int existingZero = 0;

        zeroAsHeadRes += oneCount;

        for(int i = 0; i < index.size(); ++i){
            if(index[i]){
                existingOne++;
            }else{
                zeroAsHeadRes+= (oneCount - existingOne);
                oneAsTailRes += (oneCount + 1 - existingOne);

                existingZero++;
            }
        }

        return max(zeroAsHeadRes,oneAsTailRes);
        
    }
};

int main(){
    Solution s;
    {
        string text = "abdcdbc";
        string pattern = "ac";
        assert(s.maximumSubsequenceCount(text,pattern) == 4);
    }
    {
        string text = "aabb";
        string pattern = "ab";
        assert(s.maximumSubsequenceCount(text,pattern) == 6);
    }
{
        string text = "vnedkpkkyxelxqptfwuzcjhqmwagvrglkeivowvbjdoyydnjrqrqejoyptzoklaxcjxbrrfmpdxckfjzahparhpanwqfjrpbslsyiwbldnpjqishlsuagevjmiyktgofvnyncizswldwnngnkifmaxbmospdeslxirofgqouaapfgltgqxdhurxljcepdpndqqgfwkfiqrwuwxfamciyweehktaegynfumwnhrgrhcluenpnoieqdivznrjljcotysnlylyswvdlkgsvrotavnkifwmnvgagjykxgwaimavqsxuitknmbxppgzfwtjdvegapcplreokicxcsbdrsyfpustpxxssnouifkypwqrywprjlyddrggkcglbgcrbihgpxxosmejchmzkydhquevpschkpyulqxgduqkqgwnsowxrmgqbmltrltzqmmpjilpfxocflpkwithsjlljxdygfvstvwqsyxlkknmgpppupgjvfgmxnwmvrfuwcrsadomyddazlonjyjdeswwznkaeaasyvurpgyvjsiltiykwquesfjmuswjlrphsdthmuqkrhynmqnfqdlwnwesdmiiqvcpingbcgcsvqmsmskesrajqwmgtdoktreqssutpudfykriqhblntfabspbeddpdkownehqszbmddizdgtqmobirwbopmoqzwydnpqnvkwadajbecmajilzkfwjnpfyamudpppuxhlcngkign";
        string pattern = "rr";
        assert(s.maximumSubsequenceCount(text,pattern) == 496);
    }
}
