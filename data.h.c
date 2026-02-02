#ifndef DATA_H
#define DATA_H

// تعداد سطرها //
#define ROW 50

// تعداد ستون‌ها (A تا Z) //
#define COL 26

// حداکثر طول فرمول //
#define MAX 300

// ساختار هر سلول //
typedef struct {
    char addr[5];      // آدرس مثل A1 //
    double val;        // مقدار نهایی //
    char form[MAX];    // فرمول //
    int has;           // آیا فرمول دارد //
    int err;           // خطا //
} cell;

// ساختار کل جدول //
typedef struct {
    cell a[ROW][COL];  // آرایه دوبعدی سلول‌ها //
    int r;             // تعداد سطر //
    int c;             // تعداد ستون //
}table;

// مقداردهی اولیه جدول //
void start(table *t);

// پیدا کردن یک سلول با آدرس //
cell*find(table *t,char ch,int num);

#endif
