//
// Created by Administrator on 2021-10-1.
//

#include "operator.h"
void add(double *dst,double *src)
{
    *dst += *src;
}
void sub(double *dst,double *src)
{
    *dst -= *src;
}
void mult(double *dst,double *src)
{
    *dst *= *src;
}
void map_loss_fuction(double *dst)
{
    *dst = (1/2.0)* pow(*dst,2);
}
void sub1s(double *dst)
{
    *dst = 1 - *dst;
}