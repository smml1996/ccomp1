#include <stdio.h>

void to_lower(char *c){
    *c = ((*c)>='A' && (*c)<='Z')? (*c)+32:(*c);
}

char *str_cat(char *s, char*c){
    char static result[1000];
    int cont =0;
    while(*s){
        result[cont++]= *s;
        s++;
    }
    while(*c){
        result[cont++]=*c;
        c++;
    }
    result[cont]='\0';
    return &(result[0]);
}

char *str_copy(char *s, char*c, int n){
    int cont =0;
    static char m[100000];
    while(*s){
        m[cont++]= *s;
        if(cont ==n)break;
        s++;
    }

    if(cont<n){
        while(*c){
            m[cont++]=*c;
            c++;
            if(cont ==n)return;
        }
    }
    return &(m[0]);
}

int strend(char *s, char *t, int l1, int l2){
    t+=(l2-1);
    s+=(l1-1);
    while(l2>0){
        if(*s!=*t){
            return 0;
        }
        s--; t--;l2--;
    }
    return 1;
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
main(){
/*
    char m = 'J';
    char *c= &m;
    to_lower(c);
    printf("%c",m);*/

    char w[]="hola";
    char p[]="asdnmf";

    char *s= w; char *c=p;

    int i = 0;
    char *result =str_cat(s,c);
    for(; *result!='\0';result++){
        printf("%c", *result);
    }

/*

    char c[]="1432";
    char *m = &c[0];



    printf("%d",a_toi(m));*/


}
