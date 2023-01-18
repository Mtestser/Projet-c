#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void delete_column_table(MYSQL* conn) {
	MYSQL_RES *res;
        MYSQL_ROW row;

        char table[50];
        char column[50];
        char query[200];

        printf("Entrez le nom de la table: ");
        scanf("%s", table);
        printf("Entrez le nom de la colonne que vous voulez supprimer : ");
        scanf("%s", column);

        sprintf(query, "ALTER TABLE %s DROP COLUMN %s", table, column);
        if (mysql_query(conn, query)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
            exit(1);
        }

        mysql_free_result(res);
        mysql_close(conn);
}
