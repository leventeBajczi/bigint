#include "headers/operations.h"

extern base add_op1_len;
extern base add_op1_ptr;
extern base add_op2_len;
extern base add_op2_ptr;

extern base compl_op_len;
extern base compl_op_ptr;

uint8_t* addbig(uint8_t* a, base alen, uint8_t* b , base blen)
{
    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*alen);

    #ifdef DEV
    printf("0x");
    #endif

    //load into appropiate memories
    load(a, alen, add_op1_ptr, &add_op1_len);
    #ifdef DEV
    printf(" + 0x");
    #endif

    load(b, blen, add_op2_ptr, &add_op2_len);
    #ifdef DEV
    printf(" = 0x");
    #endif


    //do the required operations
    add(0);
    
    //store the data in the result
    store(result, &alen, add_op1_ptr, add_op1_len);
    return result;
}

uint8_t* subbig(uint8_t* a, base alen, uint8_t* b , base blen)
{
    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*alen);

    //load into appropiate memories
    load(a, alen, add_op1_ptr, &add_op1_len);
    load(b, blen, compl_op_ptr, &compl_op_len);

    //do the required operations
    compl();
    cpy(compl_op_ptr, compl_op_len, add_op2_ptr, &add_op2_len);
    add(0);
    
    //store the data in the result
    store(result, &alen, add_op1_ptr, add_op1_len);
    return result;
}
uint8_t* mulbig(uint8_t* a, base alen, uint8_t* b , base blen)
{

return NULL;
}
uint8_t* restbig(uint8_t* a, base alen, uint8_t* m , base mlen)
{

return NULL;
}
uint8_t* powmod(uint8_t* a, base alen, uint8_t* b , base blen, uint8_t* m , base mlen)
{

return NULL;
}
uint8_t* isprime(uint8_t* p, base plen, base exp){

return NULL;
}