#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void rename_table(MYSQL* conn) {
  	char table_name[258];
	char table_name_after[258];

	printf("Veuillez saisir le nom de la table à modifier : \n");
	scanf("%s", &table_name);
	printf("Veuillez saisir le nouveau nom de table : \n");
	scanf("%s", &table_name_after);

	char query[256];
	snprintf(query, sizeof(query), "RENAME TABLE %s TO %s", table_name, table_name_after);

	if(mysql_query(conn, query))
	{
	    fprintf(stderr, "\n%s\n", mysql_error(conn));
	    mysql_close(conn);
	    exit(1);
	}else{printf("\nLa bdd %s est devenue %s !", table_name, table_name_after);exit(1);}

	mysql_close(conn);
}
