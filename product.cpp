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

// this function works
void viewProducts(PGconn* conn) {
	runQuery(conn, "SELECT * FROM product;");
};

// this function works
void addProduct(PGconn* conn, const std::string& name, const std::string& description,
    int quantity, double price, CategoryProd category,
    int supplierId)
{
    std::string categoryStr = categoryToString(category);
    std::string query =
        "INSERT INTO product (name, description, quantity, price, category, \"supplierId\") VALUES ('"
        + name + "', '"
        + description + "', "
        + std::to_string(quantity) + ", "
        + std::to_string(price) + ", '"
        + categoryStr + "', "
        + std::to_string(supplierId) + ");";

    runQuery(conn, query);
    // testing git author
} 

/* --test--
update product - take in column values to make changes
supplier -- values from run query needs to take different types -
*/
void updateProduct(PGconn* conn, int productId) {
    std::string query = "UPDATE product WHERE id='" + std::to_string(productId) + "' SET description=testing;";
    runQuery(conn, query);
};

// the functions below work
void viewProductCategory(PGconn* conn, CategoryProd category) {
    std::string categoryStr = categoryToString(category);
    std::string query = "SELECT * FROM product WHERE category='" + categoryStr + "';";
    runQuery(conn, query);
};
void deleteProduct(PGconn* conn, int productId) {
    std::string query = "DELETE FROM product WHERE id='" + std::to_string(productId) + "';";
    runQuery(conn, query);
};