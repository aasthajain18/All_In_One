#include <stdio.h>
#include<stdlib.h>
//****************************ARRAY**************************************
int choice,i,n;
void
my_array ()
{
  int pos, key;
  printf("\n***************************ARRAY*************************************\n");
  printf ("\nEnter the size of array\n");
  scanf ("%d", &n);
  int arr[n];
  printf ("\nEnter the elements\n");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &arr[i]);
    }
//*************************INSERTION****************************************
  void insertion_myarray (int key, int pos)
  {
    n++;
    for (i = n - 1; i >= pos; i--)
      {
  arr[i] = arr[i - 1];
      }
    arr[pos - 1] = key;
  }
//**********************DELETION*********************************************
  void deletion_myarray (int pos)
  {
    for (i = pos - 1; i <= n - 1; i++)
      {
  arr[i] = arr[i + 1];
      }
    n--;
  }
  //******************Print array***********************
  void printarray(){
      for (i = 0; i < n; i++)
      {
        printf ("%d\t", arr[i]);
      }
  }
//************************************SEARCHING****************************************
  void searching_myarray ()
  {
    int found=0;
    printf ("\nEnter the key\n");
    scanf ("%d", &key);
    for (i = 0; i < n; i++)
      {
  if (arr[i] == key)
    {
      found=1;
    }
      }
      if(found==1){
        printf("Key found");
      }
      else
          printf("Key not found");
  }
  printf("\n***************************ARRAY*************************************\n");
  printf ("\n1.Insertion\n2.Deletion\n3.Searching\n4.Print array\n5.Exit\nEnter your choice\n");
  scanf ("%d", &choice);
  switch (choice)
    {
    case 1:
      printf ("\nEnter the position");
      scanf ("%d", &pos);
      printf ("\nEnter the elemnt to be inserted\n");
      scanf ("%d", &key);
      insertion_myarray (key, pos);
      for (i = 0; i < n; i++)
   {
    printf ("%d\t", arr[i]);
    }
    break;
    case 2:
    printf ("\nEnter the position");
    scanf ("%d", &pos);
    deletion_myarray (pos);
    for (i = 0; i < n; i++)
      {
        printf ("%d\t", arr[i]);
      }
    break;
    case 3:
    searching_myarray ();
    break;
    case 4:
        for (i = 0; i < n; i++)
      {
        printf ("%d\t", arr[i]);
      }
      break;
    case 5:
      exit(1);
   default:
     printf("Enter valid choice");
     }
    }
