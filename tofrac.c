#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frac.h"

static nat gcd(nat a, nat b)
{
    nat d = 0;

    while (((a % 2) == 0) && ((b % 2) == 0)) {
        a /= 2;
        b /= 2;
        d++;
    }

    while (a != b) {
        if ((a % 2) == 0)
            a /= 2;
        else if ((b % 2) == 0)
            b /= 2;
        else if (a > b)
            a = (a - b) / 2;
        else
            b = (b - a) / 2;
    }

    return a * (1ULL << d);
}

static frac *makefrac(char *frac, int *ipart)
{
    char *dp;
    int fp, mult, i;

    *ipart = atoi(frac);
    dp = memchr(frac, '.', strlen(frac));
    pos = dp - frac;

    fp = atoi(dp + 1);

    if (0 == fp) {
        return newFrac(0, 1);
    }

    for (i = 0, mult = 1; '\0' != (dp + 1)[i]; i++, mult *= 10);

    return newFrac(fp, mult);
}

int main(int argc, char *argv[])
{
    int i, n, g;
    double f1, f2;
    nat nm, dn, gd, x;

    for (i = 1; i < argc; i++) {
        g = 1;
        f1 = atof(argv[i]);
        if (f1 < 0) {
            f1 = -f1;
            g = -1;
        }

        if (f1 == floor(f1)) {
            printf("%g == %g\n", f1, floor(f1));
            continue;
        }

        f2 = f1 - floor(f1);

        n = 0;
        x = 0;
        while (f2 != floor(f2)) {
            f2 *= 2;
            if ((((unsigned long long) floor(f2)) % 2) == 0) {
                x *= 2;
            } else {
                x = (x * 2) + 1;
            }

            n++;
        }

        gd = gcd(x, (nat) (1ULL << n));
        nm = x / gd;
        dn = (1ULL << n) / gd;

        printf("%g\t%g %s " NAT_FMT "/" NAT_FMT "\n", g * f1,
               g * floor(f1), (-1 == g) ? "-" : "+", nm, dn);
    }

    return 0;
}
