//
// Created by Administrator on 2021-10-1.
//

#include "node.h"

void Node_Weight_Init(double *weight,int num)
{
    double *tmp;
    tmp = weight;
    int i = 0;
    while (i < num)
    {
        *tmp++=(rand()%15)/100.0;
        i++;
    }
}
//遍历函数
void Node_Map(node const *nd,unsigned num,void (*map_node)(node *))
{
    node * tmp;
    for (tmp = (node *)nd;tmp <= &nd[num - 1];tmp++)
    {
        map_node(tmp);
    }

}
//随机给权值和初始值赋值
void Node_Value_Init(node *nd)
{
    nd->theta = (rand()%15) / 100.0;

}
//打印出每个节点的值
void Node_Value_Print(node *nd)
{
    printf("theta:%lf value:%lf\n",nd->theta,nd->value);
}

void Node_Input(node *nd)
{
    extern set_return set;
    static int index_to_input = 0;
    int i = 0;
    double sum = 0;
    sum += 
    index_to_input = index_to_input%(SET_NUM*INPUT_NUM);
    while (i<FIRST_LAYER_NODES)
    {
        nd->value = *(set.matrix_ptr_input+index_to_input);
        printf("input value : %lf",nd->value);
        index_to_input++;
        nd++;
        i++;
    }
    putchar('\n');

}
//将输出节点的值写入输出矩阵
void Node_Output_To_Matrix(node * nds,double * dst)
{
    node * tmp = nds + FIRST_LAYER_NODES + SECOND_LAYER_NODES;
    int i=0;
    while (i < OUTPUT_NUM)
    {
        *dst++ = tmp->value;
        tmp++;
        i++;
    }

}
