#include <iostream>
#include <chrono>
#include <vector>

void insertion_sort (std::vector <double> & v) {  // pass-by-reference

    for (int k = 1; k<v.size(); ++k) {

        double current = v[k];  // variable to memorize the element at position k
        int j = k;

        while (j > 0) {  // compare current element with each one in front of it

            if (current < v[j-1]) {  // swap elements if comparison is true 
                v[j] = v[j-1];
            } else {
                break;
            }
            --j;  // go to the next element at the left and compare this one to current
        }

        v[j] = current;
    }
}

double insertion_sort_best_time(int  n) {

    std::vector <double> v(n);  // initialize vector with size n with ascending integers
    for (int i = 0; i<n; ++i) {
        v[i] = i;
    }

    // do not shuffle the vector to get the best sort time

    auto start = std::chrono::high_resolution_clock::now();  // measure the time during the std::sort() function runs
    insertion_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> diff = stop - start;

    return diff.count();
}

double insertion_sort_worst_time(int  n) {

    std::vector <double> v(n);  // initialize vector with size n with descending integers
    for (int i = 0; i<n; ++i) {
        v[i] = v.size()-i;
    }    // do not shuffle the vector to get the worst sort time

    auto start = std::chrono::high_resolution_clock::now();  // measure the time during the std::sort() function runs
    insertion_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> diff = stop - start;

    return diff.count();
}

double insertion_sort_typical_time(int  n) {

    std::vector <double> v(n);  // initialize vector with size n with integers
    for (int i = 0; i<n; ++i) {
        v[i] = i;
    }

    std::random_shuffle(v.begin(), v.end());  // shuffle the vector to get a random sort time

    auto start = std::chrono::high_resolution_clock::now();  // measure the time during the std::sort() function runs
    insertion_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> diff = stop - start;

    return diff.count();
}

double std_sort_time(int  n) {

    std::vector <double> v(n);  // initialize vector with size n with integers
    for (int i = 0; i<n; ++i) {
        v[i] = i;
    }

    std::random_shuffle(v.begin(), v.end());  // shuffle the vector to get a random sort time

    auto start = std::chrono::high_resolution_clock::now();  // measure the time during the std::sort() function runs
    std::sort(v.begin(), v.end());
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> diff = stop - start;

    return diff.count();
}

int main() {

    int n;
    double result = 0.0;

    std::cout << "Gib bitte die Größe des Arrays an: \n";
    std::cin >> n;
    std::cout << "\n";

    // result = std_sort_time(n);

    for (int i = 0; i<1e+5; ++i) {
        result += insertion_sort_best_time(n);
    }

    std::cout << result << " Sekunden" << "\n";

    return 0;
}