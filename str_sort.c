#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLINE 1000


int  get_line(char m[5000][1000], int line){
    int i = 0;
    char c;
    char *c1 = &m[line][0];
    for(; i<MAXLINE-2 &&(c=getchar())!=EOF && c!='\n'; i++, c1++){
            *c1=c;
    }
    *c1= '\0';
    return i;
}


int get_lines(char m[5000][1000], char *p[]){
    int i = 0;
    while(i<MAXLINES && get_line(m, i)>0){
        p[i]= &m[i]; i++;
    }
    return i;
}

void writelines(char *p[],int n){
    int i;
    for(i = 0;i<=n;i++){
        printf("%s\n", *p);
        p++;
    }
}

void swap(char *p[], int i,int j ){
    char *temp= p[i];
    p[i]=p[j];
    p[j]=temp;
}

void qsort(char *p[], int left, int right){
    if(left<right){
        int last = left, i = left+1;
        swap(p, left, (left+right)/2);
        for(; i<=right; i++){
            if(strcmp(p[i],p[left])<0){
                last++;
                swap(p, i,last);


            }
        }
        swap(p, last, left);
        qsort(p, left, last-1);
        qsort(p, last+1, right);
    }
}

int main(){
    int nlines =0; char *p[5000]; char inputs[5000][1000];
    nlines = get_lines(inputs,p);
    qsort(p, 0, nlines-1);
    writelines(p,nlines-1);
}
