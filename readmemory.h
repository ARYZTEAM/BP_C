//
// Created by Administrator on 2021-10-1.
//
/*
 * ��ȡset�ṹ���е��ڴ��ַ��ָ�������д���ά�����У��ֱ���������������
 * �ù��ܿ���ͨ����ַƫ�ƺ͸ı�Batch_Size��ȡ����λ�ã����⺯���ľ���
 * ������ԶԾ�����и��ƣ�����
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
