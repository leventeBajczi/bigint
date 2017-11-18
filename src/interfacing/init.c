#include "headers/init.h"

char error[100];

boolean init(base **ptrs, base **oplens, base *lens, uint8_t len)
{
   for (int i = 0; i < len; i++)
   {
      *(oplens[i]) = lens[i];
      if (!allocate_safemem(ptrs[i], lens[i]))
      {
         strcpy(error, "Failed to allocate memory, quitting...\n\0");
         return(false);
      }

      if (!test_mem(ptrs[i], lens[i]))
      {
         strcpy(error, "Bad allocated memory, quitting...\n\0");
         return(false);
      }
   }

   return(true);
}

boolean allocate_safemem(base *ptr, base len)
{
   if (mlockall(MCL_FUTURE))
   {
      return(false);                                 //Set all future mmaps unswappable, call after every iteration (cheap, and "to be sure")
   }
   *ptr = (base)mmap(NULL, len, 0x3, 0x22, 1, 0);    //addr = NULL, len = len, prot = 0x2 | 0x1 (Read and write), flags = 0x20 | 0x2 (private and anonym), fd = 1 (standard out), offset = 0
   if (!*ptr)
   {
      return(false);
   }
   return(true);
}

boolean del(base **ptrs, base *lens, uint8_t len)
{
   for (int i = 0; i < len; i++)
   {
      if (!test_mem(ptrs[i], lens[i]))
      {
         return(false);
      }
      munmap(ptrs[i], lens[i]);
   }
   return(true);
}

boolean test_mem(base *ptr, base len)
{
   base testdata = 0x00;

   for (base i = 0; i < len; i += sizeof(base))
   {
      *(base *)(*ptr + i) = testdata;
      if (*(base *)(*ptr + i) != testdata)
      {
         return(false);
      }
   }
   return(true);
}
