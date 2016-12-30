#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <cstdlib>

#include <cmath>
#include "sort_versions.hpp"


std::vector <int> split_version(std::string version) {  // separate a sentence into its single words

   
	std::vector <int> single_numbers;  // initialize vector to write results to it
   
	std::string substring = "";
   
	int last_space = 0;  // recognize last space to create right substring

   
	for (int i = 0; i<=version.size(); i++) {
       
		if (version.compare(i,1,".") == 0 || i==version.size()) {  // find the space to separate string in front of it or the last one

           
			substring = version.substr(last_space, i - last_space);  // create substring and add it to the vector
           
			single_numbers.push_back(std::atoi(substring.c_str()) );  // this two lines could work in one, but it would be chaotic

           
			last_space = i+1;  // +1 to skip space in next string
       
		}
   
	}

   
	return single_numbers;

}



bool version_less(std::string v1, std::string v2) {
	
	std::vector<int> w1 = split_version(v1);
	
	std::vector<int> w2 = split_version(v2);
	
	bool versionless;
	
	int a,b,c;
	
	a = w1.size();
	
	b = w2.size();
	
	c = a + b + std::abs(a-b);
	
	int maximumsize = 0.5*c;
	
	int i;
	for (i = 0; i<maximumsize; i++){

		if (w1[i] > w2[i]){

			versionless = false;

			break;
		}

		if (w1[i] < w2[i]){

			versionless = true;

			break;

		}
	
	if (w1[i] == w2[i]){

			versionless = false;

			continue;

		
}

	}

	return versionless;

}



int main() {
	//std::vector<string> sortier = sort(sortversions);
	//for (int i = 0; i < sortier.size(); i++){
		
		
//}
}