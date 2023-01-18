#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void delete_table(MYSQL* conn) {
        MYSQL_RES *res;
        MYSQL_ROW row;

        char table_name[100];
        char query[200];

        printf("Entez le nom de la table que vous voulez supprimer : ");
        scanf("%s", table_name);

        sprintf(query, "DROP TABLE %s", table_name);

        if (mysql_query(conn, query))
        {
            fprintf(stderr, "%s\n", mysql_error(conn));
            exit(1);
        }

        mysql_close(conn);
}
