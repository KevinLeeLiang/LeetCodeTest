#pragma once
typedef struct link {
  int elem;// 数据域
	struct link* next;// 代表指针域，只想直接后继元素
  
  link* initLink() {  // 初始化一个只有头结点的链表
    link* p = (link*)malloc(sizeof(link));//创建一个头结点
    p->elem = 0;
    p->next = NULL;
    return p;
  }
  // 在链表p中查找elem，返回是链表中的第几个元素,没找到则返回-1
  int selectElem(link* p, int elem) { 
    link* t = p;
    int i = 1;
    while (t->next) {
      t = t->next;
      if (t->elem == elem)
        return i;
      i++;
    }
    return -1;
  }
  // 更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
  link * amendElem(link * p, int add, int newElem) {
    link* temp = p;
    temp = temp->next;//在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for (int i = 1; i < add; i++) {
      temp = temp->next;
    }
    temp->elem = newElem;
    return p;
  }
  // 在链表p的add位置插入elem
  link* insertElem(link* p, int elem, int add) {
    link* temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) {
      if (temp == NULL) {
        printf("插入位置无效\n");
        return p;
      }
      temp = temp->next;
    }
    //创建插入结点c
    link* c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
  }
  // 删除p中add位置的
  link* delElem(link* p, int add) {
    link* temp = p;
    //temp指向被删除结点的上一个结点
    for (int i = 1; i < add; i++) {
      temp = temp->next;
    }
    link* del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
  }

}link;

link* setElemForLink(int count, int* ptr_elem) {
  link* temp = (link*)malloc(sizeof(link));
  temp->elem = ptr_elem[0];
  temp->next = NULL;
  link* p = temp;
  for (size_t i = 1; i < count; i++){
    link* a = (link*)malloc(sizeof (link));
    a->elem = ptr_elem[i];
    a->next = NULL;
    temp->next = a;
    temp = temp->next;
  }
  return p;
}


link* AddTwoNumbers(link* p, link* q) {
  link* result = (link*)malloc(sizeof(link));;
  result->elem = 0;
  result->next = NULL;
  link* head = result;
  if (p==NULL || q==NULL)
    return NULL;
  // 两个链表都空了
  int temp = 0;
  int carry = 0;
  while (p != NULL && q != NULL) {
    int p_elem = 0;
    int q_elem = 0;
    p_elem = p->elem;
    q_elem = q->elem;
    p = p->next;
    q = q->next;
    temp = p_elem + q_elem;
    result->elem += temp;
    result->next = NULL;
    if (result->elem >= 10) {
      result->elem = result->elem % 10;
      carry = 1;
    }
    else
      carry = 0;
    if (p != NULL && q != NULL) {
      result->next = (link*)malloc(sizeof(link));
      result->next->elem = carry;
      result->next->next = NULL;
    }
    else
      break;
    
    if (carry) {
      result->next->elem = carry;
      carry = 0;
    }
    else 
      result->next->elem = 0;
    result = result->next;
  }
  while (p){
    result->elem += p->elem;
    
    if (result->elem >= 10) {
      result->elem = result->elem % 10;
      carry = 1;
    }
    else
      carry = 0;
    result->next = (link*)malloc(sizeof(link));
    result->next->elem = carry;
    result->next->next = NULL;
    result = result->next;
    p = p->next;
  }
  while (q) {
    result->elem += q->elem;
    if (result->elem >= 10) {
      result->elem = result->elem % 10;
      carry = 1;
    }
    else
      carry = 0;
    result->next = (link*)malloc(sizeof(link));
    result->next->elem = 0;
    result->next->next = NULL;
    result = result->next;
    
    q = q->next;
  }
  //if (!result->elem){
  //  delete result;
  //  //free(result);
  //  result = NULL;
  //}
  return head;
}

