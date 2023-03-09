#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head=NULL;

void insert(int item)
{
    struct node *new=NULL,*temp;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    
    if(head==NULL){
    head=new;
    temp=head;
    temp->next=NULL;
    }

    else
    {
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
            temp->next=new;
    }
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
    printf("%d,",temp->data);
    temp=temp->next;
    }

}

void insertatbeg(int item)
{
  struct node *temp,*new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=item;
  new->next=NULL;

  if(head==NULL)
  head=new;

  else{
    temp=head;
    head=new;
    new->next=temp;
  }
}


void delete()
{
    struct node *temp;
    temp=head;
    temp=temp->next;
    head=temp;
    free(temp);
}

int main()
{
    printf("inserting the element in list\n");
    insert(1);
    insert(2);
    insert(3);
    insert(4); 
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    display();
    printf("\n");
    printf("after inserting element in begging\n");
    insertatbeg(100);
    display();
    delete();
    printf("after deletion of element \n");
    display();

}