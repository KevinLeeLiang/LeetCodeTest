#pragma once
typedef struct link {
  int elem;// ������
	struct link* next;// ����ָ����ֻ��ֱ�Ӻ��Ԫ��
  
  link* initLink() {  // ��ʼ��һ��ֻ��ͷ��������
    link* p = (link*)malloc(sizeof(link));//����һ��ͷ���
    p->elem = 0;
    p->next = NULL;
    return p;
  }
  // ������p�в���elem�������������еĵڼ���Ԫ��,û�ҵ��򷵻�-1
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
  // ���º��������У�add ��ʾ���Ľ���������е�λ�ã�newElem Ϊ�µ��������ֵ
  link * amendElem(link * p, int add, int newElem) {
    link* temp = p;
    temp = temp->next;//�ڱ���֮ǰ��tempָ����Ԫ���
    //��������ɾ�����
    for (int i = 1; i < add; i++) {
      temp = temp->next;
    }
    temp->elem = newElem;
    return p;
  }
  // ������p��addλ�ò���elem
  link* insertElem(link* p, int elem, int add) {
    link* temp = p;//������ʱ���temp
    //�����ҵ�Ҫ����λ�õ���һ�����
    for (int i = 1; i < add; i++) {
      if (temp == NULL) {
        printf("����λ����Ч\n");
        return p;
      }
      temp = temp->next;
    }
    //����������c
    link* c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //�������в�����
    c->next = temp->next;
    temp->next = c;
    return  p;
  }
  // ɾ��p��addλ�õ�
  link* delElem(link* p, int add) {
    link* temp = p;
    //tempָ��ɾ��������һ�����
    for (int i = 1; i < add; i++) {
      temp = temp->next;
    }
    link* del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
    temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
    free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
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
  // ������������
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

