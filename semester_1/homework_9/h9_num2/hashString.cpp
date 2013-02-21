#include <string.h>
#include "hashString.h"
#include "pppower.h"

void hash(char *str1, char *str2, int len, int &h1, int &h2) {
    h1 = 0;
    h2 = 0;
    for (int i = 0; i < len; ++i)
    {
        h1 = (h1 * base + str1[i]);
        h2 = (h2 * base + str2[i]);
    }
}

int reHash(int old, int subt, int add, int d) {
    return ((old - subt * d) * base + add);
}

int search(char *str, char *ptr)
{
    int sLen = strlen(str);
    int pLen = strlen(ptr);
    int d = power(base, pLen - 1);

    int p = 0;
    int t = 0;
    hash(ptr, str, pLen, p, t);

    for (int i = 0; i <= sLen - pLen; ++i)
    {
        if (p == t)
        {
            bool f = true;
            for (int j = 0; j < pLen; ++j)
                if (ptr[j] != str[i + j])
                {
                    f = false;
                    break;
                }
            if (f)
                return i;
        }
        if (i < sLen - pLen)
            t = reHash(t, str[i], str[i + pLen], d);
    }
    return -1;
}
