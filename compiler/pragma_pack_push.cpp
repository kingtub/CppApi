#include <iostream>

using namespace std;

/*
注：若不用#pragma pack(1)和#pragma pack()括起来，则sample按编译器默认方式对齐（成员中size最大的那个）。
即按8字节（double）对齐，则sizeof(sample)==16.成员char a占了8个字节（其中7个是空字节）；
若用#pragma pack(1)，则sample按1字节方式对齐sizeof(sample)＝＝9.（无空字节），比较节省空间啦，有些场和还可使结构体更易于控制。

#pragma pack(push) //保存对齐状态
#pragma pack(4)//设定为4字节对齐
相当于 #pragma  pack (push,4)

#pragma pack是用来指定数据在内存中的对齐方式。
#pragma pack (n)             作用：C编译器将按照n个字节对齐。
#pragma pack ()               作用：取消自定义字节对齐方式。
#pragma  pack (push,1)     作用：是指把原来对齐方式设置压栈，并设新的对齐方式设置为一个字节对齐
#pragma pack(pop)            作用：恢复对齐状态
*/
struct sample1
{
    char a;
    double b;
};

#pragma pack(push, 8)
struct sample2
{
    char a;
    double b;
};

#pragma pack(pop)

#pragma pack(push, 1)
struct sample3
{
    char a;
    double b;
};

#pragma pack(pop)

int main(int argc, char *argv[])
{
    int n1, n2, n3;
    n1 = sizeof(sample1);
    n2 = sizeof(sample2);
    n3 = sizeof(sample3);

    cout << "n1 = " << n1 << endl; // n1 = 16
    cout << "n2 = " << n2 << endl; // n2 = 16
    cout << "n3 = " << n3 << endl; // n3 = 9

    return 0;
}
