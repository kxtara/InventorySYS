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


/* --test
update product - take in column values to make changes
supplier -- values from run query needs to take different types -
*/
void updateSupplier(PGconn * conn, int supplierId) {
    std::string query = "UPDATE product WHERE id='" + std::to_string(supplierId) + "' SET email=testing;";
    runQuery(conn, query);
};

static void deleteSupplier(PGconn* conn, int supplierId) {
    std::string query = "DELETE FROM product WHERE id='" + std::to_string(supplierId) + "';";
    runQuery(conn, query);
};