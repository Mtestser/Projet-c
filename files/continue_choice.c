#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void continue_choice(MYSQL* conn) {
	int end = 1;

	printf("\n\nVoulez vous continuer ?");
        printf("\n1- Oui");
        printf("\n2- Non");
        printf("\nvotre choix : ");
        scanf("%d", &end);
}
