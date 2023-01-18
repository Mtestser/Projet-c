#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void use_bdd(MYSQL* conn) {
	char bdd_name[258];
        char query[256];

        printf("Veuillez saisir le nom de la BASE a utiliser: \n");
        scanf("%s", &bdd_name);

        snprintf(query, sizeof(query), "USE %s", bdd_name);

        if(mysql_query(conn, query))
        {
            fprintf(stderr, "\n%s\n", mysql_error(conn));
            mysql_close(conn);
            exit(1);
        }else{printf("\nBDD %s utilisée !", bdd_name);}
        mysql_close(conn);
}
