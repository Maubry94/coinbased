#include <stdio.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include <stdlib.h>

int main() {

    MYSQL *mysql;
    mysql = mysql_init(NULL);
    mysql_options(mysql, MYSQL_READ_DEFAULT_GROUP, "option");

    char name[30];
    char password[30];
    char mail[30];
    char query[300];
    int selection=2;

    if (mysql_real_connect(mysql, "localhost", "root", "", "coinbased", 0, NULL, 0)) {
        //printf("MySQL client version: %s\n", mysql_get_client_info());

        while(selection !=0 && selection !=1){
            printf("Inscription = 0 Connexion = 1 : ");
            scanf("%d", &selection);
        }

        fflush(stdin);

        if(selection==0){
            printf("INSCRIPTION : \n");
            printf("Entrez votre pseudo: ");
            fgets(name, sizeof(name), stdin);

            printf("Entrez votre mot de passe: ");
            fgets(password, sizeof(password), stdin);

            printf("Entrez votre mail: ");
            fgets(mail, sizeof(mail), stdin);

            sprintf(query, "INSERT INTO user (name, password, email) VALUES ( ('%s') ,('%s'),('%s'))", name, password, mail);
            mysql_query(mysql, query);

        }else {
            printf("CONNEXION\n");

            printf("Entrez votre pseudo: ");
            fgets(name, sizeof(name), stdin);

            printf("Entrez votre mot de passe: ");
            fgets(password, sizeof(password), stdin);

            sprintf(query, "SELECT name AND password FROM user WHERE name=('%s') and password=('%s')", name, password);

            mysql_query(mysql, query);

            MYSQL_RES *result;
            result = mysql_store_result(mysql);

            MYSQL_ROW row;
            if((row = mysql_fetch_row(result)) != NULL){
                printf("Bienvenue !");
            }else{
                printf("Identifiant/Mot de Passe Incorrect");
            }
        }

        fflush(stdin);

        //printf("Enter name: ");
        //fgets(name, sizeof(name), stdin);
        //printf("Name: ");
        //puts(name);
        //mysql_query(mysql, "INSERT INTO user VALUES(2, ('%s') ,'azerty','test.hennou@gmail.com')", name)

        //sprintf(query, "INSERT INTO user (name, password, email) VALUES ( ('%s') ,'azerty','test2.hennou@gmail.com')", name);
        //mysql_query(mysql, query);
        mysql_close(mysql);
    } else {
        printf("Erreur connexion à la BDD!");
    }
    return EXIT_SUCCESS;
}