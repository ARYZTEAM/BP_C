//
// Created by Administrator on 2021-10-1.
//

#ifndef BP_REWRITE_NODE_H
#define BP_REWRITE_NODE_H
#include <stdlib.h>
#include "configs.h"
#include <stdio.h>
void Node_Weight_Init(double *weight,int num);
void Node_Map(node const *nd,unsigned num,void (*map_node)(node *));
void Node_Value_Init(node *nd);
void Node_Value_Print(node *nd);
void Node_Input(node *nd);
void Node_Output_To_Matrix(node * nds,double * dst);

#endif //BP_REWRITE_NODE_H
