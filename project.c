// C project 2i1
// Made by : Massinissa KANEM & Mathis MAGNE
// DATE : 16/01/2023
// Teacher : Frederic SANANES

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <curl/curl.h>

// including files

#include "files/create_bdd.c"
#include "files/create_table.c"
#include "files/use_bdd.c"
#include "files/delete_bdd.c"
#include "files/rename_table.c"
#include "files/insert_into_table.c"
#include "files/line.c"
#include "files/select_table.c"
#include "files/delete_column_table.c"
#include "files/delete_table.c"
#include "files/rename_column.c"
#include "files/show_tables.c"
#include "files/show_bdds.c"
#include "files/export_table.c"
#include "files/add_column.c"
#include "files/doc.c"
#include "files/continue_choice.c"

static char *host = "localhost";
static char *user = "root";
static char *pass = "user";
static char hostcase[50];
static char *dbname = "massi";

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main(){

    int choice1;
    int choice2;
    int retour = 1;

    MYSQL *conn;
    conn = mysql_init(NULL);

    printf("Choisissez : ");
    printf("\n1- modifier une base de donnees existante.");
    printf("\n2- Creer une nouvelle base de donnees.");
    printf("\n3- Consulter la doc (curl).");
    printf("\nVotre choix : ");
    scanf("%d", &choice1);
    fflush(stdout);

    while(choice1 < 1 || choice1 > 3){
         printf("Choisissez : ");
         printf("\n1- modifier une base de donnees existante.");
         printf("\n2- Creer une nouvelle base de donnees.");
	 printf("\n3- Consulter la doc (curl).");
         printf("\nVotre choix : ");
         scanf("%d", &choice1);
	 fflush(stdout);
     }
//1
    if(choice1 == 1){

        printf("\nEntrez le nom  de la base de donnée à laquelle vous souhaitez vous connecter : ");
        scanf("%s", hostcase);
        fflush(stdout);

        if(!(mysql_real_connect(conn, host, user, pass,hostcase , 3306, NULL, 0)))
        {
            fprintf(stderr, "\nError: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
            printf("\nNous sommes désolé, nous n'avons pas trouvé votre base de donnée, elle est peut etre mal orthographiée ou inexistante. Veuillez réessayer.\n\n");

        }else{
            printf("\nVous etes connectés a la base de donnée : %s !\n\n", hostcase);

            //choix commandes :
	int end = 1;

	while(end == 1){
            printf("Choisissez selon votre besoin : \n");
            printf("1- creation de base de données \n");
            printf("2- creation d'une table dans une base de données \n");
            printf("3- parcourir les bases de données \n");
            printf("4- suppression de base de données \n");
            printf("5- renommer une base de données \n");
            printf("6- Remplir une table \n");
            printf("7- affichage des résultats \n");
            printf("8- supprimer une ligne d'une table \n");
            printf("9- supprimer une colonne d'une table \n");
            printf("10- supprimer une table \n");
	    printf("11- renommer une colonne d'une table \n");
	    printf("12- afficher les tables de la bdd \n");
	    printf("13- afficher les bases dans le serveur mysql \n");
	    printf("14- faire un export d'une table \n");
	    printf("15- Ajouter une colonne à une table \n");
	    printf("16- Consulter la doc (curl) \n");
            printf("Votre choix : ");
            scanf("%d", &choice2);

            while(choice2 < 1 || choice2 > 16){
                printf("De 1 a 16, pas %s \n", choice2);
                printf("1- creation de base de données \n");
                printf("2- creation d'une table dans une base de données \n");
                printf("3- parcourir les bases de données \n");
                printf("4- suppression de base de données \n");
                printf("5- renommer une base de données \n");
                printf("6- Remplir une table \n");
                printf("7- affichage des résultats \n");
                printf("8- supprimer une ligne d'une table \n");
                printf("9- supprimer une colonne d'une table \n");
                printf("10- supprimer une table \n");
		printf("11- renommer une colonne d'une table \n");
		printf("12- afficher les tables de la bdd \n");
		printf("13- afficher les bases dans le serveur mysql \n");
		printf("14- faire un export d'une table \n");
		printf("15- Ajouter une colonne à une table \n");
		printf("16- Consulter la doc (curl) \n");
                printf("Votre choix : ");
                scanf("%d", &choice2);
            }

            switch (choice2){
                case 1: {
			create_bdd(conn);
			
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
		}
		case 2: {
                        create_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 3: {
                        use_bdd(conn);
                        continue_choice(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 4: {
                        delete_bdd(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 5: {
                        rename_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 6: {
                        insert_into_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 7: {
                        select_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 8: {
                        line(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 9: {
                        delete_column_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 10: {
                        delete_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 11: {
                        rename_column(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 12: {
                        show_tables(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 13: {
                        show_bdds(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 14: {
                        export_table(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 15: {
                        add_column(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
		case 16: {
                        doc(conn);
                        
			printf("\n\nVoulez vous continuer ?");
			printf("\n1- Oui");
			printf("\n2- Non");
			printf("\nvotre choix : ");
			scanf("%d", &end);
			if(end == 2){
            			break;
        		}
			break;
                }
	}
}
//2
}	}else if (choice1 == 2){

        	if(!(mysql_real_connect(conn, host, user, pass, dbname, 3306,  NULL, 0)))
        	{
            		fprintf(stderr, "\nError: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
            		exit(1);
        	}
        	else {printf("Connexion Reussie !\n\n");}

        	//demande d'infos (BDD)
        	char bdd_name[258];
		char query[258];

        	printf("Veuillez saisir le nom de votre BASE : ");
        	scanf("%s", &bdd_name);

        	sprintf(query, "CREATE DATABASE %s", bdd_name);

        	if(mysql_query(conn, query))
        	{
            		fprintf(stderr, "\n%s\n", mysql_error(conn));
            		mysql_close(conn);
            		exit(1);
        	}else{printf("\n\nBDD %s créée avec succés !");}

	}else{
		doc(conn);
	}
}
