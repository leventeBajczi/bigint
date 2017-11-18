#include "test.h"

#include <time.h>
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


extern base powm_op1_ptr;
extern base powm_op1_len;
extern base powm_op2_ptr;
extern base powm_op2_len;
extern base powm_op3_ptr;
extern base powm_op3_len;
extern base powm_res_ptr;
extern base powm_res_len;


#define KEYLEN    0x1000

int main()
{
   base *ptrlist[12]   = { &compl_op_ptr, &add_op1_ptr, &add_op2_ptr, &mul_op1_ptr, &mul_op2_ptr, &mul_res_ptr, &rest_op1_ptr, &rest_op2_ptr, &powm_res_ptr, &powm_op1_ptr, &powm_op2_ptr, &powm_op3_ptr };
   base *oplenlist[12] = { &compl_op_len, &add_op1_len, &add_op2_len, &mul_op1_len, &mul_op2_len, &mul_res_len, &rest_op1_len, &rest_op2_len, &powm_res_len, &powm_op1_len, &powm_op2_len, &powm_op3_len };
   base  lenlist[12]   = { KEYLEN, KEYLEN, 8, KEYLEN, KEYLEN, KEYLEN * 2, KEYLEN, KEYLEN, KEYLEN, KEYLEN, KEYLEN, KEYLEN };

   if (!init(ptrlist, oplenlist, lenlist, 12))
   {
      printf("%s", error);
      abort();
   }
   uint8_t *r;
   for (int i = 0; i < 1; i++)
   {
      base time = clock();

      uint8_t a[256] = { 0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01,
                         0x80, 0x00, 0xa0, 0x00, 0x05, 0x00, 0x00, 0x00 };
      uint8_t b[256] = { 0x00,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0xa0, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x02, 0x80, 0x10, 0x04, 0x0a, 0x0b, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01,
                         0x80, 0x00, 0xa0, 0x00, 0x05, 0x00, 0x00, 0x00 };

      r = powmodulo(a, 256, b, 256, b, 256);
      free(r);
      printf("%lu", (clock() - time) / CLOCKS_PER_SEC);
   }
   del(ptrlist, lenlist, 12);


   return(0);
}
