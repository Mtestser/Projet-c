#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void rename_column(MYSQL* conn) {
	static char *host = "localhost";
	static char *user = "root";
	static char *pass = "user";
	static char hostcase[50];
	static char *dbname = "massi";

	unsigned int port = 3306;
	static char *unix_socket = NULL;
	unsigned int flag = 0;

        MYSQL_RES *result;
        MYSQL_ROW row;

        char column[100];
        char new_name[100];
        char table[100];

        printf("Enter the name of the table: ");
        scanf("%s", table);
        printf("Enter the name of the column you want to rename: ");
        scanf("%s", column);
        printf("Enter the new name for the column: ");
        scanf("%s", new_name);

        conn = mysql_init(NULL);
        mysql_real_connect(conn, host, user, pass, dbname, 3306,  NULL, 0);

        char query[200];
        sprintf(query, "ALTER TABLE %s CHANGE %s %s VARCHAR(255)", table, column, new_name);
        mysql_query(conn, query);

        result = mysql_store_result(conn);

        printf("\nColonne renommée avec succès !\n");

        mysql_free_result(result);
        mysql_close(conn);
}
