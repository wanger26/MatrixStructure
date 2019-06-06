#import "matrix.h"
#include <stdlib.h>
#include <stdio.h>

// Matrix construction using bstree ini();
Matrix matrix_construction(void){
    Matrix matrix= bstree_ini();
    return matrix;

}

// If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
unsigned char matrix_isin(Matrix m, Index index1, Index index2){
    Key key= key_gen(index1, index2);
    if (bstree_search(m, key)!=NULL) return 1;
    else return 0;
}


// If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
// value. Otherwise, return NULL.
Value *matrix_get(Matrix m, Index index1, Index index2){
    Key key= key_gen(index1, index2);
    return bstree_search(m, key);
}


// Assign value to Matrix m at location (index1, index2). If that location already has value, then overwrite.
void matrix_set(Matrix m, Index index1, Index index2, Value value){
    Key key= key_gen(index1, index2);
    Data data= bstree_search(m,key);
    if (data==NULL){
        bstree_insert(m, key, data_gen(value));
    }
    else{
        data_set(data, value);
    }
}

// If location (index1, index2) is defined in Matrix m, then increase the associated value by
// value. Otherwise, report error
void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    Key key= key_gen(index1, index2);
    Data data= bstree_search(m,key);
    if (data==NULL) printf("Error: Matrix item not found\n");
    else data_set(data, (value+*data));
}


// Print indices and values in the Matrix m (with bstree traversal()).
void matrix_list(Matrix m){
    bstree_traversal(m);
}

// Free allocated space (with bstree free()).
void matrix_destruction(Matrix m){
    bstree_free(m);
}
