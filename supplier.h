#pragma once
#include <libpq-fe.h>
#include <string>

void viewSuppliers(PGconn* conn);
void addSupplier(PGconn* conn, const std::string& suppliername, const std::string& phone, const std::string& email);
// view by specfic supplier, update supplier info, delete product