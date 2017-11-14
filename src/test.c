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
/*
extern base rest_op1_ptr;
extern base rest_op1_len;
extern base rest_op2_ptr;
extern base rest_op2_len;
*/

#define KEYLEN 0x1000

int main()
{

    base* ptrlist[6]= {&compl_op_ptr, &add_op1_ptr, &add_op2_ptr, &mul_op1_ptr, &mul_op2_ptr, &mul_res_ptr};
    base* oplenlist[6]= {&compl_op_len, &add_op1_len, &add_op2_len, &mul_op1_len, &mul_op2_len, &mul_res_len};
    base lenlist[6] = {KEYLEN, KEYLEN, 8, KEYLEN, KEYLEN, KEYLEN*2};
    if(!init(ptrlist, oplenlist, lenlist, 6))
    {
        printf("%s", error);
        abort();
    }
    compl();
    add(0);

    return 0;
}