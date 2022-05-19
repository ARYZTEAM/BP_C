//
// Created by Administrator on 2021-10-1.
//
/*
 * 读取set结构体中的内存地址所指向的数据写入二维矩阵中，分别是输入和输出矩阵
 * 该功能可以通过地址偏移和改变Batch_Size读取任意位置，任意函数的矩阵
 * 因而可以对矩阵进行复制，剪切
 */
#ifndef BP_REWRITE_READMEMORY_H
#define BP_REWRITE_READMEMORY_H
#include "configs.h"
#include <assert.h>
#include <malloc.h>
void copy_input_to_matrix(double (*matrix)[INPUT_NUM],int Batch_Size);
void copy_label_to_matrix(double (*matrix)[OUTPUT_NUM],int Batch_Size);
void copy_input_oneline(double *dst,int line);
void copy_label_oneline(double *dst,int line);
#endif //BP_REWRITE_READMEMORY_H
