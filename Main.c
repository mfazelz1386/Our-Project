#include <stdio.h>
#include <string.h>
#include "data.h"
#include "calc.h"
#include "file.h"

int main() {

    table t;
    int choice;
    char ch;
    int num;
    char input[300];

    start(&t);

    while (1) {

        printf("\n1= write formule\n");
        printf("2= watch valou of cell\n");
        printf("3= save to file\n");
        printf("4= exit\n");
        printf(" entekhab kon: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("address cell(example A1):");
            scanf(" %c%d", &ch, &num);

            printf("formule: ");
            scanf("%s", input);

            cell *p = find(&t, ch, num);
            if (p == NULL) {
                printf("wrong address\n");
            } else {
                strcpy((*p).form, input);
                (*p).has = 1;
                (*p).val = calc(&t, (*p).form, &(*p).err);

                if ((*p).err)
                    printf("error in formule\n");
                else
                    printf("saving\n");
            }
        }

        else if (choice == 2) {

            printf("address cell: ");
            scanf(" %c%d", &ch, &num);

            cell *p = find(&t, ch, num);
            if (p == NULL)
                printf("wrong address\n");
            else
                printf("valou = %lf\n", (*p).val);
        }

        else if (choice == 3) {
            save(&t, "out.txt");
            printf("saveing\n");
        }

        else if (choice == 4) {
            break;
        }
        else {
            printf("entekhab na moatabar\n");
        }
    }

    return 0;
}
