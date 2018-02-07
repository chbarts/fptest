#include <stdlib.h>
#include "frac.h"

struct frac {
    nat num;
    nat den;
};

static nat gcd(nat num1, nat num2)
{
    while (num1 != num2) {
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }

    return num1;
}

static void reduce(frac * op)
{
    nat com;

    if (op->den == 0)
        op->den = 1;

    if (op->num != 0) {
        com = gcd(op->num, op->den);
        op->num /= com;
        op->den /= com;
    }
}

#define mabs(n) ((n) < 0 ? -(n) : (n))

static void adj(frac * res)
{
    if (res->num == 0)
        return;

    if ((res->num < 0) || (res->den < 0)) {
        res->num = mabs(res->num);
        res->den = mabs(res->den);
        reduce(res);
        res->num = -res->num;
    } else {
        reduce(res);
    }
}

frac *newFrac(nat numer, nat denom)
{
    frac *nf;

    if (!(nf = malloc(sizeof(struct frac))))
        return NULL;

    nf->num = numer;
    nf->den = denom;
    adj(nf);
    return nf;
}

void freeFrac(frac * op)
{
    free(op);
}

nat num(const frac * op)
{
    return op->num;
}

nat den(const frac * op)
{
    return op->den;
}

void add(frac * res, const frac * op1, const frac * op2)
{
    res->num = op1->num * op2->den + op2->num * op1->den;
    res->den = op1->den * op2->den;

    adj(res);
}

void sub(frac * res, const frac * op1, const frac * op2)
{
    res->num = op1->num * op2->den - op2->num * op1->den;
    res->den = op1->den * op2->den;

    adj(res);
}

void mul(frac * res, const frac * op1, const frac * op2)
{
    res->num = op1->num * op2->num;
    res->den = op1->den * op2->den;
    adj(res);
}

void fdiv(frac * res, const frac * op1, const frac * op2)
{
    inv(res, op2);
    mul(res, op1, res);
}

void inv(frac * res, const frac * op)
{
    res->num = op->den;
    res->den = op->num;
    adj(res);
}

real toReal(const frac * op)
{
    return ((real) op->num) / ((real) op->den);
}
