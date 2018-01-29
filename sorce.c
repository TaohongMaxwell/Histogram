#include <stdio.h>
#include <stdlib.h>
#define N 10

int a[N]={0};//统计随机数分布的数组
int num[100]={0};//产生随机数的数组

void line()//完善直方图的水平线
{
    printf("--------------------------------------------------------------------------\n");
}
void pr()//打印分类统计后的数据
{
    int i;
    printf("统计结果：\n");
    printf("Value\n");
    for(i=0;i<N;i++){
        printf("%d\t",i);
    }
    putchar('\n');

    printf("Times\n");
    for(i=0;i<N;i++){
        printf("%d\t",a[i]);
    }
    putchar('\n');

}
void in()//获取随机数（伪随机数）
{
    int i;int x=0,y=100;
    for(i=0;i<100;i++){
        num[i]=x+rand()%(y-x+1);//使产生的随机数在[0,100]区间内
    }
}
void judge()//统计随机数所属区间
{
    int i,k;
    for(i=0;i<100;i++){
       k=num[i]/10;
       a[k]++;
    }
}
void graph_1()//自上而下打印直方图
//改进：如果一行中无数据，则跳出本轮循环
{
    int i,j,count;
    printf("\nGraph 1:\n\n");
    for(i=0;i<N;i++){
        printf("%d\t",i);//显示横轴标题
    }
    putchar('\n');
    line();//水平线

    for(i=1;i<20;i++){
        count=0;
            for(j=0;j<10;j++){
                if(a[j]>i||a[j]==i){
                    printf("*");count++;//打印直方图
                }
                putchar('\t');
            }
            putchar('\n');
        if(count==0){
            break;//若行中无内容，跳出循环
        }
    }
}
void graph_2()//自下而上，用正常的方式显示直方图
//待优化：使用判断函数，如果一行中无数据，则删除该行
{
    int i,j,count;
    printf("\nGraph 2:\n\n");
    putchar('\n');
    for(i=1;i<20;i++){
        //count=0;
        for(j=0;j<10;j++){
                if(a[j]>(20-i)||a[j]==(20-i) ){
                    printf("*");count++;//打印直方图
                }
                putchar('\t');
        }
        graph_judge(count);
        putchar('\n');
    }
    line();//水平线

    for(i=0;i<N;i++){
        printf("%d\t",i);//显示纵轴标题
    }
    putchar('\n');
}
void graph_judge(int count)//未完待续
//判断该行中是否有内容，若无，则删除该行
{
    if(count==0){
        putchar('\b');
    }
}
int main()
{
    in();//获取随机数，存入数组num[]中
    judge();//统计随机数所属的区间
    pr();//输出统计表数据

    putchar('\n');
    graph_1();//反序直方图（无行号）
    graph_2();//正序直方图（无行号）

    return 0;
}
