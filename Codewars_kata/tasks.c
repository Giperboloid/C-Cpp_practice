#include <stddef.h>

/// Kata: Find the odd int
/// Given an array of integers, find the one that appears an odd number of times.
/// There will always be only one integer that appears an odd number of times.
/// Examples:
/// [7] should return 7, because it occurs 1 time (which is odd).
/// [0] should return 0, because it occurs 1 time (which is odd).
/// [1,1,2] should return 2, because it occurs 1 time (which is odd).
/// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
/// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
int find_odd (size_t length, const int array[length])
{
    int i = -1;
    //fixing an element
    while((size_t)++i < length){
        int j = -1;
        int times = 1;
        //going through array and comparing while an element is fixed
        while((size_t)++j < length){
            if(i != j && array[i]==array[j])
                ++times; //increasing 'times' quantity
        }
        if(times%2!=0) //checking is 'times' variable odd?
            return array[i];
    }
    return 0;
}

/// Kata: Bit Counting
/// Write a function that takes an integer as input,
/// and returns the number of bits that are equal to one in the binary representation of that number.
/// You can guarantee that input is non-negative.
/// Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case.
size_t countBits(unsigned value)
{
    /// Get bit's quantity in value
    int bits_q = sizeof(value) * 8;

    size_t ones_q = 0;

    /// Checking each bit for equality to one in the loop
    for(int i = bits_q - 1; i >= 0; --i)
        if((1 << i) & value) ++ones_q;

    return ones_q;
}

/// Kata: is_zero_plentiful
/// An array is called zero-plentiful if it contains multiple zeros, and every sequence of zeros is at least 4 items long.
/// Your task is to return the number of zero sequences if the given array is zero-plentiful, otherwise 0.
unsigned is_zero_plentiful (size_t length, const short array[length])
{

    int zero_q = 0;
    int seq_q = 0;

    for(size_t i = 0; i < length; ++i) {
        if(!array[i])
            ++zero_q;
        else {
            if(zero_q && zero_q < 4) {
                zero_q = 0;
                seq_q = 0;
                break;
            }
            else if(zero_q >= 4) {
                ++seq_q;
                zero_q = 0;
            }
        }
    }

    if(!array[length - 1])
        seq_q = (zero_q >= 4) ? seq_q + 1 : 0;

    return seq_q;
}

/// Kata: Handshake problem
/// Every year he takes photos of farmers handshaking.
/// Johnny knows that no two farmers handshake more than once.
/// He also knows that some of the possible handshake combinations may not happen.
/// However, Johnny would like to know the minimal amount of people
/// that participated this year just by counting all the handshakes.
/// Help Johnny by writing a function,
/// that takes the amount of handshakes and returns the minimal amount of people
/// needed to perform these handshakes (a pair of farmers handshake only once).
int is_perfect_square(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
        long long sr = sqrt(x);
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return 0;
}

int get_participants(int handshakes) {
    /* The solution is about finding parameter 'n'
    in the number of combinations without repetition
    of n(number of farmers) by 2(min amount of fermers for handshake):
    (C_n)^2 = handshakes -> just need to solve the quadratic equation
    and choose a minimal one positive root: n!/[ 2! * (n-2)!] = (n-1)*n/2 = handshakes
    --> n^2 -n -2*handhsakes = 0 */

    /// n^2 -n -2*handshakes -- parabola with only one positive root or null
    /// --> if handshakes is not NULL then choosing a positive one root
    int root = 0;
    if(handshakes){
        double descriminant = 1 + 8*handshakes;
        /// check if descriminant has decimal root
        if(is_perfect_square(descriminant))
            root = 1 + (int)sqrt(descriminant)/2;
        else
            root = ceil(1 + ceil(sqrt(descriminant))/2);
    }
    return root;
}


/// Kata: Number of trailing zeros in N!
// Write a program that will calculate the number of trailing zeros in a factorial of a given number.
// N! = 1 * 2 * 3 *  ... * N
// Be careful 1000! has 2568 digits...
// For more info, see: http://mathworld.wolfram.com/Factorial.html 

// Examples:
// zeros(6) = 1
// 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero
// zeros(12) = 2
// 12! = 479001600 --> 2 trailing zeros
// Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.

/* According to https://mathworld.wolfram.com/Factorial.html 
   the number Z of trailing zeros for n! can be calculated as:
   Z = sum from 1 to [log5^n] ( [ n / 5 ^ [log5^n] ] ), 
   where [] ~ floor(), log5^n ~ log(n)/log(5)
*/
long zeros(long n) {
  
  unsigned k_max = (unsigned)floor(log(n)/log(5));

  long Z = 0;
  
  for(unsigned k = 1; k <= k_max; ++k)
    Z += floor(n / pow(5, k));
  
  return Z;
}


