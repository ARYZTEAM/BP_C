//
// Created by Administrator on 2021-10-1.
//

#ifndef BP_REWRITE_MATRIX_H
#define BP_REWRITE_MATRIX_H
#include "configs.h"
#include <stdio.h>
#include <stdlib.h>
void Print_Memory(double *addr,int column,int row);
void Print_Matrix_Input(void);
void Print_Matrix_Label(void);
void Matrix_Operations(double *dst,double *src, int num, void (* oper)(double *dst ,double *src ));
void Matrix_Mapping(double *dst, int num,  void (* map_func)(double *));
double Matrix_Terms_Sum(double *dst,int num);
void Matrix_Point_Multiply(double * A,double *B,double *AB,unsigned A_num,unsigned B_num);
void Matrix_Mult(double *m1,int m1_m, int m1_n,double *m2,int m2_m,int m2_n,double *reslut);
double Matrix_Single_Mult(double *m1,double *m2,int num);
#endif //BP_REWRITE_MATRIX_H
