#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// int round(double n) {

//     if ((((int) (n)) - n) == 0) {  // check for inserted integer
//         return n;
//     }

//     if (n >0) {  // positiv number
//                  // decimals greater than 0.50 -> round up
//                  // round down smaller ones
//         n+=0.5;
//         return (int) n;

//     } else if (n<0) {
                
//         n-=0.5;
//         return (int) n;

//     } else {  // last possibility: n == 0
//         return 0;
//     }
// }

// std::vector <int> vec_to_int(std::vector <double> v) {

//     std::transform(v.begin(), v.end(), v.begin(), round);

//     return v;
// }

int main () {

    // std::cout << "Geben Sie bitte einige Zahlen ein:  \n";
    // std::cin >> double input;

    std::vector <double> v = {1.6, 19.5, 2.2};
    // vec_to_int(v);
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << v.at(element) << "\n";
    }

    return 0;
}