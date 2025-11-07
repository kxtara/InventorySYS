#pragma once
#include <libpq-fe.h>
#include <string>

void viewSuppliers(PGconn* conn);
void addSupplier(PGconn* conn, const std::string& suppliername, const std::string& phone, const std::string& email);
void viewSupplier(PGconn* conn, int supplierId);
void updateSupplier(PGconn* conn, int supplierId,const std::string& column, const std::string& value);
void deleteSupplier(PGconn* conn, int supplierId);