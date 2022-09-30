#include <iostream>
#include <cctype>


/// Kata: Isograms

// An isogram is a word that has no repeating letters, consecutive or non-consecutive.
// Implement a function that determines whether a string that contains only letters is an isogram.
// Assume the empty string is an isogram. Ignore letter case.
/* Example: (Input --> Output)
 * "Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)
 * */
bool is_isogram(std::string str) {

    for(size_t i = 0; i < str.length(); ++i){
        if(str.find(str[i], i + 1)!=std::string::npos ||
           str.find((char)toupper(str[i]), i + 1)!=std::string::npos)
            return false;
    }

    return true;

}
