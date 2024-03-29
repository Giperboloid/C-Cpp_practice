#include <iostream>
#include <cctype>
#include <unordered_map>


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



/// Kata: Counting Duplicates

// Write a function that will return the count of distinct case-insensitive alphabetic characters 
// and numeric digits that occur more than once in the input string. The input string can be assumed 
// to contain only alphabets (both uppercase and lowercase) and numeric digits.

/* 
Examples: 
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice
*/
size_t duplicateCount(const std::string& in)
{
  
  size_t counter = 0;
  std::unordered_map<char, int> u_map{};
  
  for(const auto& sym : in)
    ++u_map[std::tolower(static_cast<unsigned char>(sym))];

  std::for_each(u_map.begin(), u_map.end(), 
                [&counter](std::pair<const char, int>& map_e){
                  if (map_e.second > 1)
                    ++counter;
                });
  
  return counter;
}



/// Kata: Integers: Recreation One

// Find all integers between m and n (m and n integers with 1 <= m <= n) such
// that the sum of their squared divisors is itself a square. 

/* Examples 
   1, 246, 2, 123, 3, 82, 6, 41 are the divisors of number 246. Squaring these divisors we get: 1, 
   60516, 4, 15129, 9, 6724, 36, 1681. The sum of these squares is 84100 which is 290 * 290.
 */
class SumSquaredDivisors
{
  
private:
  
    static std::set<long long> GetNotPrimeNumbers(long long m, long long n) {
      
      /*
       * Let's use Sieve of Eratosthenes Method
       */
      std::vector<bool> arr(n + 1, true);
      std::set<long long> result{};
    
      arr[0] = arr[1] = false;
    
      for(long long i = 2; i*i <= n; ++i)
         if(true == arr[i])
              for(auto j = i*i; j <= n; j+=i)
                  arr[j] = false;
                
      std::for_each(arr.begin(), arr.end(), [&result, m, idx = 0] (bool is_prime) mutable {
          if(not is_prime && idx >= m)
              result.insert(idx);
          ++idx;    
      });            
    
      return result;    
    }
  
    static long long GetDevisorsSquaredSum(long long num) {
      
      long long devisor = 0, sqr_sum = 0;
      
      for (devisor = 1; devisor * devisor < num; ++devisor) {
          if (num % devisor == 0)
              sqr_sum += devisor * devisor;
      }
      
      if (devisor - (num / devisor) == 1) {
          --devisor;
      }
    
       for (; devisor >= 1; --devisor) {
         if (num % devisor == 0)
              sqr_sum += (num / devisor) * (num / devisor);
      }
      
      return sqr_sum;
    }
  
  
public:
  
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n) {
      
      std::vector<std::pair<long long, long long>> result{};
      
      /* 
       * First of all we need filter out prime numbers - they exactly don't match to our criteria:
       * the sum of squared devisors of an prime number can't be an square -> because this sum equals 
       * 1 + some_square.
       */
      auto not_prime_numbers{GetNotPrimeNumbers(m, n)};
      
      if(not not_prime_numbers.empty()) {
        
        for(const auto& not_prime : not_prime_numbers) {
        
          auto sqr_sum {GetDevisorsSquaredSum(not_prime)};
        
          long long sqr_sum_root = sqrt(sqr_sum);
        
          if(sqr_sum_root * sqr_sum_root == sqr_sum)
          result.push_back({not_prime, sqr_sum});
        }
        
      }
      
      return result;
    }
};




/// Kata: Perimeter of squares in a rectangle

/// The drawing shows 6 squares the sides of which have a length 
/// of 1, 1, 2, 3, 5, 8. It's easy to see that the sum of the perimeters of these 
/// squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80.
typedef unsigned long long ull;

class SumFct
{
  
  private:
  
      static ull FebSeqSum(int count, ull prev, ull curr) {
        
        ull result = curr;

        if(--count)         
          result += FebSeqSum(count, curr, curr + prev);
        
        return result;
        
      }
  
  
  public:
  
       static ull perimeter(int n) {
         return 4 * (FebSeqSum(n, 1, 1) + 1);
       }
  
};



/// Kata: Replace With Alphabet Position
// In this kata you are required to, given a string, replace every letter with its position in the alphabet.
// If anything in the text isn't a letter, ignore it and don't return it.
// "a" = 1, "b" = 2, etc.

std::string alphabet_position(const std::string &text) {

  std::string result;
  
  for(const char symb : text) {
    
    auto ascii_code = static_cast<int>(symb);
    int pos = 0;
    
    if(ascii_code >= 65 && ascii_code <= 90) 
       pos = ascii_code - 65 + 1;
    else if (ascii_code >= 97 && ascii_code <= 122)
       pos = ascii_code - 97 + 1;
    else
      continue;
    
    result += (std::to_string(pos) + ' ');
  }
  
  if(!result.empty())
     result.pop_back();
  
  return result;
    
}

