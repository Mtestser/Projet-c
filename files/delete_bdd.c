#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void delete_bdd(MYSQL* conn) {
  	char bdd_name[258];

	printf("Veuillez saisir le nom de la BASE a supprimer: \n");
	scanf("%s", &bdd_name);

	char query[256];
	snprintf(query, sizeof(query), "DROP DATABASE %s", bdd_name);

	if(mysql_query(conn, query))
	{
	    fprintf(stderr, "\n%s\n", mysql_error(conn));
	    mysql_close(conn);
	    exit(1);
	}else{printf("\nBDD %s supprimée !", bdd_name);}
	mysql_close(conn);

}
