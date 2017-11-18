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

extern base powm_op1_ptr;
extern base powm_op1_len;
extern base powm_op2_ptr;
extern base powm_op2_len;
extern base powm_op3_ptr;
extern base powm_op3_len;
extern base powm_res_ptr;
extern base powm_res_len;

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
   
    mul_res_len = alen + blen;

    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*mul_res_len);

    #ifdef DEV
    setbuf(stdout, NULL);
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

    store(result, &alen, rest_op1_ptr + (alen - mlen), mlen);
    #ifdef DEV
    printf("\n");
    #endif

    return result;
}
uint8_t* powmodulo(uint8_t* a, base alen, uint8_t* b , base blen, uint8_t* m , base mlen)
{
    uint8_t* mhelp = (uint8_t*)malloc(sizeof(uint8_t)*mlen);
    uint8_t* bhelp = (uint8_t*)malloc(sizeof(uint8_t)*blen);
    memcpy(mhelp, m, mlen);
    memcpy(bhelp, b, blen);
    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t)*mlen);
    uint8_t* resulthelp = (uint8_t*)malloc(sizeof(uint8_t)*mlen*2);
    uint8_t carry = 0, carryhelp;
    setbig(result, mlen, 0x01);
    do
    {
        carry = 0;
        if(b[blen-1] % 2)
        {
            resulthelp = mulbig(result, mlen, a, alen);
            memcpy(m, mhelp, mlen);
            result = restbig(resulthelp, 2*mlen, m, mlen);
            memcpy(b, bhelp, blen);
        }
        
        for(base i = (base)b; i<(base)b+blen; i++)
        {
            carryhelp = carry;
            carry = (*(uint8_t*)i) & 0x01;
            *(uint8_t*)i = carryhelp*0x80 + ((*(uint8_t*)i) / 2);
        }
        memcpy(bhelp, b, blen);
        resulthelp = mulbig(a, alen, a, alen);
        memcpy(m, mhelp, mlen);
        a = restbig(resulthelp, 2*alen, m, mlen);
        memcpy(b, bhelp, blen);
    }while(!isnull(b, blen));

    return result;
}
boolean isnull(uint8_t* a, base alen)
{
    for(base i = (base)a; i<(base)a+alen; i++)
    {
        if(*(uint8_t*)i != 0) return false;
    }
    return true;
}
boolean setbig(uint8_t* a, base alen, uint8_t to)
{
    for(base i = (base)a; i<(base)a+alen-1; i++)
    {
        *(uint8_t*)i = 0;
    }
    *(uint8_t*)((base)a+alen-1) = to;
    return true;
}


uint8_t* isprime(uint8_t* p, base plen, base exp){

return NULL;
}