#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "frac.h"

int main(int argc, char *argv[])
{
    frac *frac1;
    int i, n, g;
    double f1, f2;
    nat x;

    for (i = 1; i < argc; i++) {
        g = 0;
        f1 = atof(argv[i]);
        if (f1 < 0) {
            f1 = -f1;
            g = 1;
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

        if (1 == g) {
            x = -x;
        }

        if ((frac1 = newFrac(x, (nat) (1ULL << n))) == NULL) {
            fprintf(stderr, "tofrac: MEMORY ERROR!!!\n");
            exit(EXIT_FAILURE);
        }

        printf("%g\t" NAT_FMT "/" NAT_FMT "\n", f1, num(frac1),
               den(frac1));

        freeFrac(frac1);
    }

    return 0;
}
