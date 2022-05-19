//
// Created by Administrator on 2021-10-1.
//

#ifndef BP_REWRITE_UPDATE_H
#define BP_REWRITE_UPDATE_H
#include "configs.h"
#include "matrix.h"
#include "operator.h"
#include "readmemory.h"
static double calcu_w_theta(void );
void fuc_mutl_alpha(double *dst);
static void array_copy(double *dst,double *src,int size);
void read_nodes_to_matrix(node *nds);
void update_theta(double *output);
void write_theta(node * nds);
void update_weight();
void print_read();

#endif //BP_REWRITE_UPDATE_H
