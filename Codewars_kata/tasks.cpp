#include <iostream>
#include <cctype>
#include<unordered_map>


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


/// Kata: Delete occurrences of an element if it occurs more than n times

// Given a list and a number, create a new list that contains each number of list at most N times, without reordering.
// For example if the input number is 2, and the input list is [1,2,3,1,2,1,2,3], 
// you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3,
// which leads to [1,2,3,1,2,3]. With list [20,37,20,21] and number 1, the result would be [20,37,21].
    
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  
  if(arr.size() < 2)
    return arr;
 
  std::unordered_map<int, int> u_map {};
  
  for(size_t i = 0; i < arr.size(); ++i)
    ++u_map[arr[i]];
 
  for(auto right_it {arr.rbegin()}; 
      right_it != arr.rend(); ++right_it) 
  {
    if(u_map[*right_it] > n)
    {
      --u_map[*right_it];
      arr.erase(--(right_it.base()));
    }    
  }
  
  return arr;
  
}


