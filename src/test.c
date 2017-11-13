#include "test.h"

extern char error[100];

int main()
{
    base params[2] = {0x100000, 0x200};
    if(!init(params))
    {
        printf("%s", error);
        abort();
    }

    while(1);
    return 0;
}