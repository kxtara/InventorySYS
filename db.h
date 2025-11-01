#pragma once
#include <libpq-fe.h>
#include <string>

// These are declarations — not actual code yet!
PGconn* connectToDB(const std::string& conninfo);
void runQuery(PGconn* conn, const std::string& query);
void closeConnection(PGconn* conn);

// Customer
void viewCustomers(PGconn* conn);
void addCustomer(PGconn* conn, const std::string& name, const std::string& address, const std::string& phone);
void deleteCustomer(PGconn* conn, int customerId);