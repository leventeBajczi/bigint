#include "test.h"

extern char error[100];

int main()
{
    base params[2] = {0x80, 0x10};
    if(!init(params))
    {
        printf("%s", error);
        abort();
    }
    compl();

    while(1);
    return 0;
}