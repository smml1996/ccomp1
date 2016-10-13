#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

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

void print_list(struct node *head){
    struct node * pp = head;
    while(pp!=NULL){
        printf("%d\n", pp->val);
        pp = pp->next;
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
    new_node -> val =val;
    for(int i = 0; i<index;i++, pp=pp->next);
    new_node->next = pp->next;
    pp->next = new_node;
}

void delete_node(struct node *head, int index){
    if(index == 0){
        *head= *(head->next);
        return;
    }
    struct node *pp = head;
    for(int i = 0; i<index-1; i++,pp= pp->next);
    free(pp->next);
    pp->next = pp->next->next;


}
int main(){

    struct node *head;
    head = malloc(sizeof(struct node));
    head -> val = 5;
    head -> next =NULL;
    //printf("%d", (*head).val);
    push_back(head, 7);
    add_at(head, 11, 0);
    delete_node(head,0);
    print_list(head);
return 0;
}
