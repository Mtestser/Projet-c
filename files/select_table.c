#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void select_table(MYSQL* conn) {

	static char *host = "localhost";
	static char *user = "root";
	static char *pass = "user";
	static char hostcase[50];
	static char *dbname = "massi";

	unsigned int port = 3306;
	static char *unix_socket = NULL;
	unsigned int flag = 0;
	
	char table_name[128];
        char query[256];

        printf("Entrez le nom de la table : ");
        scanf("%s", table_name);

       
        if (!mysql_real_connect(conn, host, user, pass,dbname , 3306, NULL, 0))
        {
            fprintf(stderr, "Connexion a la bdd non reussi : Error %u (%s)\n", mysql_errno(conn), mysql_error(conn));
            
        }

        snprintf(query, sizeof(query), "SELECT * FROM %s", table_name);

        if (mysql_query(conn, query))
        {
            fprintf(stderr, "Échec d'exécution de la requête: Error %u (%s)\n", mysql_errno(conn), mysql_error(conn));
            mysql_close(conn);
            
        }

        MYSQL_RES *result = mysql_store_result(conn);
        if (!result)
        {
            fprintf(stderr, "Échec de la récupération des résultats de la requête : Error %u (%s)\n", mysql_errno(conn), mysql_error(conn));
            mysql_close(conn);
            
        }
        int num_fields = mysql_num_fields(result);
        MYSQL_FIELD *fields = mysql_fetch_fields(result);

        // Print a dividing line
        for (int i = 0; i < num_fields; i++) {
            printf("--------------------");
            printf("-+-");
        }
        printf("\n");

        // Print the field names
        for (int i = 0; i < num_fields; i++) {
            printf("%-*s", 20, fields[i].name);
            printf(" | ");
        }
        printf("\n");

        // Print a dividing line
        for (int i = 0; i < num_fields; i++) {
            printf("--------------------");
            printf("-+-");
        }
        printf("\n");

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(result)))
        {
            for (int i = 0; i < num_fields; i++)
            {
                printf("%-*s", 20, row[i]);
                printf(" | ");
            }
            printf("\n");
        }

        // Print a dividing line
        for (int i = 0; i < num_fields; i++) {
            printf("--------------------");
            printf("-+-");
        }
        printf("\n");

        mysql_free_result(result);
        mysql_close(conn);
}
