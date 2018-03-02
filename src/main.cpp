#include <libpq-fe.h>
#include <cstdio>
#include <cstdlib>

#define UNUSED(x) (void)(x)

PGconn *dbConnection = nullptr;
PGresult *res = nullptr;

static void terminate(int code) {
    if (code != 0) {
        fprintf(stderr, "%s\n", PQerrorMessage(dbConnection));
    }

    if (res != nullptr) {
        PQclear(res);
    }

    if (dbConnection != nullptr) {
        PQfinish(dbConnection);
    }

    exit(code);
}

static void clearRes() {
    PQclear(res);
    res = nullptr;
}

static void processNotice(void *arg, const char *message) {
    UNUSED(arg);
    UNUSED(message);
}

int main() {


    int libpq_ver = PQlibVersion();
    printf("Version of libpq: %d\n", libpq_ver);

    dbConnection = PQconnectdb("user=rienel password=1957 host=127.0.0.1 dbname=testdb");
    if (PQstatus(dbConnection) != CONNECTION_OK) {
        terminate(1);
    }

    PQsetNoticeProcessor(dbConnection, processNotice, nullptr);

    int server_ver = PQserverVersion(dbConnection);
    char *user = PQuser(dbConnection);
    char *db_name = PQdb(dbConnection);

    printf("Server version: %d\n", server_ver);
    printf("User: %s\n", user);
    printf("DB name: %s\n", db_name);

    res = PQexec(dbConnection, "SELECT * FROM students");
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        terminate(1);
    }

    int ncols = PQnfields(res);
    printf("In \"student\" table have %d columns", ncols);
    for (int i = 0; i < ncols; i++) {
        char *name = PQfname(res, i);
        printf(" %s", name);
    }
    printf("\n");

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char *stud_id = PQgetvalue(res, i, 0);
        char *first_name = PQgetvalue(res, i, 1);
        char *name = PQgetvalue(res, i, 2);
        printf("Id: %s, first_name: %s, name: %s", stud_id, first_name, name);
    }
    printf("Total: %d rows\n", nrows);

    clearRes();
    terminate(0);
    return 0;
}