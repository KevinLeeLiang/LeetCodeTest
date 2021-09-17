# Add Two Numbers
## 题目
You are given two non-empty linked lists representing two non-negative integers. The digits are
stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
## example
```c++
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,

return [0, 1]
```
## 题目大意
2 个逆序的链表，要求从低位开始相加，得出结果也逆序输出，返回值是逆序结果链表的头结点。
## 解题思路
需要注意的是各种进位问题。
极端情况，例如
```c++
Input: (9 -> 9 -> 9 -> 9 -> 9) + (1 -> )
Output: 0 -> 0 -> 0 -> 0 -> 0 -> 1
```
为了处理⽅法统⼀，可以先建⽴⼀个虚拟头结点，这个虚拟头结点的 Next 指向真正的 head，这样
head 不需要单独处理，直接 while 循环即可。另外判断循环终⽌的条件不⽤是 ```c++p.Next ！= NULL```，这样最
后⼀位还需要额外计算，循环终⽌条件应该是```c++ p != NULL```。

两个都不是```c++NULL```时，将对应的elem相加，如果>=10，则取余并进位add置为1，否则为0，然后将指针后移。
```c++ p->next->elem=add```，然后为next指针申请内存```c++ p->next=(link*)malloc(sizeof(link))```

## 数据结构
* Definition for singly-linked list.
```c++
type struct link{
  int elem;
  link* next;
}
```

