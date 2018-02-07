#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n, g;
    double f1, f2;
    unsigned long long x;

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

        if (0 == g) {
            printf("%g = %g + %g/(2^%d) :: %g + %llu/%llu\n", f1,
                   floor(f1), f2, n, floor(f1), x, 1ULL << n);
        } else {
            printf("-%g = -%g - %g/(2^%d) :: -%g - %llu/%llu\n", f1,
                   floor(f1), f2, n, floor(f1), x, 1ULL << n);
        }
    }

    return 0;
}
