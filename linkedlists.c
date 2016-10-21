#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void print_list(struct node *head){
    struct node * pp = head;
    while(pp!=NULL){
        printf("%d\n", pp->val);
        pp = pp->next;
    }
}

struct node* create(struct node *head, int l, int values[]){
    head = malloc(sizeof(struct node));
    struct node  *p = head;int i = 0;
    for( ;i<l-1; i++){
       // printf("%d\n",values[i]);
        p->val = values[i];
        p->next = malloc(sizeof(struct node));
        p=p->next;
    }
    p->val = values[i];
    p->next = NULL;
    return head;
}

void delete_node(struct node *head, int value){
    struct node *prev= head;
   while(head->val == value){
        free(head);
        *head= *(head->next);
    }
    struct node *cur = head->next;
    while(cur->next!=NULL){
        if(cur->val == value){
            prev->next = cur->next;
            free(cur);
            cur=cur->next;
        }else{
            prev =cur;
            cur=cur->next;}
    }

    if(cur->val==value){
        prev->next=NULL;
        free(cur);
    }
}
void add_at(struct node *head, int val, int index){ //base 0
    struct node *pp = head;
    struct node *new_node = malloc(sizeof(struct node));
    if(index == 0){
        int temp = head->val;
        head->val = val;
        new_node->next = head->next;
        new_node->val = temp;
        head->next= new_node;
        return;
    }
    new_node -> val =val;int i = 0;
    for(; i<index;i++, pp=pp->next);
    new_node->next = pp->next;
    pp->next = new_node;
}

void push_back(struct node *head, int valor){
    struct node *last = malloc(sizeof(struct node));
    last->val = valor;
    last->next= NULL;
    struct node *pp = head;
    while((pp->next)!=NULL){
        pp= pp->next;
    }
    pp->next = last;
}

void sort_insert(struct node *head, int value){
    struct node *p = head;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = value;
    if(p->val>=value){
        add_at(head,value, 0);
        return;
    }
    while(p->next!=NULL){
        if(p->val && p->next->val>value){
            new_node ->next = p->next;
            p->next = new_node;
            return;
        }
        p= p->next;
    }
    p->next = new_node;
    new_node->next=NULL;
}

void concatenate(struct node *head1, struct node *head2){
    struct node *pp = head1;
    while(pp->next!=NULL)pp=pp->next;
    pp->next =head2;
}


int main(){

    struct node *head;
    int values[5]= {1,2,3,4,5};
    head = create(head, 5, values);
    sort_insert(head, 1);
    //delete_node(head, 2);
    print_list(head);
}
