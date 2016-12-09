//
//  sort_time.cpp
//  sort_time
//
//  Created by Moritz Althaus on 7/12/16.
//  Copyright © 2016 Moritz Althaus. All rights reserved.
//

# include <iostream>
# include <string>
# include <cassert>
# include <cmath>
# include <vector>
# include <cctype>
# include <cstdlib>
# include <algorithm>
# include <chrono>

template <typename Iterator, typename LessThanFunctor> //Insertion Sort mit Iterator
void insertion_sort(Iterator begin, Iterator end, LessThanFunctor less_than) {
    if(begin == end) return;
    Iterator beginning = begin;
    for(begin++; begin!=end; begin++) {
        auto current = *begin;
        Iterator iter = begin;
        while(iter > beginning) {
            if(less_than(*(iter - 1), current)) { //Warum kann ich hier nicht *begin einsetzten?
                break;
            }
            *iter = *(iter - 1);
            --iter;
        }
        *iter = current; //Element in die Lücke einfügen
    }
    
}
template <typename Iterator> //gibt einen Vector aus
void vector_out(Iterator begin, Iterator end){
    std::cout << "{";
    if(begin != end) {
        std::cout << " " << *begin;
        ++begin;
        for(; begin != end; ++begin) {
            std::cout << ", " << *begin;
        }
    }
    std::cout << "}";
}


std::vector<double> best_time_vector(int n) {
    std::vector<double> v(n);
    for(long int k=0; k<n; ++k) {
        v[k] = k;
    }
    return v;
}
std::vector<double> worst_time_vector(int n) {
    std::vector<double> v(n);
    for(long int k=0;k<n; ++k) {
        v[k] = n-k-1;
    }
    return v;
}

double std_insertion_sort_time(std::vector<double> v) { //Messung für Insertion Sort
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort(v.begin(), v.end(), [] (double a, double b) {
        return a<b;
    });
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stop - start;
    return diff.count();
}
              
double insertion_sort_worst_time(double n) {
    std::vector<double> v = worst_time_vector(n);
    return std_insertion_sort_time(v);
}
double insertion_sort_best_time(double n) {
    std::vector<double> v = best_time_vector(n);
    return std_insertion_sort_time(v);
}
double insertion_sort_typical_time(double n) {
    std::vector<double> v = best_time_vector(n);
    std::random_shuffle(v.begin(), v.end());
    return std_insertion_sort_time(v);
}
double fastest_typical_time(int size) {
    double fastest_time=0;
    double time;
    for(int i=0; i<3; ++i) {
        time = insertion_sort_typical_time(size);
        if(time<fastest_time || fastest_time==0) {
            fastest_time = time;
        }
    }
    
    return fastest_time;
}
double fastest_best_time(int size) {
    double fastest_time=0;
    double time;
    for(int i=0; i<3; ++i) {
        time = insertion_sort_best_time(size);
        if(time<fastest_time || fastest_time==0) {
            fastest_time = time;
        }
    }

    return fastest_time;
}
double fastest_worst_time(int size) {
    double fastest_time=0;
    double time;
    for(int i=0; i<size; ++i) {
        time = insertion_sort_worst_time(size);
        if(time<fastest_time || fastest_time==0) {
            fastest_time = time;
        }
    }
    
    return fastest_time;
}

double std_sort_time_s(std::vector<double> v) { //Messung für Sort
    auto start = std::chrono::high_resolution_clock::now();
    sort(v.begin(), v.end(), [] (double a, double b) {
        return a<b;
    });
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stop - start;
    return diff.count();
}

double sort_worst_time(double n) {
    std::vector<double> v = worst_time_vector(n);
    return std_sort_time_s(v);
}
double sort_best_time(double n) {
    std::vector<double> v = best_time_vector(n);
    return std_sort_time_s(v);
}
double sort_typical_time(double n) {
    std::vector<double> v = best_time_vector(n);
    std::random_shuffle(v.begin(), v.end());
    return std_sort_time_s(v);
}
double fastest_typical_time_s(int size) {
    double fastest_time=0;
    double time;
    for(int i=0; i<3; ++i) {
        time = sort_typical_time(size);
        if(time<fastest_time || fastest_time==0) {
            fastest_time = time;
        }
    }
    
    return fastest_time;
}
double fastest_best_time_s(int size) {
    double fastest_time=0;
    double time;
    for(int i=0; i<3; ++i) {
        time = sort_best_time(size);
        if(time<fastest_time || fastest_time==0) {
            fastest_time = time;
        }
    }
    
    return fastest_time;
}
double fastest_worst_time_s(int size) {
    double fastest_time=0;
    double time;
    for(int i=0; i<3; ++i) {
        time = sort_worst_time(size);
        if(time<fastest_time || fastest_time==0) {
            fastest_time = time;
        }
    }
    
    return fastest_time;
}

void call_best (std::vector<double> sizes) {
    for(int i=0; i<sizes.size(); ++i) {
        std::cout << "Größe: " << sizes[i] << std::endl;
        std::cout << "Beste Zeit Insertion Sort: " << fastest_best_time(sizes[i]) << std::endl;
        // std::cout << "Beste Zeit Sort für Größe: " << fastest_best_time_s(sizes[i]) << std::endl;
        std::cout << std::endl;
    }
}

void call_worst (std::vector<double> sizes) {
    for(int i=0; i<sizes.size(); ++i) {
        std::cout << "Größe: " << sizes[i] << std::endl;
        std::cout << "Schlechteste Zeit Insertion Sort: " << fastest_worst_time(sizes[i]) << std::endl;
        // std::cout << "Schlechteste Zeit Sort: " << fastest_worst_time_s(sizes[i]) << std::endl;
        std::cout << std::endl;
    }
}

void call_typical (std::vector<double> sizes) {
    for(int i=0; i<sizes.size(); ++i) {
        std::cout << "Größe: " << sizes[i] << std::endl;
        std::cout << "Typische Zeit Insertion Sort: " << fastest_typical_time(sizes[i]) << std::endl;
        std::cout << "Typische Zeit Sort: " << fastest_typical_time_s(sizes[i]) << std::endl;
        std::cout << std::endl;
    }
}
int main() {
    std::vector<double> sizes = {5, 10, 20};
    call_typical(sizes);


}
