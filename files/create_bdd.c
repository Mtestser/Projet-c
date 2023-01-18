#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void create_bdd(MYSQL* conn) {
  char bdd_name[258];
  char query[256];

  printf("Veuillez saisir le nom de la bdd a creer : \n");
  scanf("%s", bdd_name);

  snprintf(query, sizeof(query), "CREATE DATABASE %s", bdd_name);

  if(mysql_query(conn, query)) {
    fprintf(stderr, "\n%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  } else {
    printf("\nBDD %s crée !", bdd_name);
    mysql_close(conn);
  }
}
