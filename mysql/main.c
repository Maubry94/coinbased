#include <stdio.h>
#include <stdlib.h>
#include "include/mysql.h"

typedef struct
{
    char host[20];
    char user[25];
    char pass[50];
} DB_CONN_PARAMS;

int main(int argc, char **argv)
{
    printf("MySQL client version: %s\n", mysql_get_client_info());
    return 0;
}