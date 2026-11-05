#include <stdio.h>
#include <stdbool.h>

bool valid_triangle (unsigned x, unsigned y, unsigned z);


int main(void) {
    if (valid_triangle(4, 1, 5)) {
        return 0;
    }


    return 1;
}


bool valid_triangle (unsigned x, unsigned y, unsigned z) {
    bool valid = (x + y >= z) ? true : false;
    return valid;
}