//*********************Linked List***************************†*****************
struct node{
  int data;
  struct node *next;
};
void my_linkedlist(){
  int n,data,c=0;
  struct node *head;
  struct node *temp;
  struct node *temp1;
  head=(struct node*)malloc(sizeof(struct node));
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter no. of nodes");
  scanf("%d",&n);
  printf("Enter the data");
  scanf("%d",&data);
  head->data=data;
  for(int i=2;i<=n;i++){
    if(c==0){
      scanf("%d",&data);
      temp->data=data;
      head->next=temp;
      temp->next=NULL;
      c++;
    }
    else
       {
         scanf("%d",&data);
         temp1=(struct node*)malloc(sizeof(struct node));
         temp1->data=data;
         temp->next=temp1;
         temp1->next=NULL;
         temp=temp1;
       }
  }
  void traversal(struct node *ptr){
    printf("\n***********Linked List***************\n");
    if(head==NULL){
      printf("\nNo element in list\n");
    }
    while(ptr!=NULL){
      printf("%d\t",ptr->data);
      ptr=ptr->next;
    }
  }
traversal(head);
//***************""""""**Insertion*************************"
void insertion_in_ll(){
  int data,pos;
   printf("Enter the data to be inserted\n");
    scanf("%d",&data);
    
 //************Insert at first**************
   
    void insert_at_first(int data){
      struct node *ptr=(struct node*)malloc(sizeof(struct node));
      ptr->data=data;
      ptr->next=head;
      head=ptr;
    }
    
 //********Insert at position****************
   void insert_at_position(int data){
     printf("Enter position\n");
     scanf("%d",&pos);
     if(pos<0||pos>=n){
       printf("Invalid position");
     }
     else
   {
         struct node *ptr=head;
         struct node *newnode=(struct node*)malloc(sizeof(struct node));
         newnode->data=data;
         for(int i=1;i<pos-1;i++){
           ptr=ptr->next;
         }
         newnode->next=ptr->next;
         ptr->next=newnode;
         }
         return head;
   }
   //***************Insert at end******************
   void insert_at_end(int data){
     struct node *ptr=head;
     struct node *p=ptr->next;
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=data;
     while(p->next!=NULL){
       ptr=ptr->next;
       p=p->next;
     }
     p->next=newnode;
     newnode->next=NULL;
     return head;
   }
   
    printf("\n1.Insert at first\n2.Insert at position\n3.Insert at end\nEnter the choice\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      insert_at_first(data);
      traversal(head);
      break;
    case 2:
      insert_at_position(data);
      traversal(head);
      break;
    case 3:
      insert_at_end(data);
      traversal(head);
      break;
      default:
        printf("Enter valid choice");
        break;
      
}
}
//********************Deletion***********************
void deletion_in_ll(){
  int pos,i;
  //****************Deletion at first*******************
  void delete_at_first(){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
  }
  //****************Deletion at pos***************
 void delete_at_pos(){
   struct node *ptr=head;
   struct node *p=ptr->next;
   printf("\nEnter the position\n");
   scanf("%d",&pos);
   for(i=1;i<pos-1;i++){
     ptr=ptr->next;
     p=p->next;
   }
   ptr->next=p->next;
   free(p);
   return head;
 }
 void delete_at_end(){
     struct node *ptr=head;
     struct node *p=ptr->next;
     while(p->next!=NULL){
       ptr=ptr->next;
       p=p->next;
     }
     ptr->next=NULL;
     free(p);
     return head;
 }
 printf("\n1.Deletion at first\n2.Deletion at position\n3.Deletion at end\nEnter choice\n");
 scanf("%d",&choice);
 switch(choice){
   case 1:
     delete_at_first();
     traversal(head);
     break;
   case 2:
     delete_at_pos();
     traversal(head);
     break;
   case 3:
     delete_at_end();
     traversal(head);
     break;
 }
}
printf("\n*******************Linked List********************\n");
printf("\n1.Insertion\n2.Deletion\n3.Print the list\nEnter the choice\n");
scanf("%d",&choice);
switch(choice){
  case 1:
    insertion_in_ll();
    break;
  case 2:
    deletion_in_ll();
    break;
    case 3:
      traversal(head);
      break;
      case 4:
        exit(0);
        default:
          printf("Enter valid choice");
          break;
}
}
//********"*"""""""Doubly linked list********************
struct dllnode{
  struct dllnode *prev;
  struct dllnode *next;
  int data;
};
void traversal_dll(struct dllnode *head)
{
  int c=0;
  struct dllnode *ptr=head;
  while(ptr!=NULL)
  {
    if(c==0)
        {
           printf("%d",ptr->data);
           ptr=ptr->next;
           c++;
        }
    else
        {
           printf("<===>%d",ptr->data);
           ptr=ptr->next;
           c++;
        }
  }
}
void revtraversal(struct dllnode *tail)
{
  int c=0;
  struct dllnode *ptr=tail;
  while(ptr!=NULL){
    if(c==0){
      printf("%d",ptr->data);
      ptr=ptr->prev;
      c++;
    }
    else
{
  printf("<-%d",ptr->data);
  ptr=ptr->prev;
  c++;
}
  }
}
//*****************Insertion***********************
void insertion_dll(struct dllnode *head,struct dllnode *tail){
  int choice,data,index;
  
  
  struct dllnode *insertatfirst(struct dllnode *head,int data){
    struct dllnode *p=(struct dllnode*)malloc(sizeof(struct dllnode));
    p->prev=NULL;
    head->prev=p;
    p->next=head;
    p->data=data;
    head=p;
    return head;
  }
 struct dllnode *insertatindex(struct dllnode *head,int index,int data){
  struct dllnode *p=(struct dllnode*)malloc(sizeof(struct dllnode));
  struct dllnode *t=head;
  p->data=data;
  for(int i=1;i<index-1;i++){
    t=t->next;
  }
  p->next=t->next;
  p->prev=t;
  t->next=p;
  t->next->prev=p;
 }
 struct dllnode *insertatend(struct dllnode *tail,int data){
   struct dllnode *q=(struct dllnode*)malloc(sizeof(struct dllnode));
   q->next=NULL;
   tail->next=q;
   q->prev=tail;
   q->data=data;
   tail=q;
   return tail;
 }
  
  
  printf("\n1.Insertion at beginning\n2.Insert at index\n3.Insert at end\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      printf("What to insert");
      scanf("%d",&data);
      head=insertatfirst(head,data);
      traversal_dll(head);
      break;
    case 2:
      printf("Where to insert");
      scanf("%d",&index);
      printf("\nWhat to insert");
      scanf("%d",&data);
      insertatindex(head,index,data);
      traversal_dll(head);
      break;
    case 3:
      printf("What to insert");
      scanf("%d",&data);
      tail=insertatend(tail,data);
      traversal_dll(head);
      break;
      default:
        printf("Enter valid code");
        break;
  }
}
//*********************Deletion***********************
void deletion_dll(struct dllnode *head,struct dllnode *tail){
   int choice,index;
   struct dllnode *dltatfirst(struct dllnode *head){
     struct dllnode *p=head; 
     head=head->next;
     head->prev=NULL;
     free(p);
     return head;
   }
   struct dllnode *dltatend(struct dllnode *tail){
     struct node *t=tail;
     tail=tail->prev;
     tail->next=NULL;
     free(t);
     return tail;
   }
   struct dllnode *dltatindex(struct dllnode *head,int index){
     struct dllnode *t=head;
     struct dllnode *p=head->next;
     for(int i=0;i<index-1;i++){
       t=t->next;
     }
      t->next=p->next;
      p->next->prev=t;
     free(p);
     return head;
   }
  printf("\n1.Delete at first\n2.Delete at index\n3.Delete at end\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      head=dltatfirst(head);
      traversal_dll(head);
      revtraversal(tail);
      break;
      case 2:
        printf("Where to delete");
        scanf("%d",&index);
        dltatindex(head,index);
        traversal_dll(head);
        revtraversal(tail);
        break;
      case 3:
        tail=dltatend(tail);
        traversal_dll(head);
        revtraversal(tail);
        break;
        default:
          printf("Enter valid code");
          break;
  }
}
void my_dll(){
  int choice,data,n,c=0;
  //Creation of nodes
  struct dllnode *head;
  struct dllnode *temp;
  struct dllnode *temp1;
  struct dllnode *tail;
  //Allocation of memory
  head=(struct dllnode*)malloc(sizeof(struct dllnode));
  temp=(struct dllnode*)malloc(sizeof(struct dllnode));
 //Assing data to each node
 
    printf("Enter no. of nodes");
    scanf("%d",&n);
    printf("Enter data");
    scanf("%d",&data);
    head->data=data;
    head->prev=NULL;
    for(int i=2;i<=n;i++){
    if(c==0){
      scanf("%d",&data);
      temp->data=data;
      temp->prev=head;
      temp->next=NULL;
      head->next=temp;
      c++;
    }
    else
{
  temp1=(struct dllnode*)malloc(sizeof(struct dllnode));
  scanf("%d",&data);
  temp1->data=data;
  temp1->next=NULL;
  temp1->prev=temp;
  temp->next=temp1;
  temp=temp1;
}
tail=temp1;
}
printf("\n*********************Doubly Linked List***************\n");
  printf("1.Traversal\n2.Insertion\n3.Deletion\n");
  printf("Enter your choice");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      traversal_dll(head);
      printf("\nReverse traversal\n");
      revtraversal(tail);
      break;
    case 2:
      insertion_dll(head,tail);
      break;
      case 3:
        deletion_dll(head,tail);
        break;
        default:
          printf("Enter valid choice");
          break;
  }
}
//******************************Circular linked list************************************************************





