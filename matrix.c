//
// Created by Administrator on 2021-10-1.
//

#include "matrix.h"
//对内存地址进行打印，注意是double类型的指针，每column打印一个换行符号
void Print_Memory(double *addr,int column,int row)
{
    int i;
    for (i = 0;i<=(column* row - 1);i++)
    {
        if ( i % column == 0)putchar('\n');
        printf("%lf\t" ,*addr++);
    }

}
//打印输入的矩阵
void Print_Matrix_Input(void)
{
    extern set_return set;
    Print_Memory(set.matrix_ptr_input,set.input_num,set.set_num);
}
//打印输出的矩阵
void Print_Matrix_Label(void)
{
    extern set_return set;
    Print_Memory(set.matrix_ptr_label,set.output_num,set.set_num);
}
//将矩阵dst加上减去或者乘上src,num为矩阵的总的大小
void Matrix_Operations(double *dst,double *src, int num, void (* oper)(double *dst ,double *src ))
{
    register double * dst_tmp = dst;
    register double * src_tmp = src;
    int i = 0;
    while (i < num )
    {
        oper(dst_tmp++,src_tmp++);
        i++;
    }

}
//将矩阵中的每个值代入函数获得新矩阵
void Matrix_Mapping(double *dst, int num,  void (* map_func)(double *))
{
    register double *tmp = dst;
    int i = 0;
    while (i < num )
    {
        map_func(tmp++);
        i++;
    }


}

//将矩阵中每项相加 const * matrix指向一个常数矩阵
double Matrix_Terms_Sum(double *dst,int num)
{
    register double *tmp = dst;
    double sum = 0;
    int i = 0;
    while (i < num)
    {
        sum += *tmp++;
        i++;
    }
    return sum;
}

//A是横的向量，B是纵向量
void Matrix_Point_Multiply(double * A,double *B,double *AB,unsigned A_num,unsigned B_num)
{
    register double *tmp1 ;
    register double *tmp2 ;
    for (tmp1 = A; tmp1 <= A +  A_num - 1; tmp1++) {
        for (tmp2 = B; tmp2 <= B +  B_num - 1; tmp2++) {

            *AB++ = (*tmp1) * (*tmp2);
        }

    }

}

//两个一维矩阵正交相乘的结果,待优化
double Matrix_Single_Mult(double *m1,double *m2,int num)
{
    int i = 0;
    double sum = 0;
    while (i < num)
    {
        sum += m1[i] * m2[i];
        i++;
    }
    return sum;
}


//当两个矩阵正交的时候传入六个参数
void Matrix_Mult(double *m1,int m1_m, int m1_n,double *m2,int m2_m,int m2_n,double *reslut)
{
    int i,j,k;
    if (m1_n != m2_m)
    {
        printf("parameter error!\n");
        exit(1);
    }
    double sum;
    for ( i = 0; i < m1_m; ++i) {
        for (j = 0; j < m2_n; ++j) {


            for (k = 0,sum = 0;k< m1_n;k++)
            {
//                sum += m1[m1_m][k] * m2[k][j];
                sum += *(m1 + m1_m * i + k) * *(m2 + k * m2_m + j);
            }
//            reslut[i][j] = sum;
            *(reslut+ i* m1_m +j) = sum;

        }
    }
}