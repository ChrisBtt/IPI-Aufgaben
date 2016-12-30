#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

template <typename ElementType, typename LessThanFunctor>

// exercise 7.1a)
bool check_sorted(std::vector<ElementType> const & v, LessThanFunctor less_than) {

    if (v.size() == 0) {  // an empty container is sorted
        return true;
    }

    for (int k = 1; k < v.size(); ++k) {
        if (less_than(v[k], v[k-1])) { // check equality depending on the input function
            return false; 
        }
    }

    return true;  // array sorted if all pairs checked
}

template <typename Iterator, typename LessThanFunctor>

// exercise 7.1b)
bool check_sorted(Iterator begin, Iterator end, LessThanFunctor less_than) {
    if (begin == end) { // empty container is sorted
        return true;
    }

    Iterator next = begin;
    ++ next; // "next" points to element next to begin

    for (; next != end; ++begin, ++next) { // creates a for-loop over both iterators at the same time

        if (less_than(*next , *begin)) {  // checks the two partners with our function less_than
            return false;
        } 
    }

    return true;
}

template <typename ElementType, typename LessThanFunctor>

// exercise 7.1c)
void insertion_sort(std::vector<ElementType> & v, LessThanFunctor less_than) {
    
    for (int k = 1; k < v.size(); ++k) {
        
        double current = v[k];  // remarks the given element at position k
        int j = k; // position where the function creates a gap

        while (j>0) {

            if (less_than(v[j-1], current)) {  // compares the current element to its previous neighbour
                break;
            }

            v[j] = v[j-1];  // copies each element to its next neighbour then the old position is overwritten
            --j;
        }
        v[j] = current;  // element at position k is copied to position j
    }
}

template <typename Iterator, typename LessThanFunctor>

void insertion_sort(Iterator begin, Iterator end, LessThanFunctor less_than) {

    Iterator beginning = begin;  // creates variable to refer to begin of the container
    for (begin++; begin < end; ++begin) {
        
        auto current = *begin;  // remarks the given element at position k
        Iterator iter = begin; // position where the function creates a gap

        while (iter>beginning) {

            if (less_than(*(iter-1), current)) {  // compares the current element to its previous neighbour
                break;
            }

            *iter = *(iter-1);  // copies each element to its next neighbour then the old position is overwritten
            --iter;
        }
        *iter = current;  // element at position k is copied to position j
    }
}


int main() {

    std::vector <std::string> v = {"Ac", "ab", "De", "cf"};

    insertion_sort(v.begin(), v.end(), [] (std::string a, std::string b) {  // sort container and check if sorted
        return a>b;
    });

    for (auto & element : v) {
        std::cout << element << std::endl;
    }
    assert(check_sorted(v.begin(), v.end(), [] (std::string a, std::string b) {
        return a>b;
    }));

    std::random_shuffle(v.begin(), v.end());  // shuffle container and test if sorted
    assert(!check_sorted(v.begin(), v.end(), [] (std::string a, std::string b) {
        return a>b;
    }));

    return 0;
}
