#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "data.h"

// ذخیره جدول
void save_table_to_file(table *my_table, const char *filename);

// خواندن جدول
void load_table_from_file(table *my_table, const char *filename);

#endif