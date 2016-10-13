#include <stdio.h>

void to_lower(char *c){
    *c = ((*c)>='A' && (*c)<='Z')? (*c)+32:(*c);
}

void str_cat(char *s, char*c){
    while(*s!='\0'){
        s++;
    }
    for(;*c!='\0';c++,s++){
        *s= *c;
    }
}

void str_copy(char *s, char*c, int n){
    while(*s!='\0'){
        s++;
    }
    int i = 0;
    for(;*c != '\0' && i<n;s++,c++,i++){
        *s=*c;
    }
}

int strend(char *s, char *t){
    char *temp = t;

    for(; *s!='\0';s++){
        if(*s==*temp){
            temp++;
        }else{
            s-=temp-t;
            temp=t;
        }
    }
    return ((*temp)=='\0'?1:0);
}

int a_toi(char *c){
    int result =0;
    while(*c){
        result*=10;
        result+= (int)(*c)-'0';
        c++;
    }
    return result;
}
int main(){

    char c[30] = "hello";
    char s[] = "low";
    printf("%d", strend(&c[0],&s[0]));
}
