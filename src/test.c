#include "test.h"

extern char error[100];

int main()
{
    base params[2] = {0x400000, 0x1000};
    if(!init(params))
    {
        printf("%s", error);
        abort();
    }
    compl();
    add();

    mul();

    return 0;
}