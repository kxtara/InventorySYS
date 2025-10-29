#include "db.h"
#include <iostream>
PGconn* connectToDB(const std::string& conninfo) {
    PGconn* conn = PQconnectdb(conninfo.c_str());
    // PGconn* conn -- declares a pointer representing the connection state

   /*
   PQconnectb -- attempts to connect PostgreSQL using a connection string.That function :
   * Parse the connection string.
   * Opens a socket to the host:port
   * Runs the PostgreSQL authentication handshake (password,etc.)
   * Returns a PGconn * object which represents the connection (even if connection failed - you must check the status).
   */


    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return nullptr;
    }
    /*
    PQstatus(conn) - returns the connection status
    CONNECTION_OK means success. Any other value means the connection didn't succeed.
    PQerrorMessage(conn) — returns a textual error message with details from libpq/Postgres.
    std::cerr << ... — prints the error.
    PQfinish(conn) — closes and frees the PGconn object (important cleanup even on failure).
    return nullptr; — returns a null pointer that points to nothing
    */



    std::cout << "Connected to PostgreSQL successfully!" << std::endl;
    return conn;
}

void runQuery(PGconn* conn, const std::string& query) {
    //const string& query !reference -- doesn't create a copy of the query -- query can't be modified.
    PGresult* res = PQexec(conn, query.c_str());

    ExecStatusType status = PQresultStatus(res);

    if (status == PGRES_TUPLES_OK) {
        // SELECT query
        // Loop through results
        int rows = PQntuples(res);
        int cols = PQnfields(res);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << PQgetvalue(res, i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
    else if (status == PGRES_COMMAND_OK) {
        // INSERT,UPDATE,DELETE query
        std::cout << "Command executed successfully. Rows affected: "
            << PQcmdTuples(res) << std::endl;
    }
    else {
        std::cerr << "Query failed: " << PQerrorMessage(conn) << std::endl;
    }

    PQclear(res);
}

void closeConnection(PGconn* conn) {
    PQfinish(conn);
    std::cout << "Connection closed." << std::endl;
}



//-----

void viewCustomers(PGconn* conn) {
    runQuery(conn, "SELECT * FROM customer;");
}

void addCustomer(PGconn* conn, const std::string& name, const std::string& address, const std::string& phone) {
    std::string query = "INSERT INTO customer (name,address,phone) VALUES ('" + name + "','" + address + "','" + phone + "');";
    runQuery(conn, query);
};

void deleteCustomer(PGconn* conn, int customerId) {
    std::string query = "DELETE FROM customer WHERE id = " + std::to_string(customerId) + ";";
    runQuery(conn, query);
}

//void updateCustomer(PGconn* conn, const std:)