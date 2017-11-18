#include "test.h"
extern char error[100];

extern base compl_op_ptr;
extern base compl_op_len;

extern base add_op1_ptr;
extern base add_op1_len;
extern base add_op2_ptr;
extern base add_op2_len;

extern base mul_op1_ptr;
extern base mul_op1_len;
extern base mul_op2_ptr;
extern base mul_op2_len;
extern base mul_res_ptr;
extern base mul_res_len;

extern base rest_op1_ptr;
extern base rest_op1_len;
extern base rest_op2_ptr;
extern base rest_op2_len;


#define KEYLEN 0x1000

int main()
{
    base* ptrlist[8]= {&compl_op_ptr, &add_op1_ptr, &add_op2_ptr, &mul_op1_ptr, &mul_op2_ptr, &mul_res_ptr, &rest_op1_ptr, &rest_op2_ptr};
    base* oplenlist[8]= {&compl_op_len, &add_op1_len, &add_op2_len, &mul_op1_len, &mul_op2_len, &mul_res_len, &rest_op1_len, &rest_op2_len};
    base lenlist[8] = {KEYLEN, KEYLEN, 8, KEYLEN, KEYLEN, KEYLEN*2, KEYLEN, KEYLEN};
    if(!init(ptrlist, oplenlist, lenlist, 8))
    {
        printf("%s", error);
        abort();
    }
    compl();
    add(0);
    mul();


    uint8_t a[32] = {16, 0, 0, 0, 86, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
    uint8_t b[32] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01,
                     0x80, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00};
    uint8_t *r = addbig(a, 8, b, 8);
    free(r);
    r = subbig(a, 32, b, 32);
    free(r);
    r = mulbig(a, 32, b, 32);
    free(r);
    for(int i = 0; i<1; i++){
        r = restbig(a, 32, b, 16);
        free(r);
    }


    return 0;
}