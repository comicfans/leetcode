#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


 class Iterator {
 	struct Data;
		Data* data;
 public:
 	Iterator(const vector<int>& nums):_nums(nums){
    }

		// Returns the next element in the iteration.
 	int next(){
        ++pos;
        return _nums[pos];
    }



 	// Returns true if the iteration has more elements.
 	bool hasNext() const{
        return pos < (int)_nums.size()-1;
    }

private:
    int pos = -1;
    const vector<int>& _nums;
 };


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums),_nums(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {

        assert(pos < (int)_nums.size()-1);
        return _nums[pos+1];
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    
        ++pos;
        return Iterator::next();
	}
	
	bool hasNext() const {
        return Iterator::hasNext();
	    
	}

    const vector<int> _nums;
    int pos = -1;
};

int main(){
    {
        vector<int> nums={1,2,3};
        PeekingIterator it(nums);
        assert(it.next() == 1);
        assert(it.peek() == 2);
        assert(it.next() == 2);
        assert(it.next() == 3);
        assert(!it.hasNext());
    }
    {
        vector<int> nums={1,2,3,4};
        PeekingIterator it(nums);
        assert(it.hasNext());
        assert(it.peek() == 1) ;
        assert(it.peek() == 1) ;
        assert(it.next() == 1) ;
        assert(it.next() == 2) ;
        assert(it.peek() == 3) ;
        assert(it.peek() == 3) ;
        assert(it.next() == 3) ;
        assert(it.hasNext()) ;
        assert(it.next() == 4) ;
        assert(!it.hasNext()) ;
    }
    
}
