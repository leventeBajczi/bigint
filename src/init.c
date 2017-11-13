#include "init.h"
base *addr = 0x0, len = 0x0, *ptr = 0x0, keylen = 0x0;  

char error[100];

boolean init(base *params)
{
    len = params[0];
    keylen = params[1];
    if(!allocate_safemem()) 
    {
        strcpy(error, "Failed to allocate memory, quitting...\n\0");
        return false;
    }
    if(!test_mem()) 
    {
        strcpy(error, "Bad allocated memory, quitting...\n\0");
        return false;
    }

    return true;

}

boolean allocate_safemem()
{
    if(mlockall(MCL_FUTURE)) return false;           //Set all future mmaps unswappable
    addr = (base*) mmap(NULL, len, 0x3, 0x22, 1, 0);  //addr = NULL, len = len, prot = 0x2 | 0x1 (Read and write), flags = 0x20 | 0x2 (private and anonym), fd = 1 (standard out), offset = 0
    if(!addr) return false;
    return true;
}


boolean del()
{
    if(!test_mem()) return false;
    return true;
}

boolean test_mem()
{   
    base testdata = 0xaabbccddeeff0012;
    for(base i = 0; i < len/8; i++)
    {
        *(addr+i) = testdata;
        if(*(addr+i) != testdata) return false;
    }
    return true;
}