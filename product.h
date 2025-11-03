#pragma once
#include <libpq-fe.h>
#include <string>
#include "category.h"

void viewProducts(PGconn* conn);
void addProduct(PGconn* conn, const std::string& name, const std::string& description, int quantity, double price, CategoryProd category, int supplierId); //supplier
void updateProduct(PGconn* conn, int productId);
void viewProductCategory(PGconn* conn, CategoryProd category);
void deleteProduct(PGconn* conn, int productId);