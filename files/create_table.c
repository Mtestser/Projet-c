#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void create_table(MYSQL* conn){

/*
static char *host = "localhost";
static char *user = "root";
static char *pass = "user";
static char hostcase[50];
static char *dbname = "massi";


unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;*/
char table_name[256];
char query[256];


	//MYSQL* conn = mysql_init(NULL);
        /*if (!mysql_real_connect(conn, host, user, pass,hostcase , 3306, NULL, 0)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
            return 1;
        }*/

	printf("Entrez le nom de la table : ");
	scanf("%s", table_name);
	sprintf(query, "CREATE TABLE %s (id INT NOT NULL AUTO_INCREMENT PRIMARY KEY)", table_name);

	// execute the query
	if (mysql_query(conn, query)) {
	    fprintf(stderr, "%s\n", mysql_error(conn));
	}else{printf("Table %s crée avec succés ! ", table_name);}
	mysql_close(conn);
       
}
