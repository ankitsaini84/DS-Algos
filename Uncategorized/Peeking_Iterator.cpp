/**
 * Given an Iterator class interface with methods: next() and hasNext(), design and 
 * implement a PeekingIterator that support the peek() operation -- it essentially peek() 
 * at the element that will be returned by the next call to next().
 * 
 * EXAMPLE:
 * Assume that the iterator is initialized to the beginning of the list: [1,2,3].
 * 
 * Call next() gets you 1, the first element in the list.
 * Now you call peek() and it returns 2, the next element. Calling next() after that still 
 * return 2. 
 * You call next() the final time and it returns 3, the last element. 
 * Calling hasNext() after that should return false.
 */

#include <iostream>
#include <vector>

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
 class Iterator {
    public:
    struct Data;
	Data* data;
	Iterator(const std::vector<int>& nums);
	Iterator(const Iterator& iter);
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

/**
 * Algo ~
 * Idea is to always keep the next element ready with us.
 * So, whenever seek() is called, return current cached 'next-element' and fetch & 
 * cache the next element with us.
 * 
 * But, since, copying any elements in constructor is forbidden - 
 * how to get 1st next-element to cache?
 * -> If 1st call is peek(), just fetch & cache the next element right away &
 * return the same.
 * -> But, if 1st call is seek(), fetch next-element to return to the user, & also,
 * fetch another next-element to caching.
 * 
 * Since, we always have the next cached next-element, we'll know when we reach
 * the last element - cached value -1.
 */
class PeekingIterator : public Iterator {
    // -2 -> Represents, Un-initialized
    // -1 -> Represents, Last-Element
    int next_no {-2};

    int getNext() {
        if(Iterator::hasNext()) return Iterator::next();
        else {
            return -1;
        }
    }
public:
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(next_no == -2) {         // 1st call is peek
            next_no = Iterator::next();
        }
        return next_no;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(next_no == -2) {         // 1st call is next
            next_no = getNext();    // return this to user
        }
        int temp {next_no};
        next_no = getNext();        // cache next-element
	    return temp;
	}
	
	bool hasNext() const {
        return next_no != -1;       // last element
	}
};

int main() {
    return 0;
}