#include "db.h"
#include "product.h"
#include <iostream>

// Tested
void viewSuppliers(PGconn* conn) {
	runQuery(conn, "SELECT * FROM supplier;");

};
void addSupplier(PGconn* conn, const std::string& suppliername, const std::string& phone, const std::string& email) {
    std::string query = "INSERT INTO supplier (suppliername, phone, email) VALUES ('"
        + suppliername + "', '"
        + phone + "', '"
        + email + "');";

    runQuery(conn, query);
};