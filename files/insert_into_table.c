#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void insert_into_table(MYSQL* conn) {
  	char table_name[128];
        char column_names[128];
        char values[128];

        printf("Entrez le nom de la table : ");
        scanf("%s", table_name);

        printf("Entrez les noms des colonnes dans lesquelles insérer, séparés par des virgules : ");
        scanf("%s", column_names);

        printf("Entrez les valeurs à insérer, séparées par des virgules : ");
        scanf("%s", values);

        char query[256];
        snprintf(query, sizeof(query), "INSERT INTO %s (%s) VALUES (%s)", table_name, column_names, values);

        if(mysql_query(conn, query))
        {
            fprintf(stderr, "\n%s\n", mysql_error(conn));
            mysql_close(conn);
            exit(1);
        }else{printf("\nL'ajout à la table %s réussi !", table_name);exit(1);}

        mysql_close(conn);
}
