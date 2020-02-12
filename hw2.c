#include <stdio.h>

static const unsigned int bits_in_int = sizeof(int)*8;

unsigned int reverse(unsigned int toReverse) {
    unsigned int temp = 0;
    unsigned int result = 0;
    unsigned int most_sig = 0;

    for (unsigned int search = 0; search < bits_in_int; search++) {
        if (((toReverse >> search) & 1) == 1) {
            most_sig = search;
        }
    }

    unsigned int shift_start = most_sig;

    for (int shift_end = 0; shift_end <= most_sig; shift_end++) { 
        temp = ((toReverse >> shift_end) & 1) << (shift_start);
        shift_start--;
        result = result | temp;
    }
    return result;
}


unsigned int max_ones(unsigned int x) {
    int temp = 0;
    int total = 0;

    while (x > 0) {
        if (x & 1 > 0) {
            temp++;
            x = x >> 1;
        } else {
            if (temp >= total) {
                total = temp;
            }
            temp = 0;
            x = x >> 1;
        }
    }
    return total;
}


int main() {
    printf("%u\n", reverse(0b110100101));       // will print 331

    printf("%d\n", max_ones(0xF0FFF0F0));       // prints 12
    printf("%d\n", max_ones(0xF0FFFF0F));       // prints 16

    return 0;
}