//***********"""""""******Stack"***********************
#define MAX 5

int stack[MAX];
int top=-1;

int isFull(){
  if(top==MAX-1){
    return 1;
  }
  else 
  return 0;
}
int isEmpty(){
  if(top==-1){
    return 1;
  }
  else
      return 0;
}
void push(int data){
  if(isFull()){
    printf("\nStack Overflow\n");
    return;
  }
  top=top+1;
  stack[top]=data;
}
int pop(){
  int val;
  if(isEmpty()){
    printf("\nStack Underflow\n");
    exit(1);
  }
  val=stack[top];
  top=top-1;
  return val;
}
void printstack(){
  if(isEmpty()){
    printf("\nStack Underflow\n");
    return;
  }
  for(i=top;i>=0;i--){
    printf("%d\n",stack[i]);
    printf("\n");
  }
}
int peek(){
  if(isEmpty()){
    printf("\nStack underflow\n");
    exit(1);
  }
  return stack[top];
}
void mystack(){
  int choice,data,ind,i;
  printf("\n************************Stack********************\n");
  while(1){
  printf("1.Print stack\n2.Top Element\n3.Push\n4.Pop\n6.Exit\nEnter your choice");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      printstack();
      break;
      
      case 2:
        peek();
        printf("Top element : %d\n",stack[top]);
      break;
      
      case 3:
        printf("What to push");
        scanf("%d",&data);
        push(data);
      break;
      
      case 4:
        data=pop();
        printf("Deleted element is %d\n",data);
      break;
       case 6:
       exit(1);
       
      default:
        printf("Enter valid choice\n");
      break;
  }
 }
}

