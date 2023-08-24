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


/// Kata: Descending Order

// Your task is to make a function that can take any non-negative integer as an argument 
// and return it with its digits in descending order. Essentially, rearrange the digits 
// to create the highest possible number.

/* Examples:
Input: 42145 Output: 54421
Input: 145263 Output: 654321
Input: 123456789 Output: 987654321 */

uint64_t descendingOrder(uint64_t a)
{
  
  auto char_digits{std::to_string(a)};
  
  std::sort(char_digits.begin(), char_digits.end(), std::greater<char>());
  
  uint64_t result {};
  std::from_chars(char_digits.data(), char_digits.data() + char_digits.size(), result);
  
  return result;
}



    
