/* Show the CGI (Common Gateway Interface) environment variables */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql.h>

/* Print a basic HTTP header. */

static void
print_http_header(const char *content_type)
{
    printf("Content-Type: %s\n\n", content_type);
}

int main()
{

    int i;
    print_http_header("text/html");
    printf("<!DOCTYPE html>");
    printf(
    "<html lang=\"en\">"
    "<head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    "<title>TC47 LOGS</title>"
    "<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6\" crossorigin=\"anonymous\"/>"
    "<style>body {background-color: #1e1e2d;background-image: linear-gradient(to bottom right,#1e1e2e,#1e1e24);height: 100vh;}</style>"
    "</head>");
    printf("<body>");
    printf("<main class=\"container\">");

    MYSQL *con = mysql_init(NULL);
    // printf("MySQL client version: %s\n", mysql_get_client_info());
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "root_pswd",
                            NULL,0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    if (mysql_query(con, "CREATE DATABASE Sensor_Data"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
	}	
	if (mysql_query(con, "USE Sensor_Data"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
	}

    if (mysql_query(con, "CREATE TABLE Data(id INT NOT NULL AUTO_INCREMENT, PRIMARY KEY (id), Data INT,Temperatuur INT, date_time datetime NOT NULL DEFAULT CURRENT_TIMESTAMP)"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		return;
	}

    mysql_query(con, "SELECT * FROM `Sensor_Data`");
    MYSQL_RES *confres = mysql_store_result(con);
    int totalrows = mysql_num_rows(confres);
    int numfields = mysql_num_fields(confres);
    MYSQL_ROW row;
    MYSQL_FIELD *mfield;

    printf("<div class=\"row \">");
    printf("<div class=\"col \">");
    printf("<div class=\"table-responsive\">");
    printf("<table class=\"table text-white\"><caption>sensor logs.</caption><thead><tr><th scope=\"col\">#</th><th scope=\"col\">Temperatuur</th><th scope=\"col\">Tijdstip</th></tr></thead>");
    printf("<tbody>");
    while ((row = mysql_fetch_row(confres)))
    {
        printf("<tr>");
        for (i = 0; i < numfields; i++)
        {
            char *val = row[i];
            printf("<td> %s </td>", val);
        }
        printf("<\tr>");
    }
    printf("</tbody></table></div></div></div></div></main></body></html>");
    return 0;
}