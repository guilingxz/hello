#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list_node
{
	int data;
	struct list_node *next;
};

typedef struct list_node list_single;
list_single *create_list_node(int data)
{
	list_single *node = NULL;
	node = (list_single *)malloc(sizeof(list_single));
	if (node == NULL)
	{
		printf("malloc fair!\n");
	}
	memset(node, 0, sizeof(list_single));
	node->data = data;
	node->next = NULL;
	return node;
}
int main(void)
{
	int data = 100;
	list_single *node_ptr = create_list_node(data); //创建一个节点
	printf("node_ptr->data=%d\n", node_ptr->data);	//打印节点里的数据
	printf("node_ptr->next=%d\n", node_ptr->next);
	free(node_ptr);
	return 0;
}

//尾插法
//访问头节点
struct list*p =header;

//判断是不是最后一个节点，如果不是，则往后移，如是，将new节点插入
while(NULL != p->next)
p=p->next;
p->next=new;


struct list*p =header;
struct list*p=heater;

while(NULL != p->next)
p=p->next;
p->next=new;

//头插法
struct list*p=header;
new->next = p -> next;
p->next=new;

//双链表插入
s->next=p->next;
p->next->prior=s;
s->prior=p;
p->next=s;

//双链表的删除
p->next=q->next;
q->next->prior=p;
free(q);