逻辑结构上一个挨一个的数据，在实际存储时，并没有像[顺序表](http://data.biancheng.net/view/4.html)那样也相互紧挨着。恰恰相反，数据随机分布在内存中的各个位置，这种存储结构称为[线性表](http://data.biancheng.net/view/157.html)的链式存储。  
  
由于分散存储，为了能够体现出数据元素之间的逻辑关系，每个数据元素在存储的同时，要配备一个指针，用于指向它的直接后继元素，即每一个数据元素都指向下一个数据元素（最后一个指向NULL(空)）。  
  

![](/uploads/allimg/170717/2-1FGGH922492.png)  
[图](http://data.biancheng.net/view/200.html)1 链式存储存放数据

  
如图1所示，当每一个数据元素都和它下一个数据元素用指针链接在一起时，就形成了一个链，这个链子的头就位于第一个数据元素，这样的存储方式就是链式存储。  

> 线性表的链式存储结构生成的表，称作“[链表](http://data.biancheng.net/view/160.html)”。

## 链表中数据元素的构成

每个元素本身由两部分组成：  

1. 本身的信息，称为“数据域”；
2. 指向直接后继的指针，称为“指针域”。

![](/uploads/allimg/170719/2-1FG9150JD34.png)  
图2 结点的构成

这两部分信息组成数据元素的存储结构，称之为“结点”。n个结点通过指针域相互链接，组成一个链表。  
  

![](/uploads/allimg/170727/2-1FHG45629418.png)  
图3 含有n个结点的链表  
 

图 3 中，由于每个结点中只包含一个指针域，生成的链表又被称为 线性链表 或 单链表。  
  
链表中存放的不是基本数据类型，需要用结构体实现自定义：

[复制](http://data.biancheng.net/view/5.html#)[纯文本](http://data.biancheng.net/view/5.html#)[复制](http://data.biancheng.net/view/5.html#)
```c++
typedef struct Link{
    char elem;//代表数据域
    struct Link \* next;//代表指针域，指向直接后继元素
}link;
```
typedef struct Link{
    char elem;//代表数据域
    struct Link \* next;//代表指针域，指向直接后继元素
}link;

## 头结点、头指针和首元结点

头结点：有时，在链表的第一个结点之前会额外增设一个结点，结点的数据域一般不存放数据（有些情况下也可以存放链表的长度等信息），此结点被称为头结点。  

> 若头结点的指针域为空（NULL），表明链表是空表。头结点对于链表来说，不是必须的，在处理某些问题时，给链表添加头结点会使问题变得简单。

首元结点：链表中第一个元素所在的结点，它是头结点后边的第一个结点。  
  
头指针：永远指向链表中第一个结点的位置（如果链表有头结点，头指针指向头结点；否则，头指针指向首元结点）。  

头结点和头指针的区别：头指针是一个指针，头指针指向链表的头结点或者首元结点；头结点是一个实际存在的结点，它包含有数据域和指针域。两者在程序中的直接体现就是：头指针只声明而没有分配存储空间，头结点进行了声明并分配了一个结点的实际物理内存。

  
![](/uploads/allimg/170719/2-1FG915025H28.png)

图 4 头结点、头指针和首元结点

> 单链表中可以没有头结点，但是不能没有头指针！

## 链表的创建和遍历

万事开头难，初始化链表首先要做的就是创建链表的头结点或者首元结点。创建的同时，要保证有一个指针永远指向的是链表的表头，这样做不至于丢失链表。  
  
例如创建一个链表（1，2，3，4）:
```c++
link initLink(){
  link p=(link)malloc(sizeof(link));//创建一个头结点
  link temp=p;//声明一个指针指向头结点，用于遍历链表
  //生成链表
  for (int i=1; i<5; i++) {
    link a=(link)malloc(sizeof(link));
    a->elem=i;
    a->next=NULL;
    temp->next=a;
    temp=temp->next;
  }
  return p;
}
```

## 链表中查找某结点

一般情况下，链表只能通过头结点或者头指针进行访问，所以实现查找某结点最常用的方法就是对链表中的结点进行逐个遍历。  
  
实现代码：

```c++
int selectElem(link * p,int elem){
  link * t=p;
  int i=1;
  while (t->next) {
    t=t->next;
    if (t->elem==elem) {
      return i;
    }
    i++;
  }
  return -1;
}
```

## 链表中更改某结点的数据域

链表中修改结点的数据域，通过遍历的方法找到该结点，然后直接更改数据域的值。  
  
实现代码：

[复制](http://data.biancheng.net/view/5.html#)[纯文本](http://data.biancheng.net/view/5.html#)[复制](http://data.biancheng.net/view/5.html#)
```c++
//更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
link *amendElem(link * p,int add,int newElem){
  link * temp=p;
  temp=temp->next;//在遍历之前，temp指向首元结点
  //遍历到被删除结点
  for (int i=1; i<add; i++) {
    temp=temp->next;
  }
  temp->elem=newElem;
  return p;
}
```
## 向链表中插入结点

链表中插入头结点，根据插入位置的不同，分为3种：

1. 插入到链表的首部，也就是头结点和首元结点中间；
2. 插入到链表中间的某个位置；
3. 插入到链表最末端；

![](/uploads/allimg/170718/2-1FGQ0394c05.png)  
图 5 链表中插入结点5

  
虽然插入位置有区别，都使用相同的插入手法。分为两步，如图 5 所示：  

- 将新结点的next指针指向插入位置后的结点；
- 将插入位置前的结点的next指针指向插入结点；

  
提示：在做插入操作时，首先要找到插入位置的上一个结点，图4中，也就是找到结点 1，相应的结点 2 可通过结点 1 的 next 指针表示，这样，先进行步骤 1，后进行步骤 2，实现过程中不需要添加其他辅助指针。  
  
实现代码：

```c++
link * insertElem(link * p,int elem,int add){
  link * temp=p;//创建临时结点temp
  //首先找到要插入位置的上一个结点
  for (int i=1; i<add; i++) {
    if (temp==NULL) {
      printf("插入位置无效\n");
      return p;
    }
    temp=temp->next;
  }    
  //创建插入结点c
  link * c=(link*)malloc(sizeof(link));
  c->elem=elem;
  //向链表中插入结点
  c->next=temp->next;
  temp->next=c;
  return  p;
}
```

注意：首先要保证插入位置的可行性，例如图 5 中，原本只有 5 个结点，插入位置可选择的范围为：1-6，如果超过6，本身不具备任何意义，程序提示插入位置无效。

## 从链表中删除节点

当需要从链表中删除某个结点时，需要进行两步操作：  

- 将结点从链表中摘下来;
- 手动释放掉结点，回收被结点占用的内存空间;

使用malloc函数申请的空间，一定要注意手动free掉。否则在程序运行的整个过程中，申请的内存空间不会自己释放（只有当整个程序运行完了以后，这块内存才会被回收），造成内存泄漏，别把它当成是小问题。

  
实现代码：

```c++
link * delElem(link * p,int add){
  link * temp=p;
  //temp指向被删除结点的上一个结点
  for (int i=1; i<add; i++) {
    temp=temp->next;
  }
  link * del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
  temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
  free(del);//手动释放该结点，防止内存泄漏
  return p;
}
```

## 完整代码
```c++
#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
  int  elem;
  struct Link *next;
}link;
link * initLink();
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link * insertElem(link * p,int elem,int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link * delElem(link * p,int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p,int elem);
//更新结点的函数，newElem为新的数据域的值
link *amendElem(link * p,int add,int newElem);
void display(link *p);

int main() {
  //初始化链表（1，2，3，4）
  printf("初始化链表为：\n");
  link *p=initLink();
  display(p);
  
  printf("在第4的位置插入元素5：\n");
  p=insertElem(p, 5, 4);
  display(p);
  
  printf("删除元素3:\n");
  p=delElem(p, 3);
  display(p);
  
  printf("查找元素2的位置为：\n");
  int address=selectElem(p, 2);
  if (address==-1) {
    printf("没有该元素");
  }else{
    printf("元素2的位置为：%d\n",address);
  }
  printf("更改第3的位置的数据为7:\n");
  p=amendElem(p, 3, 7);
  display(p);
  
  return 0;
}

link * initLink(){
  link * p=(link*)malloc(sizeof(link));//创建一个头结点
  link * temp=p;//声明一个指针指向头结点，用于遍历链表
  //生成链表
  for (int i=1; i<5; i++) {
    link *a=(link*)malloc(sizeof(link));
    a->elem=i;
    a->next=NULL;
    temp->next=a;
    temp=temp->next;
  }
  return p;
}
link * insertElem(link * p,int elem,int add){
  link * temp=p;//创建临时结点temp
  //首先找到要插入位置的上一个结点
  for (int i=1; i<add; i++) {
    if (temp==NULL) {
      printf("插入位置无效\n");
      return p;
    }
    temp=temp->next;
  }
  //创建插入结点c
  link * c=(link*)malloc(sizeof(link));
  c->elem=elem;
  //向链表中插入结点
  c->next=temp->next;
  temp->next=c;
  return  p;
}

link * delElem(link * p,int add){
  link * temp=p;
  //遍历到被删除结点的上一个结点
  for (int i=1; i<add; i++) {
    temp=temp->next;
  }
  link * del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
  temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
  free(del);//手动释放该结点，防止内存泄漏
  return p;
}
int selectElem(link * p,int elem){
  link * t=p;
  int i=1;
  while (t->next) {
    t=t->next;
    if (t->elem==elem) {
      return i;
    }
    i++;
  }
  return -1;
}
link *amendElem(link * p,int add,int newElem){
  link * temp=p;
  temp=temp->next;//tamp指向首元结点
  //temp指向被删除结点
  for (int i=1; i<add; i++) {
    temp=temp->next;
  }
  temp->elem=newElem;
  return p;
}
void display(link *p){
  link* temp=p;//将temp指针重新指向头结点
  //只要temp指针指向的结点的next不是Null，就执行输出语句。
  while (temp->next) {
    temp=temp->next;
    printf("%d",temp->elem);
  }
  printf("\n");
}
```
运行结果：
```
初始化链表为：
1234
在第4的位置插入元素5：
12354
删除元素3:
1254
查找元素2的位置为：
元素2的位置为：2
更改第3的位置的数据为7:
1274
```
## 总结

线性表的链式存储相比于顺序存储，有两大优势：

1. 链式存储的数据元素在物理结构没有限制，当内存空间中没有足够大的连续的内存空间供[顺序表](http://data.biancheng.net/view/158.html)使用时，可能使用链表能解决问题。（链表每次申请的都是单个数据元素的存储空间，可以利用上一些内存碎片）
2. 链表中结点之间采用指针进行链接，当对链表中的数据元素实行插入或者删除操作时，只需要改变指针的指向，无需像顺序表那样移动插入或删除位置的后续元素，简单快捷。

  
链表和顺序表相比，不足之处在于，当做遍历操作时，由于链表中结点的物理位置不相邻，使得计算机查找起来相比较顺序表，速度要慢。

