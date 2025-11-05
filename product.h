#pragma once
#include <libpq-fe.h>
#include <string>
#include "category.h"

//-- tested
void viewProducts(PGconn* conn);
void addProduct(PGconn* conn, const std::string& name, const std::string& description, int quantity, double price, CategoryProd category, int supplierId); //supplier

// update product - take in column values to make changes
void updateProduct(PGconn* conn, int productId, const std::string& column, const std::string& value);

//-- tested
void viewProductCategory(PGconn* conn, CategoryProd category);
static void deleteProduct(PGconn* conn, int productId);