#include <iostream>
#include <vector>
#include <string>



int main() {

    std::vector<int> ordered_numbers;  // dynamic vector to react to variable size

    int new_number = -1;  // initialize as negative to cover all inserts

    std::cout << "Bitte geben Sie eine positive, ganze Zahl ein, negative Zahlen beenden das Programm \n";
    std::cin >> new_number;
    std::cout << "\n\n";

    while (new_number >= 0) {

        if (ordered_numbers.size() == 0) {  // function.size() do not cover this occurence if vector is empty
                ordered_numbers.push_back(new_number);

        } else if (new_number < ordered_numbers.back()) {  // insert new_number somewhere in the vector

            for (int i = 0; i < ordered_numbers.size(); i++) {  

                if (ordered_numbers.at(i) < new_number) {
                    continue;

                } else {  // if new number is smaller or equal to the own in the array print it

                    ordered_numbers.insert(ordered_numbers.begin()+i, new_number);
                    break;

                } 
            }

        } else {  // set new_number at the end of the vector
            ordered_numbers.push_back(new_number);
        }

        std::cout << "Das ist dein eingegebener Vektor" << std::endl;  // Ausgabe nach jeder Änderung des Vektors
        for (int i =0;  i < ordered_numbers.size(); i++) {
            std::cout << ordered_numbers[i] << std::endl;
        }

        std::cout << "Bitte geben Sie eine positive, ganze Zahl ein, negative Zahlen beenden das Programm \n";  // Aufforderung zur Eingabe in der Schleife
        std::cin >> new_number;
        std::cout << "\n\n";

    } 

    return 0;
}
