#pragma once
#include <libpq-fe.h>
#include <string>

void viewSuppliers(PGconn* conn);
void addSupplier(PGconn* conn, const std::string& suppliername, const std::string& phone, const std::string& email);
void viewSupplier(PGconn* conn, int supplierId);

// update product - take in column values to make changes
void updateSupplier(PGconn* conn, int supplierId);

void deleteSupplier(PGconn* conn, int supplierId);
// view by specfic supplier, update supplier info, delete product