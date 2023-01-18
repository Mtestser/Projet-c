#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void line(MYSQL* conn) {
	static char *host = "localhost";
	static char *user = "root";
	static char *pass = "user";
	static char hostcase[50];
	static char *dbname = "massi";

	unsigned int port = 3306;
	static char *unix_socket = NULL;
	unsigned int flag = 0;


   	char table_name[256];
        char id_name[256];
        int row_id;

        if (!mysql_real_connect(conn, host, user, pass, dbname, 3306,  NULL, 0)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
           
        }

        printf("Entrez le nom d'une table : ");
        scanf("%s", table_name);
        printf("Entrez le nom de la colonne id : ");
        scanf("%s", id_name);
        printf("Entrez le numero de la ligne a supprimer : ");
        scanf("%d", &row_id);

        char query[256];
        sprintf(query, "DELETE FROM %s WHERE %s=%d", table_name, id_name, row_id);
        if (mysql_query(conn, query)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
            
        }

        printf("La ligne %d a bien ete supprimee de la table '%s' successfully!\n", row_id, table_name);

        mysql_close(conn);
}
