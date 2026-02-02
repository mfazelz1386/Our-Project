#include <stdio.h>
#include <string.h>
#include "data.h"
#include "calc.h"
#include "file.h"

int main() {

    table t;

    // مقداردهی اولیه 
    start(&t);

    // فرمول برای A1 
    strcpy(t.a[0][0].form, "sin(3+2)");
    t.a[0][0].has = 1;
    t.a[0][0].val = calc(&t, t.a[0][0].form, &t.a[0][0].err);

    // فرمول برای A2 
    strcpy(t.a[1][0].form, "A1*2+sqrt(16)");
    t.a[1][0].has = 1;
    t.a[1][0].val = calc(&t, t.a[1][0].form, &t.a[1][0].err);

    // نمایش خروجی 
    printf("A1 = %lf\n", t.a[0][0].val);
    printf("A2 = %lf\n", t.a[1][0].val);

    // ذخیره در فایل 
    save(&t, "out.txt");

    return 0;
}