#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void export_table(MYSQL* conn) {
	
        MYSQL_RES* res;
        MYSQL_ROW row;

        // Connect to the database
        char* server = "localhost";
        char* user = "root";
        char* password = "user";
        char* database = "massi";
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, server, user, password, database, 3306, NULL, 0)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
            
        }

        // Get the name of the table
        char table_name[255];
        printf("Enter the name of the table: ");
        scanf("%s", table_name);

        // Execute the SELECT query
        char query[255];
        sprintf(query, "SELECT * FROM %s", table_name);
        if (mysql_query(conn, query)) {
            fprintf(stderr, "%s\n", mysql_error(conn));
            
        }

        // Get the result set
        res = mysql_use_result(conn);

        // Open the file for writing
        char file_name[255];
        sprintf(file_name, "%s-table.txt", table_name);
        FILE* fp;
        fp = fopen(file_name, "w");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file\n");
            
        }else{printf("\nTable exportée avec succes !");}

        // Save the column names to the file
        MYSQL_FIELD* field;
        while ((field = mysql_fetch_field(res)) != NULL) {
            fprintf(fp, "%-*s", 20, field->name);
            fprintf(fp, " | ");
        }
        fprintf(fp, "\n");

        // Print a dividing line
        for (int i = 0; i < mysql_num_fields(res); i++) {
            fprintf(fp, "--------------------");
            fprintf(fp, "-+-");
        }
        fprintf(fp, "\n");

        // Save the result set to the file
        while ((row = mysql_fetch_row(res)) != NULL) {
            for (int i = 0; i < mysql_num_fields(res); i++) {
                fprintf(fp, "%-*s", 20, row[i]);
                fprintf(fp, " | ");
            }
            fprintf(fp, "\n");
        }

        // Print a dividing line
        for (int i = 0; i < mysql_num_fields(res); i++) {
            fprintf(fp, "--------------------");
            fprintf(fp, "-+-");
        }
        fprintf(fp, "\n");

        // Close the file and the connection
        fclose(fp);
        mysql_free_result(res);
        mysql_close(conn);
}
