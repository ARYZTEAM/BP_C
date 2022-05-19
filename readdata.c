//
// Created by Administrator on 2021-10-1.
//

#include "readdata.h"
static FILE *fp(char *filename)
{
    FILE *fp;
    fp = fopen(filename,"r");
    if (fp == NULL)
    {
        perror("data.txt");
        exit(1);
    }
    return fp;
}
//多文件处理逻辑还没写。。。
int file_read(int arg_n,...)
{
    extern set_return set;
    FILE *f_obj;
    if (0)//arg_n != 0
    {
        va_list va;
        va_start(va,arg_n);
        char * filename;
        while (arg_n-->0)
        {
            filename = va_arg(va,char *);
            read_set(fp(filename));
        }
        va_end(va);
        return 0;


    } else
    {
        atexit(free_memory);
        read_set(fp("data.txt"));
        printf("%d %d %d\n",set.set_num,set.input_num,set.output_num);
        return 0;
    }


//    fscanf();
}

static void read_set(FILE * fobj)
{
    extern set_return set;
    int set_num,input_num,output_num;
    double * mem_ptr_input,*mem_ptr_label;
    double input,label;
    if(fscanf(fobj,"%d %d %d",&set_num,&input_num,&output_num) != 3)
    {
        printf("Wrong data format!\n");
        exit(1);
    }
    set.set_num = set_num;
    set.input_num = input_num;
    set.output_num = output_num;

    mem_ptr_input = (double *)malloc(sizeof(double ) * set_num * input_num);
    mem_ptr_label = (double *)malloc(sizeof(double ) * set_num * output_num);
    set.matrix_ptr_input = mem_ptr_input;
    set.matrix_ptr_label = mem_ptr_label;
    char *index,*bufz;
    fgets(buffer,BUFSIZ,fobj);

    if (mem_ptr_input != NULL && mem_ptr_label != NULL)
    {
        for (set_num = set.set_num,bufz = buffer;set_num > 0;set_num--)
        {

            if (fgets(buffer,BUFSIZ,fobj)==NULL)
            {
                printf("Wrong fgets format!\n");
                exit(1);
            }
//            puts(buffer);
            for (input_num = set.input_num,bufz = buffer;input_num > 0;input_num--)
            {
                input=strtod(bufz,&index);
                bufz = index;
                *mem_ptr_input++ = input;
//                printf("input : %lf\t",input);
            }

        }
        for (set_num = set.set_num,bufz = buffer;set_num > 0;set_num--)
        {

            if (fgets(buffer,BUFSIZ,fobj)==NULL)
            {
                printf("Wrong fgets format!\n");
                exit(1);
            }
            for (output_num = set.output_num,bufz = buffer;output_num > 0;output_num--)
            {
                label=strtod(bufz,&index);
                bufz = index;
                *mem_ptr_label++ = label;
            }

        }
    } else
    {
        perror("memory out of range\n");
        exit(1);
    }

    fclose(fobj);


//    free(mem_ptr);
}

void free_memory(void)
{
    extern set_return set;
    free(set.matrix_ptr_input);
    free(set.matrix_ptr_label);
}
