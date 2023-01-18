#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void add_column(MYSQL* conn) {
	char table_name[100];
        char column_name[100];
        char column_type[100];
        int column_size;
        int auto_increment;

        printf("Enter the name of the table: ");
        scanf("%s", table_name);

        printf("Enter the name of the column: ");
        scanf("%s", column_name);

        printf("Enter the type of the column (e.g. INT, VARCHAR): ");
        scanf("%s", column_type);

        printf("Enter the size of the column: ");
        scanf("%d", &column_size);

        printf("En AUTO INCREMENT (1 pour oui / 0 pour non : ");
        scanf("%d", &auto_increment);


        char query[200];

        if (auto_increment) {
            sprintf(query, "ALTER TABLE %s ADD %s %s(%d) AUTO_INCREMENT PRIMARY KEY", table_name, column_name, column_type, column_size); // create the query string
        }else {
            sprintf(query, "ALTER TABLE %s ADD %s %s(%d)", table_name, column_name, column_type, column_size);
        }

        // execute the query
        if (mysql_query(conn, query)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
           
        }

        // close the connection
        mysql_close(conn);
}
