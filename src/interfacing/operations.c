#include "headers/operations.h"

extern base add_op1_len;
extern base add_op1_ptr;
extern base add_op2_len;
extern base add_op2_ptr;

extern base compl_op_len;
extern base compl_op_ptr;

extern base mul_op1_len;
extern base mul_op1_ptr;
extern base mul_op2_len;
extern base mul_op2_ptr;
extern base mul_res_len;
extern base mul_res_ptr;

extern base rest_op1_len;
extern base rest_op1_ptr;
extern base rest_op2_len;
extern base rest_op2_ptr;

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
    #ifdef DEV
    printf("\n");
    #endif

    return result;
}

uint8_t* subbig(uint8_t* a, base alen, uint8_t* b , base blen)
{
    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*alen);

    #ifdef DEV
    printf("0x");
    #endif

    //load into appropiate memories
    load(a, alen, add_op1_ptr, &add_op1_len);
    #ifdef DEV
    printf(" - 0x");
    #endif

    load(b, blen, compl_op_ptr, &compl_op_len);

    //do the required operations
    compl();
    cpy(compl_op_ptr, compl_op_len, add_op2_ptr, &add_op2_len);
    add(0);
    
    //store the data in the result
    #ifdef DEV
    printf(" = 0x");
    #endif

    store(result, &alen, add_op1_ptr, add_op1_len);
    #ifdef DEV
    printf("\n");
    #endif

    return result;
}
uint8_t* mulbig(uint8_t* a, base alen, uint8_t* b , base blen)
{
    setbuf(stdout, NULL);
    mul_res_len = alen + blen;

    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*mul_res_len);

    #ifdef DEV
    printf("0x");
    #endif

    //load into appropiate memories
    load(a, alen, mul_op1_ptr, &mul_op1_len);
    #ifdef DEV
    printf(" * 0x");
    #endif

    load(b, blen, mul_op2_ptr, &mul_op2_len);

    //do the required operations
    mul();
    
    //store the data in the result
    #ifdef DEV
    printf(" = 0x");
    #endif

    store(result, &alen, mul_res_ptr, mul_res_len);
    #ifdef DEV
    printf("\n");
    #endif

    return result;
}
uint8_t* restbig(uint8_t* a, base alen, uint8_t* m , base mlen)
{
    uint8_t zero[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*alen);

    #ifdef DEV
    printf("0x");
    #endif

    //load into appropiate memories
    load(a, alen, rest_op1_ptr, &rest_op1_len);
    #ifdef DEV
    printf(" %% 0x");
    #endif

    for(base i = 0; i<alen - mlen; i+=sizeof(base)){
        load(zero, 8, rest_op2_ptr, &rest_op2_len);
        rest_op2_ptr+=sizeof(base);
    }
    load(m, mlen, rest_op2_ptr, &rest_op2_len);
    rest_op2_ptr -= alen - mlen;
    rest_op2_len += alen - mlen;

    //do the required operations
    rest();
    
    //store the data in the result
    #ifdef DEV
    printf(" = 0x");
    #endif

    store(result, &alen, rest_op1_ptr, rest_op1_len);
    #ifdef DEV
    printf("\n");
    #endif

    return result;
return NULL;
}
uint8_t* powmod(uint8_t* a, base alen, uint8_t* b , base blen, uint8_t* m , base mlen)
{

return NULL;
}
uint8_t* isprime(uint8_t* p, base plen, base exp){

return NULL;
}