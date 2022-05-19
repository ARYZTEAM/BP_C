//
// Created by Administrator on 2021-10-1.
//

#include "readmemory.h"
//注意这里加了个验证，需要一致
//复制输入矩阵
void copy_input_to_matrix(double (*matrix)[INPUT_NUM],int Batch_Size)
{
    extern set_return set;
    double * tmp = *matrix;
    double * input_ptr = set.matrix_ptr_input;
    assert(INPUT_NUM == set.input_num);
    assert(Batch_Size <= set.set_num);
    while (tmp <= &matrix[Batch_Size - 1][INPUT_NUM - 1])
    {
        *tmp++ = *input_ptr++;
    }


}
//复制标签矩阵
void copy_label_to_matrix(double (*matrix)[OUTPUT_NUM],int Batch_Size)
{
    extern set_return set;
    double * tmp = *matrix;
    double * label_ptr = set.matrix_ptr_label;
    assert(OUTPUT_NUM == set.output_num);
    assert(Batch_Size <= set.set_num);
    while (tmp <= &matrix[Batch_Size - 1][OUTPUT_NUM - 1])
    {
        *tmp++ = *label_ptr++;
    }

}
void copy_input_oneline(double *dst,int line)
{
    extern set_return set;
    double * input_ptr = set.matrix_ptr_input + (line-1) * INPUT_NUM;
    int i = 0;
    while (i < INPUT_NUM)
    {
        *dst++ = *input_ptr++;
        i++;
    }
}
void copy_label_oneline(double *dst,int line)
{
    extern set_return set;
    double * label_ptr = set.matrix_ptr_label + (line - 1)* OUTPUT_NUM;
    int i = 0;
    while (i < OUTPUT_NUM)
    {
        *dst++ = *label_ptr++;
        i++;
    }
}