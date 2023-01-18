#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void show_tables(MYSQL* conn) {
	static char *host = "localhost";
	static char *user = "root";
	static char *pass = "user";
	static char hostcase[50];
	static char *dbname = "massi";

	unsigned int port = 3306;
	static char *unix_socket = NULL;
	unsigned int flag = 0;

        MYSQL_RES *res;
        MYSQL_ROW row;

        char database[50];
        char query[256];

        printf("Entrez le nom de la bdd : ");
        scanf("%s", database);

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, host, user, pass, database, 3306,  NULL, 0))
        {
            fprintf(stderr, "\n%s\n", mysql_error(conn));
            exit(1);
        }

        sprintf(query, "SHOW TABLES");
        mysql_query(conn, query);
        res = mysql_use_result(conn);

        printf("Les tables dans la bdd '%s': \n", database);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("- %s \n", row[0]);
        }

        mysql_free_result(res);
        mysql_close(conn);
}
