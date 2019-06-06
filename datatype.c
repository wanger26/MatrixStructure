#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "datatype.h"

char*string_dup(char *str){
    return strdup(str);
}

Key key_gen(char *skey1, char *skey2){
    Key newKey=malloc(sizeof(Key)); //Allocating space for a key
    newKey->skey1=string_dup(skey1);
    newKey->skey2=string_dup(skey2);

    return newKey;
}

int key_comp(Key key1, Key key2){
    int result=0;
    result=strcmp(key1->skey1, key2->skey1);
    if (result==0) result=strcmp(key1->skey2, key2->skey2); //if the first keys are equal check the 2nd ones

    return result;

}

void key_print(Key key){
    printf("%s\t%s",key->skey1, key->skey2 );
}

void key_free(Key key){
    free(key->skey1);
    free(key->skey2);
    free(key);
}

Data data_gen (int idata){
    Data newData= malloc(sizeof(Data)); //Allocating memory for a data
    *newData=idata;

    return newData;
}

void data_set(Data data, int idata){
    *data=idata;
}

void data_print(Data data){
    printf("\t%d\n", *data);
}

void data_free(Data data){
    free(data);
}