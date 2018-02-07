typedef struct frac frac;

#ifndef NAT_TYPE
#define NAT_TYPE long long int
#endif

#ifndef NAT_FMT
#define NAT_FMT "%Ld"
#endif

typedef NAT_TYPE nat;

#ifndef REAL_TYPE
#define REAL_TYPE long double
#endif

#ifndef REAL_FMT
#define REAL_FMT "%Lf"
#endif

typedef REAL_TYPE real;

frac *newFrac(nat p, nat q);
void freeFrac(frac * op);
nat num(const frac * op);
nat den(const frac * op);
void add(frac * res, const frac * op1, const frac * op2);
void sub(frac * res, const frac * op1, const frac * op2);
void mul(frac * res, const frac * op1, const frac * op2);
void fdiv(frac * res, const frac * op1, const frac * op2);
void inv(frac * res, const frac * op);
real toReal(const frac * op);
