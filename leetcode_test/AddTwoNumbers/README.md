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

