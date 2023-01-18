#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void show_bdds(MYSQL* conn) {

        MYSQL_RES *res;
        MYSQL_ROW row;
        
        char *server = "localhost";
        char *user = "root";
        char *password = "user";
        char *dbname = "massi";

        char query[258];

        conn = mysql_init(NULL);

        if (!mysql_real_connect(conn, server, user, password, dbname, 3306, NULL, 0))
        {
            fprintf(stderr, "\n%s\n", mysql_error(conn));
            exit(1);
        }

        sprintf(query, "SHOW DATABASES");
        mysql_query(conn, query);
        res = mysql_use_result(conn);

        printf("Les BDD dans le serveur '%s': \n", server);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("- %s \n", row[0]);
        }

        mysql_free_result(res);
        mysql_close(conn);
}
