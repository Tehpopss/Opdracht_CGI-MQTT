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
    "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    "<title>TC47 LOGS</title>"
    "<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6\" crossorigin=\"anonymous\"/>"
    "<style></style>"
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
    if (mysql_real_connect(con, "localhost", "webuser", "secretpassword",
                            "Sensor_Data",0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
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
    printf("<table class=\"table text-white\"><caption>sensor data.</caption><thead><tr><th scope=\"col\">#</th><th scope=\"col\">Temperatuur</th><th scope=\"col\">Tijdstip</th></tr></thead>");
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