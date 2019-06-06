#include <stdio.h>
#include "matrix.h"

void dataTest(void);
void bstTest(void);
void matrixTest(void);


int main() {
    int test=0;
    scanf("%d", &test);

    if (test==1) dataTest();
    else if (test==2)bstTest();
    else matrixTest();
    return 0;
}

void dataTest(void){

    Key key1 =key_gen("Test", "123");
    Key key2= key_gen("ACDC", "ABBA");
    Key key3= key_gen("Drake", "OVO");
    Key key4= key_gen("The Beatles", "Bruce Springsteen");
    Data data1=data_gen(9);
    Data data2= data_gen(13);
    Data data3= data_gen(19);

    printf("Correct Answer\t\t Result\n");
    printf("Test123\t\t%s\n", string_dup("Test 123"));
    printf("1 \t\t%d\n",key_comp(key1, key2));
    printf("-1 \t\t%d\n",key_comp(key3, key4));
    printf("0 \t\t%d\n",key_comp(key1, key1));
    key_print(key1);
    data_print(data1);
    data_free(data1);
}
void bstTest(void){
    Key key1 =key_gen("Test", "123");
    Key key2= key_gen("ACDC", "ABBA");
    Key key3= key_gen("Drake", "OVO");
    Key key4= key_gen("The Beatles", "Bruce Springsteen");
    Data data1=data_gen(9);
    Data data2= data_gen(13);
    Data data3= data_gen(19);

    printf("Correct Answer\t\t Result\n");
    printf("Test123\t\t%s\n", string_dup("Test 123"));
    printf("1 \t\t%d\n",key_comp(key1, key2));
    printf("-1 \t\t%d\n",key_comp(key3, key4));
    printf("0 \t\t%d\n",key_comp(key1, key1));
    key_print(key1);
    data_print(data1);
    data_free(data1);

    BStree bst= bstree_ini();
    bstree_insert(bst, key1, data1);
    bstree_insert(bst, key2, data1);
    bstree_insert(bst, key3, data2);
    bstree_insert(bst, key4, data3);
    printf("9\t\t%d\n", *bstree_search(bst, key1));
    printf("Should be ACDC ABBA --> Drake OVO --> Test 123 --> The Beatles Bruce Springsteen\n ");
    bstree_traversal(bst);
    bstree_free(bst);
}
void matrixTest(void){
    Key key1 =key_gen("Test", "123");
    Key key2= key_gen("ACDC", "ABBA");
    Key key3= key_gen("Drake", "OVO");
    Key key4= key_gen("The Beatles", "Bruce Springsteen");
    Data data1=data_gen(9);
    Data data2= data_gen(13);
    Data data3= data_gen(19);

   Matrix matrix=matrix_construction();
   matrix_set(matrix, "bba", "aa",99);
   matrix_set(matrix, "aab", "aab",1);
   matrix_set(matrix, "bba", "aa",1);
   matrix_set(matrix, "aab", "abb",1);
   matrix_set(matrix, "bba", "aaa",1);

    printf("Correct Answer\t\t Result\n");
    printf("1\t\t%d\n", matrix_isin(matrix, "bba", "aa"));
    printf("0\t\t%d\n", matrix_isin(matrix, "not", "here"));
    printf("1 \t\t%d\n",*matrix_get(matrix, "bba", "aa"));
    if (matrix_get(matrix, "not", "here")==NULL) printf("Passed\n");
    matrix_set(matrix, "bba", "aa",17777);
    printf("17777 \t\t%d\n",*matrix_get(matrix, "bba", "aa"));
    matrix_inc(matrix, "bba", "aa", 1);
    printf("17778 \t\t%d\n",*matrix_get(matrix, "bba", "aa"));
    printf("Should be \t aab aab --> aab abb --> bba aa --> bba aaa\n ");
    matrix_list(matrix);
}
