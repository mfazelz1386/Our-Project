#include "data.h"
#include <stdio.h>
//مقداردهی اولیه جدول //
void start(table *t) {
    int i,j;

    // تنظیم تعداد سطر و ستون //
    (*t).r=ROW;
    (*t).c=COL;

    // پیمایش همه سلول‌ها //
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {

            // ساخت آدرس مثل A1 //
            sprintf((*t).a[i][j].addr, "%c%d", 'A'+j, i+1);

            // مقدار اولیه صفر //
            (*t).a[i][j].val=0;

            // فرمول خالی //
            (*t).a[i][j].form[0]='\0';

            // بدون فرمول و بدون خطا //
            (*t).a[i][j].has=0;
            (*t).a[i][j].err=0;
        }
    }
}

// پیدا کردن سلول با آدرس //
cell* find(table *t, char ch, int num) {

    // تبدیل حرف و عدد به اندیس //
    int x=ch - 'A';
    int y=num - 1;

    // بررسی معتبر بودن آدرس //
    if (x<0 || x >= (*t).c || y<0 || y >= (*t).r)
        return NULL;

    // برگرداندن آدرس سلول //
    return &((*t).a[y][x]);
}
