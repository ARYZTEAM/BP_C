//
// Created by Administrator on 2021-10-1.
//
/*
 * 文件说明，其会将data.txt文件中的train数据和label数据写入到内存中，地址和大小存在全局结构体变量set中，详细见configs.h
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
