//
// Created by Administrator on 2021-10-1.
//

#include "fuction.h"
//sigmoidº¯Êý
double Sigmoid(double value)
{
    double tmp = 1.0 + exp(-2*value/(double)U0) ;
    return (1.0/tmp);

}

