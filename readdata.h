//
// Created by Administrator on 2021-10-1.
//
/*
 * �ļ�˵������Ὣdata.txt�ļ��е�train���ݺ�label����д�뵽�ڴ��У���ַ�ʹ�С����ȫ�ֽṹ�����set�У���ϸ��configs.h
 */
#ifndef BP_REWRITE_READDATA_H
#define BP_REWRITE_READDATA_H
#include "configs.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
static char buffer[BUFSIZ];
int file_read(int arg_n,...);
static FILE *fp(char *filename);
static void read_set(FILE * fobj);
void free_memory(void);
#endif //BP_REWRITE_READDATA_H
