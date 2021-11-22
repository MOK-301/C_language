#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>//bool函数

struct Node *real;//尾指针，全局变量
bool temp = true;//标志位
struct Node
{
    int data;
    struct Node* next;
};

//创建带头结点链表
struct Node* createLink()
{
    struct Node *headNode = (struct Node *)malloc(sizeof(struct Node));
    headNode->next = NULL;//头结点没有数据域，指针域指向NULL
    return headNode;
}

//打印链表
void printfLink(struct Node* link)
{
    struct Node *qMove = link->next;
    while(qMove)
    {
        printf("%d %p\n", qMove->data,qMove->next);
        qMove = qMove->next;
    }
}

//创建新结点
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//尾插法
void insertNode_w(struct Node* Link,int data)
{
    struct Node* newNode = createNode(data);
    if(temp)//设置标志位，因为此方法已封装，若无标志位，每次调用都会初始化尾指针
    {
        real = Link;
        temp = false;
    }
    newNode->next = real->next;
    real->next = newNode;
    real = newNode;//尾指针指向新的结点

}
void delNode(struct Node* link,int data)
{
    struct Node *posNode = link->next;//设置指向第一个结点的指针
    struct Node *posNodeFront = link;//将链表指向指针，修改指针域
    if (posNode == NULL)
    {
        printf("空链表！\n");
    }else
    {
        while(posNode->data!=data)
        {
            posNodeFront = posNode;//临时指针指向另一个指针
            posNode = posNodeFront->next;//移动到下一个结点
            if (posNode == NULL)//判断是否为NULL，最后一个结点
            {
                printf("没有找到相关的信息！\n");
                return;

            }
        }
        posNodeFront->next = posNode->next;//因为数据域匹配，将被删除结点的next传送至上一结点的next
        free(posNode);//将要删除的结点释放
    }

}

int main(void)
{
    struct Node *link = createLink();
    insertNode_w(link, 1);
    insertNode_w(link, 2);
    insertNode_w(link, 3);
    printfLink(link);
    delNode(link, 2);
    printfLink(link);
    return 0;
}
