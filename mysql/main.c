#include <stdio.h>
#include <stdlib.h>
#include "include/mysql.h"

// typedef struct
// {
//     char host[20];
//     char user[25];
//     char pass[50];
// } DB_CONN_PARAMS;

int main(int argc, char **argv)
{
    // Initialization of a variable that will be used for the connection
    MYSQL *con = mysql_init(NULL);
    char password[255];
    char login[255];
    char server[255];
    char database[255];
    int port;
    char request[3000];

    // If the variable is NULL, the error is showed and the program stops
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    strcpy(login, "root");
    strcpy(password, "root");
    strcpy(server, "localhost");
    strcpy(database, "coinbased");

    port = 3306;

    // The program tries to connect to the database, if it fails, the program stops after showing the error
    if (mysql_real_connect(con, server, login, password, database, port, NULL, 0) == NULL)
    {
        // fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    strcpy(request, "INSERT INTO users(`first_name`, `last_name`, `email`) VALUES(\"Bob\", \"Obo\", \"bob.obo@gmail.com\")");

    if (mysql_query(con, request))
        printf("%s\n", mysql_error(con));
    mysql_close(con);
    exit(0);
}
