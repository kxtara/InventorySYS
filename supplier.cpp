#include "db.h"
#include "product.h"
#include <iostream>
#include <unordered_set>

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
void updateSupplier(PGconn* conn, int supplierId, const std::string& column, const std::string& value) {
    static const std::unordered_set<std::string> validColumns = {
        "suppliername", "phone","email"
    };

 // temporary protection
if (validColumns.count(column)) {
    std::string query = "UPDATE supplier SET " + column + " = '" + value + "' WHERE id = " + std::to_string(supplierId) + ";";
    runQuery(conn, query);
}
else {
    std::cerr << "Invalid column name: " << column << std::endl;
}
};
void viewSupplier(PGconn* conn, int supplierId) {
    std::string query = "SELECT * FROM supplier WHERE id = " + std::to_string(supplierId) + ";";
    runQuery(conn, query);
}
static void deleteSupplier(PGconn* conn, int supplierId) {
    std::string query = "DELETE FROM product WHERE id='" + std::to_string(supplierId) + "';";
    runQuery(conn, query);
};