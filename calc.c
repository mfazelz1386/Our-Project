#include "calc.h"
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// توابع داخلی برای اولویت عملگرها 
static double e1(table *t,const char **s,int *err);
static double e2(table *t,const char **s,int *err);
static double e3(table *t,const char **s,int *err);

// تابع اصلی محاسبه 
double calc(table *t,const char *s,int *err) {

    // صفر کردن خطا 
    *err=0;

    // شروع پردازش از بالاترین سطح 
    return e1(t,&s,err);
}

// -پردازش + و  
static double e1(table *t,const char **s,int *err) {

    // گرفتن مقدار اول 
    double v=e2(t,s,err);

    // تا وقتی + یا - داریم 
    while(**s=='+' || **s=='-'){
        char op=**s;
        (*s)++;

        double n=e2(t,s,err);
        if (op=='+')
            v=v+n;
        else
            v=v-n;
    }

    return v;
}

// / پردازش * و 
static double e2(table *t,const char **s,int *err){

    double v=e3(t,s,err);

    while(**s=='*' || **s=='/'){

        char op=**s;
        (*s)++;

        double n=e3(t,s,err);
        if(op=='*'){
            v=v*n;
        }
        else{
            // جلوگیری از تقسیم بر صفر 
            if(n==0){
                *err=1;
                return 0;
            }
            v=v/n;
        }
    }

    return v;
}

// عدد، پرانتز، تابع یا ارجاع سلولی 
static double e3(table *t,const char **s,int *err){

    // اگر پرانتز بود 
    if(**s=='('){

        (*s)++;
        double v=e1(t,s,err);

        // بررسی پرانتز بسته
        if(**s==')')
            (*s)++;
        else
            *err=1;

        return v;
    }

    // اگر تابع ریاضی بود 
    if(islower(**s)){

        char name[10];
        int i=0;

        // خواندن اسم تابع 
        while(isalpha(**s)){
            name[i++]=**s;
            (*s)++;
        }
        name[i]='\0';

        // بررسی پرانتز 
        if(**s!='('){
            *err=1;
            return 0;
        }

        (*s)++;
        double v=e1(t,s,err);

        if(**s==')')
            (*s)++;
        else
            *err=1;

        // اجرای تابع 
        if(strcmp(name,"sin")==0)
            return sin(v);
        if(strcmp(name,"cos")==0)
            return cos(v);
        if(strcmp(name,"tan")==0)
            return tan(v);
        if(strcmp(name,"sqrt")==0){
            if (v<0){ 
                *err=1; 
                return 0; 
            }
            return sqrt(v);
        }
        if(strcmp(name,"log")==0){
            if(v<=0){ 
                *err=1;
                return 0;
            }
            return log(v);
        }

        // تابع ناشناخته 
        *err=1;
        return 0;
    }

    // اگر ارجاع سلولی بود مثل A1 
    if(isupper(**s)){

        char ch=**s;
        (*s)++;

        int num=0;
        while(isdigit(**s)){
            num=num*10+(**s-'0');
            (*s)++;
        }

        cell *p=find(t,ch,num);
        if(p==NULL){
            *err=1;
            return 0;
        }

        return (*p).val;
    }

    // اگر عدد معمولی بود 
    return strtod(*s,(char**)s);
}
