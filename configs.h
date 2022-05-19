//
// Created by Administrator on 2021-10-1.
//

#ifndef BP_REWRITE_CONFIGS_H
#define BP_REWRITE_CONFIGS_H

#define DEBUG printf("%s on line %d is successful execute!\n",__FILE__,__LINE__)
#define PRINT_NODE(node) printf("theta:%lf weight:%lf\n",node.theta,node.weight)
#define SET_NUM (150)
#define INPUT_NUM (4)
#define OUTPUT_NUM (3)
#define FIRST_LAYER_NODES (INPUT_NUM)
#define SECOND_LAYER_NODES (5)
#define THIRD_LAYER_NODES (OUTPUT_NUM)
#define SUM_NODES   (FIRST_LAYER_NODES+SECOND_LAYER_NODES+THIRD_LAYER_NODES)
//sigmoid�����ĵ���ֵ
#define U0 (1)
//�����ȵ�����
#define BETA (-0.01)
//����weight������
#define ALPHA   (0.01)

//M��������ֵΪM����
//N�������ΪNά
typedef struct
{
    double theta;
    double value;

}node;


typedef struct
{
    int set_num;
    int input_num;
    int output_num;
    double *matrix_ptr_input;
    double *matrix_ptr_label;
}set_return;


#endif //BP_REWRITE_CONFIGS_H
