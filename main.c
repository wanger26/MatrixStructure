#include "matrix.h"
#include <stdio.h>


int main (void){
    Matrix matrix= matrix_construction();
    char key1[256], key2[256];


    while (scanf("%s %s", key1, key2)== 2) { //while the file or the user has more input
        if (matrix_isin(matrix, key1, key2) == 1) {
            matrix_inc(matrix, key1, key2, 1);
        } else{
            matrix_set(matrix, key1, key2, 1);
        }
    }


    matrix_list(matrix);
    matrix_destruction(matrix);
    return 0;
}