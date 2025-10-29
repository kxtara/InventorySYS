// InventorySYS.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream> // standard c++ IO
#include <libpq-fe.h> // postgresql c client library (APIs)
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inputFile(".env"); // open .env file

    if (!inputFile.is_open()) {
        cerr << "Error : Could not open the file!" << endl;
        return 1;
    }
    string conninfo;
    string line;

    while (getline(inputFile, line)) {
        // read line-by-line
        size_t found = line.find('=');
        if (found != string::npos) {
            conninfo = line.substr(found + 1);
        }
        
    }
    inputFile.close();


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
        cerr << "Connection to database failed: " << PQerrorMessage(conn) << endl;
        PQfinish(conn);
        return 1;
    }
    /*
    PQstatus(conn) - returns the connection status
    CONNECTION_OK means success. Any other value means the connection didn't succeed.
    PQerrorMessage(conn) — returns a textual error message with details from libpq/Postgres.
    std::cerr << ... — prints the error.
    PQfinish(conn) — closes and frees the PGconn object (important cleanup even on failure).
    return 1; — exit with non-zero status to indicate error.
    */



    cout << "Connected to PostgreSQL successfully!" << endl;
    // Perform database operations here

    PGresult* res = PQexec(conn, "SELECT * FROM customer;");
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cerr << "SELECT failed:" << PQerrorMessage(conn) << endl;
        cout << res << endl;
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    cout << "SELECT ran successfully!" << endl;

    // Loop through results
    int rows = PQntuples(res);
    int cols = PQnfields(res);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << PQgetvalue(res,i, j) << " ";
        }
        cout << endl;
    }

   // res = PQexec(conn, "INSERT INTO customer (name,address,phone) VALUES ('jomauris','state road prov4','340-233-9089');");

    PQclear(res);
    PQfinish(conn); // Close the connection
    return 0;
}

