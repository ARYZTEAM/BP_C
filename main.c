#include <stdio.h>
#include <time.h>
#include "readdata.h"
#include "matrix.h"
#include "readmemory.h"
#include "operator.h"
#include "node.h"
#include "fuction.h"
#include "update.h"
//configs.h已经被readdata.h包括进去了
int index_output_row = 0;
set_return set;
//set一定要定义为全局变量

double (*weight_first_second)[SECOND_LAYER_NODES];
double (*weight_second_third)[THIRD_LAYER_NODES];
double test[3];
//指针指向权值关系
//参数值全都按实际输入就行了
//转移函数
void Func_Transfer(node * nodes)
{
    node *tmp,*node_init;
    int i,j;
    double sum;
    //隐层的计算

    for (tmp = nodes + FIRST_LAYER_NODES, i =0;i < SECOND_LAYER_NODES; i++,tmp++)
    {
        for (j = 0,sum = 0,node_init = nodes; j < FIRST_LAYER_NODES;j++){
            sum +=node_init->value * weight_first_second[j][i];
            node_init++;
        }
        sum -= tmp->theta;
        tmp->value = Sigmoid(sum);
    }

    //输出层计算
    for(tmp = nodes + FIRST_LAYER_NODES + SECOND_LAYER_NODES, i =0;i < THIRD_LAYER_NODES; i++,tmp++)
    {
        for (j = 0,sum = 0,node_init = nodes + FIRST_LAYER_NODES; j < SECOND_LAYER_NODES;j++)
        {
            sum +=  node_init->value * weight_second_third[j][i];
            node_init++;
        }
        sum-=tmp->theta;
        tmp->value = Sigmoid(sum);
    }


}

double Fuc_Loss(double *output)
{
    extern int index_output_row;
    double label_one_line[OUTPUT_NUM];
    index_output_row = (index_output_row%SET_NUM) + 1;
    copy_label_oneline(label_one_line,index_output_row);
    printf("\nCORRET ANSER IS :\n");
    Print_Memory(label_one_line,OUTPUT_NUM,1);
    test[0] = label_one_line[0];
    test[1] = label_one_line[1];
    test[2] = label_one_line[2];
    Matrix_Operations(label_one_line,output,OUTPUT_NUM,sub);
    Matrix_Mapping(label_one_line,OUTPUT_NUM,map_loss_fuction);
    return Matrix_Terms_Sum(label_one_line,OUTPUT_NUM);
}

double getaver(double losses)
{
    static int i = 0;
    static double sum = 25;
    i++;
    if (i>25)
    {
        double tmp = sum;
        sum = 0;
        i = 0;
        return tmp / 25.0;

    }
    sum += losses;
    return 1;

}



int main() {
    srand(time(0));
    double losses = 1;

    file_read(0);//多文件读取暂时没有完成，参数随便



    double relation1_2[FIRST_LAYER_NODES][SECOND_LAYER_NODES];
    double relation2_3[SECOND_LAYER_NODES][THIRD_LAYER_NODES];
    weight_first_second = relation1_2;
    weight_second_third = relation2_3;

    Node_Weight_Init(&relation1_2[0][0],sizeof(relation1_2)/sizeof(relation1_2[0][0]));
    Node_Weight_Init(&relation2_3[0][0],sizeof(relation2_3)/sizeof(relation2_3[0][0]));


    node nds[SUM_NODES];
    double node_output[OUTPUT_NUM];
    int i = 0;
    int flag=1;
    Node_Map(nds,SUM_NODES,Node_Value_Init);
    double lossesss = 0;
    while (losses >= 0.0001)
    {
//        printf("the %d\n",i+1);
        Node_Input(nds);
        Func_Transfer(nds);
        Node_Output_To_Matrix(nds,node_output);
        printf("output is :\n");
        Print_Memory(node_output,OUTPUT_NUM,1);
        losses = Fuc_Loss(node_output);
        printf("fuction losses is %lf\n",losses);
        lossesss = getaver(losses);
        if ((lossesss >= 0.01) && flag)//调整部分
        {
            read_nodes_to_matrix(nds);
            update_theta(node_output);
            write_theta(nds);
            update_weight();
        } else
        {
            flag = 0;
            static int j = 0,k = 0;
            k++;
            printf("the %d\n",k+1);
            int a = 0;
            int b = 0;
            int c = 0;
            a = (test[0] == 1) && (node_output[0] >= node_output[1]) &&(node_output[0]>= node_output[2]);
            b = (test[1] == 1) && (node_output[1] >= node_output[0]) &&(node_output[1]>= node_output[2]);
            c = (test[2] == 1) && (node_output[2] >= node_output[1]) &&(node_output[2]>= node_output[0]);
            if (a||b||c)
            {
                j++;
            }
            printf("当前正确率为：%lf\n",j/(double)(k));

        }

        i++;
    }
    return 0;
}

