//
// Created by Administrator on 2021-10-1.
//

#include "update.h"
static double value1[SECOND_LAYER_NODES];
static double value2[THIRD_LAYER_NODES];
static double theta1[SECOND_LAYER_NODES];
static double theta2[THIRD_LAYER_NODES];
static double label_index[OUTPUT_NUM];
static double input_index[FIRST_LAYER_NODES];
static void array_copy(double *dst,double *src,int size)
{
    register double *tmp1 = dst;
    register double *tmp2 = src;
    while (tmp1 <= dst + size - 1 )
    {
        *tmp1++ = *tmp2++;
    }
}

//static void Matrix_Mult(double (*wjk)[THIRD_LAYER_NODES],double * thetak,double * result)
//{
//
//
//}


void print_read()
{
    int i;
    for (i = 0; i < SECOND_LAYER_NODES; i++) {
        printf("value1:%lf\tthete1:%lf\n",value1[i],theta1[i]);

    }
    for (i = 0; i < THIRD_LAYER_NODES; i++) {
        printf("value2:%lf\tthete2:%lf\n",value2[i],theta2[i]);

    }
    for (i = 0; i < FIRST_LAYER_NODES; i++) {
        printf("inpput:%lf\n",input_index[i]);

    }
    for (i = 0; i < OUTPUT_NUM; i++) {
        printf("label:%lf\n",label_index[i]);

    }
}


void read_nodes_to_matrix(node *nds)
{
    node *tmp = nds+FIRST_LAYER_NODES;
    extern int index_output_row;
    int i;
    for (i = 0; i < SECOND_LAYER_NODES; i++) {
        value1[i] = tmp->value;
        theta1[i] = tmp->theta;
        tmp++;
    }
    for (i = 0; i < THIRD_LAYER_NODES; i++) {
        value2[i] = tmp->value;
        theta2[i] = tmp->theta;
        tmp++;
    }
    copy_label_oneline(label_index,index_output_row);
    copy_input_oneline(input_index,index_output_row);

}

void update_theta(double *output)
{
    double tmp_label[OUTPUT_NUM];
    double tmp_output[OUTPUT_NUM];
    array_copy(tmp_label,label_index,OUTPUT_NUM);
    array_copy(tmp_output,output,OUTPUT_NUM);
    Matrix_Operations(tmp_label,tmp_output,OUTPUT_NUM,sub);
    Matrix_Mapping(tmp_output,OUTPUT_NUM,sub1s);
    Matrix_Operations(tmp_label,tmp_output,OUTPUT_NUM,mult);
    Matrix_Operations(tmp_label,output,OUTPUT_NUM,mult);
    array_copy(theta2,tmp_label,OUTPUT_NUM);



    extern double (*weight_second_third)[THIRD_LAYER_NODES];

    double wjk_thetak[SECOND_LAYER_NODES];
    double sum;
    for ( int i = 0; i < SECOND_LAYER_NODES; ++i) {
        for (int j = 0; j < 1; ++j)
        {
            sum = 0;
            for (int k = 0;k< THIRD_LAYER_NODES;k++)
            {
                sum +=  weight_second_third[SECOND_LAYER_NODES - 1][k] * theta2[k];
            }
            wjk_thetak[i] = sum;
        }


    }


    double value1_cpy[SECOND_LAYER_NODES];
    array_copy(value1_cpy,value1,SECOND_LAYER_NODES);
    Matrix_Mapping(value1_cpy,SECOND_LAYER_NODES,sub1s); //value_cpy = 1- Yj

    sum = Matrix_Single_Mult(value1_cpy,wjk_thetak,SECOND_LAYER_NODES);
    //赋值
    array_copy(theta1,value1,SECOND_LAYER_NODES);
    for (int i = 0; i < SECOND_LAYER_NODES; ++i) {
        theta1[i] *= sum;
    }

}
void write_theta(node * nds)
{
    node *tmp = nds+FIRST_LAYER_NODES;
    int i;
    for (i = 0; i < SECOND_LAYER_NODES; i++) {
        tmp->theta += theta1[i]*BETA;
        tmp++;
    }
    for (i = 0; i < THIRD_LAYER_NODES; i++) {
        tmp->theta += theta2[i]*BETA;
        tmp++;
    }}
void update_weight()
{
    extern double (*weight_second_third)[THIRD_LAYER_NODES];
    double weight_tmp[SECOND_LAYER_NODES][THIRD_LAYER_NODES];
    Matrix_Point_Multiply(value1,theta2,&weight_tmp[0][0],SECOND_LAYER_NODES,OUTPUT_NUM);
    Matrix_Mapping(&weight_tmp[0][0],SECOND_LAYER_NODES*OUTPUT_NUM,fuc_mutl_alpha);
    Matrix_Operations(&weight_second_third[0][0],&weight_tmp[0][0],SECOND_LAYER_NODES*OUTPUT_NUM,add);
//    printf("\n--------权值第二层指向第三层：--------\n");
//
//    Print_Memory(&weight_second_third[0][0],THIRD_LAYER_NODES,SECOND_LAYER_NODES);


    extern double (*weight_first_second)[SECOND_LAYER_NODES];
    double weight_tmp2[FIRST_LAYER_NODES][SECOND_LAYER_NODES];
    Matrix_Point_Multiply(input_index,theta1,&weight_tmp2[0][0],FIRST_LAYER_NODES,SECOND_LAYER_NODES);
    Matrix_Mapping(&weight_tmp2[0][0],FIRST_LAYER_NODES*SECOND_LAYER_NODES,fuc_mutl_alpha);
    Matrix_Operations(&weight_first_second[0][0],&weight_tmp2[0][0],FIRST_LAYER_NODES*SECOND_LAYER_NODES,add);
//    printf("\n--------权值第一层指向第二层：--------\n");
//
//    Print_Memory(&weight_first_second[0][0],SECOND_LAYER_NODES,FIRST_LAYER_NODES);


}

void fuc_mutl_alpha(double *dst)
{
    *dst = ALPHA * (*dst);

}

static double calcu_w_theta(void )
{
    double sum = 0;
    double tmp = 0;
    extern double (*weight_second_third)[THIRD_LAYER_NODES];
    int i,j;
    for (i = 0; i < THIRD_LAYER_NODES; i++) {

        for(tmp = 0,j = 0;j < SECOND_LAYER_NODES;j++)
        {
            tmp += weight_second_third[j][i];
        }
        sum+=theta2[i]*tmp;

    }
    return sum;
}