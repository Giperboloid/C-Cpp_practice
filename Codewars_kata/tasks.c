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
