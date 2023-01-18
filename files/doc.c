#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void doc(MYSQL* conn) {
	CURL *curl = curl_easy_init();

        if (!curl) {
            fprintf(stderr, "Il y a eu un probleme lors de l'initialisation de curl\n");
        }

        //options
        curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.96.138/curlfile.html");

        //action
        CURLcode result = curl_easy_perform(curl);

        if(result != CURLE_OK){
            fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
        }

        curl_easy_cleanup(curl);
}
