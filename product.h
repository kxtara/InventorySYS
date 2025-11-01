#pragma once
#include <libpq-fe.h>
#include <string>
#include "category.h"

/*
1. View Product by getting the productID
2. Add Product (int pk, string name, string description, int quantity, double price, string category (might use enum - should return a string), int fk (supplierID) supplierID (might use enum))
3. Update product with productID
4. View product based on category or supplier--
5. Delete product with productID

*/
void viewProducts(PGconn* conn);
void addProduct(PGconn* conn, std::string& name, std::string& description, int quantity, double price, CategoryProd category); //supplier
void updateProduct(PGconn* conn, int productId);
void viewProductCategory(PGconn* conn, CategoryProd category);
void deleteProduct(PGconn* conn, int productId);