//Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}K;
K* root=NULL;
//Insertion in a binary search tree
void Insert(int key)
{
    K *r,*temp;
    K *t=root;
    if(t==NULL)
    {
        temp=(K*)malloc(sizeof(K));
        temp->data=key;
        temp->right=temp->left=NULL;
        root=temp;
    }
    else{
        while(t!=NULL)
        {
            r=t;
            if(key>t->data)
            t=t->right;
            else
            t=t->left;
        }
        temp=(K*)malloc(sizeof(K));
        temp->data=key;
        temp->right=temp->left=NULL;
        if(key>r->data)
         r->right=temp;
        else
        r->left=temp;
        }
}
//Recursive method to insert in a binary search tree
K* RecursiveInsert(K* p, int key)
{
 K* temp;
 if(p==NULL)
 {
   temp=(K*)malloc(sizeof(K));
   temp->left=NULL;
   temp->right=NULL;
   temp->data=key;
   return temp;
 }
 if(key>p->data)
 {
    p->right=RecursiveInsert(p->left,key);
 }
 else if(key<p->data)
 {
    p->left=RecursiveInsert(p->right,key);
 }
return p;
}
//find a particular element in a binary search tree
K* Search(K *p, int key)
{
    while(p!=NULL)
    {
        if(p->data==key)
        return p;
        else if(p->data>key)
         p=p->right;
        else if(p->data<key)
        p=p->left;
    }
    return NULL;
}
//printing element in inorder way
void Inorder(K *p)
{
    if(p)
    {
Inorder(p->left);
printf("%d ",p->data);
Inorder(p->right);
    }
}
//printing element in preorder way;
void Preorder(K *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}
//printing element in postorder way
void Postorder(K *p)
{
    if(p)
    {
        Postorder(p->left);
        Postorder(p->right);
        printf("%d ",p->data);
    }
}
//finding the maximum element in a binary search tree
K* Max(K *p)
{
    while(p && p->right!=NULL)
    {
        p=p->right;
    }
    return p;
}
//Height of binary search tree
int Height(struct Node *p)
{
 int x,y;
 if(p==NULL)return 0;
 x=Height(p->left);
 y=Height(p->right);
 return x>y?x+1:y+1;
}
//finding highest element in left side of binary tree
struct Node *InPre(struct Node *p)
{
 while(p && p->right!=NULL)
 p=p->right;
 
 return p;
}
//finding minimum element in right side of binary tree
struct Node *InSucc(struct Node *p)
{
 while(p && p->left!=NULL)
 p=p->left;
 
 return p;
}
//Delete a node in binary search tree
struct Node *Delete(struct Node *p,int key)
{
 struct Node *q;
 
 if(p==NULL)
 return NULL;
 if(p->left==NULL && p->right==NULL)
 {
 if(p==root)
 root=NULL;
 free(p);
 return NULL;
 
 }
 
 if(key < p->data)
 p->left=Delete(p->left,key);
 else if(key > p->data)
 p->right=Delete(p->right,key);
 else
 {
 if(Height(p->left)>Height(p->right))
 {
 q=InPre(p->left);
 p->data=q->data;
 p->left=Delete(p->left,q->data);
 }
 else
 {
 q=InSucc(p->left);
 p->data=q->data;
 p->left=Delete(p->left,q->data);
 }
 
 
 }
 return p;
}

int main()
{
   int key;
   while(1)
   {
   printf("\n--------------------Menu drive of binary search tree-------------------");
   printf("\n 1. To insert a node in a binary search treee\n");
   printf("\n 2. To Search an element in a binary search tree\n");
   printf("\n 3. To display binary search tree in inorder pattern:\n");
   printf("\n 4. To display binary search tree in preorder pattern:\n");
   printf("\n 5. To display binary search tree in postorder pattern:\n");
   printf("\n 6. To delete a node\n");
   printf("\n 7. To find the maximum element in a binary search tree:\n");
   scanf("%d",&key);
   switch(key)
   {
    case 1: 
    {
        int x;
        printf("\n Enter the element you want to insert\n");
        scanf("%d",&x);
        Insert(x);
        break;
    }
    case 2:
    {
      K *temp;
      int x;
      printf("\n Enter the element you want to search \n");
      scanf("%d",&x);
      temp=Search(root,x);
      if(temp!=NULL)
      {
        printf("\n Element is present in binary search tree");
      }
      else{
        printf("\n Element is not present in binary search tree");
      }
      break;
    }
    case 3:
    {
        Inorder(root);
        break;
    }
    case 4:
    {
        Preorder(root);
        break;
    }
    case 5:
    {
        Postorder(root);
        break;
    }
    case 6:
    {
        int x;
        printf("\n Enter the element you want to delete:\n");
        scanf("%d",&x);
        Delete(root,x);
        break;
    }
    case 7:
    {
        K *temp;
        temp=Max(root);
        printf("\n Maximum element in a binary search tree is %d ",temp->data);
        break;
    }
    default:
    {
        printf("\n Please choose valid key;\n");
        break;
    }
   }
   }

return 0;

}
