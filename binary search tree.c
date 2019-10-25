#include<stdio.h>
struct bst
{
    int data;
    struct node *lc;
    struct node *rc;
}*ptr,*prev,*root,*temp,*ptr1;

void insert()
{
    int it;
    ptr=root;
    printf("item:");
    scanf("%d",&it);
    temp=(int *)malloc(sizeof(struct bst));
    temp->data=it;
    temp->lc=NULL;
    temp->rc=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(it<ptr->data)
            {
                prev=ptr;
                ptr=ptr->lc;
            }
            else if(it==ptr->data)
            {
                printf("item already present");
                return;
            }
            else
            {
                prev=ptr;
                ptr=ptr->rc;
            }
        }
        if(prev->data<it)
        {
            prev->rc=temp;
        }
        else
        {
            prev->lc=temp;
        }
    }

}

void inorder(struct bst *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lc);
        printf("%d\t",ptr->data);
        inorder(ptr->rc);
    }
}
void preorder(struct bst *ptr)  //name should be ptr itself
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}
void del(int item)
{
    int c,it;

    ptr=root;
    int flag=0;
    while(ptr!=NULL && flag==0)
    {
        if(item<ptr->data)
        {
            prev=ptr;
            ptr=ptr->lc;
        }
        else if(item==ptr->data)
        {
            flag=1;
        }
        else
        {
            prev=ptr;
            ptr=ptr->rc;
        }
    }
    if(flag==0)
    {
        printf("no item found!!\n");
        return;
    }
    if(ptr->lc==NULL && ptr->rc==NULL)
    {
        c=1;
    }
    else if(ptr->lc!=NULL && ptr->rc!=NULL)
    {
        c=3;
    }
    else
    {
        c=2;
    }

    if(c==1)
    {
        if(prev->data<item)
        {
            prev->rc=NULL;
        }
        else
        {
           prev->lc=NULL;
        }
        free(ptr);
    }
    else if(c==2)
    {
        if(prev->lc==ptr)
        {
            if(ptr->lc==NULL)
            {
                prev->lc=ptr->rc;
            }
            else
            {
                prev->lc=ptr->lc;
            }
        }
        else
        {
            if(prev->rc==ptr)
            {
                if(ptr->lc==NULL)
                {
                    prev->rc=ptr->rc;
                }
                else
                {
                    prev->rc=ptr->lc;
                }
            }
        }
        free(ptr);
    }
    else
    {
        if(c==3)
        {
            ptr1=ptr->rc;
            prev=ptr;      //prev of ptr1 is............ptr
            if(ptr1!=NULL)
            {
                while(ptr1->lc!=NULL)
                {
                    prev=ptr1;          //previous of ptr1->lc is.....ptr1
                    ptr1=ptr1->lc;
                }
            }
            it=ptr1->data;
            if(prev==ptr)
            {
                ptr->rc=NULL;  //or prev->rc=NULL
            }
            else
            {
                prev->lc=NULL;
            }
            ptr->data=it;

            free(ptr1);
        }
    }

}


void main()
{
    int ch,item;
    root=NULL;
    while(1){
    printf("\n1.insertion\n2.deletion\n3.inorder\n4.pre\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert();
                break;
        case 2: printf("item:");
                scanf("%d",&item);
                del(item);
                break;
        case 3:inorder(root);
                break;
        case 4:preorder(root);
                break;
    }
    }
}
