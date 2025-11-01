#include "db.h"  //run query function
#include "product.h"
#include <iostream>

// Might create diff runQuery function - 
// Testing not completed

std::string static categoryToString(CategoryProd category) {
    switch (category) {
    case CategoryProd::FOOD: return "Food";
    case CategoryProd::CLOTHING: return "Clothing";
    case CategoryProd::ELECTRONICS: return "Electronics";
    }
    return "Food"; // default fallback
}

void viewProducts(PGconn* conn) {
	runQuery(conn, "SELECT * FROM product;");
};
void addProduct(PGconn* conn, std::string& name, std::string& description, int quantity, double price, CategoryProd category) {
    std::string categoryStr = categoryToString(category);
    std::string query = "INSERT INTO product (name, description, quantity, price, category) VALUES ('"
        + name + "', '"
        + description + "', "
        + std::to_string(quantity) + ", "
        + std::to_string(price) + ", "
        + categoryStr + ");";
	runQuery(conn,query);
};

//supplier -- values from run query needs to take different types
void updateProduct(PGconn* conn, int productId) {
    std::string query = "UPDATE product WHERE id='" + std::to_string(productId) + "' SET description=testing;";
    runQuery(conn, query);
};
void viewProductCategory(PGconn* conn, CategoryProd category) {
    std::string categoryStr = categoryToString(category);
    std::string query = "SELECT * FROM product WHERE category='" + categoryStr + "';";
    runQuery(conn, query);
};
void deleteProduct(PGconn* conn, int productId) {
    std::string query = "DELETE FROM product WHERE id='" + std::to_string(productId) + "';";
    runQuery(conn, query);
};