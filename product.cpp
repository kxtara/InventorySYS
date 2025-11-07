#include "db.h"
#include "product.h"
#include <iostream>
#include <unordered_set>

// Testing completed*
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
void updateProduct(PGconn* conn, int productId, const std::string& column, const std::string& value) {
    static const std::unordered_set<std::string> validColumns = {
        "name", "description","quantity","price","category","suppierId"
    };
        if (validColumns.count(column)) {
            std::string query = "UPDATE product SET " + column + " = '" + value + "' WHERE id = " + std::to_string(productId) + ";";
            runQuery(conn, query);
        }
    else {
        std::cerr << "Invalid column name: " << column << std::endl;

    }
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