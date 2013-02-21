#pragma once

long power(long a, long k) {
    long b = 1;
    while (k) {
        if ((k % 2) == 0) {
            k = k / 2;
            a = a * a;
        } else {
            k--;
            b = b * a;
        }
    }
    return b;
}
