#include "../singly_ll.h"
#include <stdlib.h>
#include <stdio.h>


int main(void) {
    // NULL list
    node *null_list = NULL;
    node *A = llreverse(null_list);

    node *B = llreverse(A);

    llprint(A);
    llprint(B);

    insert("A", A);
    llprint(A);

    delete(B);

    return 0;
}