//***************Queue********************************************
struct quenode
{
  int data;
  struct quenode* next;
};//defining linked list to implement queue
struct quenode *front = NULL;
struct quenode *rear = NULL;
void enqueue(int d)//function to insert a node in queue
{
  struct quenode* new_n;
  new_n = (struct quenode*)malloc(sizeof(struct quenode));
  new_n->data = d;
  new_n->next = NULL;
  if((front == NULL)&&(rear == NULL)){
    front = rear = new_n;
  }
  else{
    rear->next = new_n;
    rear = new_n;
  }
  
}
void print()
{
  struct quenode* temp;
  if((front == NULL)&&(rear == NULL)){
    printf("\nQueue is Empty");
  }
  else{
    temp = front;
    while(temp){
      printf("\n%d",temp->data);
      temp = temp->next;
    }
  }
}
void dequeue()//function to delete an element from a queue
{
  struct quenode *temp;
  temp = front;
  if((front == NULL)&&(rear == NULL)){
    printf("\nQueue is Empty");
  }
  else{
    front = front->next;
    free(temp);
  }
}
void myqueue()//main function to use all our declared function
{
  int opt,n,i,data;
printf("\n**************************************\n");
printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tQUEUE\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
printf("\n**************************************\n");

  while(opt!=0){
    printf("\n\n1.Implement Queue\n2.Enqueue\n3.Data in Queue \n4.DeQueue\n0.Exit\nEnter Your Choice:-");
    scanf("%d",&opt);
    switch(opt){
      case 1:
        printf("\nEnter the size: ");
        scanf("%d",&n);
        printf("\nEnter your data\n");
        i=0;
        while(i<n){
          scanf("%d",&data);
          enqueue(data);
          i++;
        }
        print();
        break;
        case 2:{
          printf("What to insert");
          scanf("%d",&data);
          enqueue(data);
          print();
          break;
        }
      case 3:
        print();
        break;
      case 4:
        dequeue();
        print();
        break;
      case 0:
        break;
      default:
        printf("\nIncorrect Choice");
      
    }
  }
}
//**************************TREE*******************************
int tree[15];
void mytree(){
void insert(int data,int index)
{
  if(data<=tree[index])
  {
    if(tree[2*index+1]==0)
      tree[2*index+1]=data;
      else
         insert(data,2*index+1);
  }
   else 
  {
    if(tree[2*index+2]==0)
      tree[2*index+2]=data;
      else
         insert(data,2*index+2);
  }
}
  printf("\n*********************Tree********************************\n");
  int number,r;
  printf("enter root value\n");
    scanf("%d",&r);
   tree[0]=r;
   printf("enter the elements\n");
   for(int i=1;i<15;i++)
   {
     scanf("%d",&number);
     insert(number,0);
   }
   printf("\nPreorder traversal of BST\n");
   for(int i=0;i<15;i++)
   {
     printf(" %d",tree[i]);
   }
}


//*******************Main function********************
int main ()
{
  printf("Menu driven program of data structure");
  printf("\n1.Array\n2.Singly Linked List\n3.Doubly linked list\n4.Stack\n5.Queue\n6.Tree\n7.Exit\nEnter your choice:-\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      my_array();
      break;
      case 2:
      my_linkedlist();
      break;
      case 3:
        my_dll();
        break;
        case 4:
          mystack();
          break;
          case 5:
            myqueue();
            break;
            case 6:
              mytree();
              break;
      case 7:
        exit(1);
      default:
        printf("Enter valid choice");
  }
return 0;
}