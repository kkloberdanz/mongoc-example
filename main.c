#include <mongoc/mongoc.h>

int main(void) {
    const char *uri_string = "mongodb://localhost:27017/";
    mongoc_client_t *client = NULL;
    bson_error_t error = {0};
    mongoc_database_t *database = NULL;
    bson_t *command = NULL;
    bson_t reply = BSON_INITIALIZER;
    int rc = 0;
    bool ok = true;

    // Initialize the MongoDB C Driver.
    mongoc_init();

    client = mongoc_client_new(uri_string);
    if (!client) {
        fprintf(stderr, "Failed to create a MongoDB client.\n");
        rc = 1;
        goto cleanup;
    }

    // Get a handle on the "admin" database.
    database = mongoc_client_get_database(client, "admin");
    if (!database) {
        fprintf(stderr, "Failed to get a MongoDB database handle.\n");
        rc = 1;
        goto cleanup;
    }

    // Ping the database.
    command = BCON_NEW("ping", BCON_INT32(1));
    ok = mongoc_database_command_simple(
        database, command, NULL, &reply, &error
    );
    if (!ok) {
        fprintf(stderr, "error: %s\n", error.message);
        rc = 1;
        goto cleanup;
    }
    bson_destroy(&reply);

    printf("Pinged your deployment. You successfully connected to MongoDB!\n");

// Perform cleanup.
cleanup:
    bson_destroy(command);
    mongoc_database_destroy(database);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return rc;
}
