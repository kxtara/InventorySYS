// InventorySYS.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream> // standard c++ IO
#include <cstdlib>
#include <fstream>
#include <string>
#include "db.h"
#include "supplier.h"
#include "product.h"
using namespace std;

int main()
{
    ifstream inputFile(".env"); // open .env file

    if (!inputFile.is_open()) {
        cerr << "Error : Could not open the file!" << endl;
        return 1;
    }
    string conninfo;
    string line;

    while (getline(inputFile, line)) {
        // read line-by-line
        size_t found = line.find('=');
        if (found != string::npos) {
            conninfo = line.substr(found + 1);
        }
        
    }
    inputFile.close();

    auto conn = connectToDB(conninfo);    
    if (!conn) return 1;

    int choice = 0;
     // This has an error, after choosing multiple options it prints out infinitely 
    /*while (choice != 4) {
        std::cout << "1. View all customers\n2. Add a customer.\n3. Delete a customer\n4. Exit\n";
    std::cin >> choice;

        switch (choice) {
        case 1: {
              viewCustomers(conn);
              break;
        }
        case 2: {
            std::string name, address, phone;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover newline
            std::cout << "Name: ";
            std::getline(std::cin, name);

            std::cout << "Address: ";
            std::getline(std::cin, address);

            std::cout << "Phone: ";
            std::getline(std::cin, phone);

            addCustomer(conn, name, address, phone);
            break;
        }
        case 3: {
            int customerId;
            // infinite loop???
            std::cout << "customerId: "; std::cin >> customerId;
            deleteCustomer(conn, customerId);
            break;
        }
        case 4: {
            std::cout << "Exiting...\n";
            break;
        }
        default: {
            std::cout << "Invalid choice\n";
        }
        }
    }*/


    //addProduct(conn, "iPhone XR 64GB", "Fairly used black iPhone XR 64GB with minor scratches.",1,349.99,ELECTRONICS,1);
    /*cout << "View all Suppliers: \n" << endl ;
    viewSuppliers(conn);
    cout << "Update supplier\n" << endl;
    updateSupplier(conn,4,"email","Foodincoporation@foodinc.com");*/
    // deleteSupplier(conn,4);

   /* cout << "Delete product by id:" << endl;
    deleteProduct(conn,1);*/
    /*cout << "Now view all Products: \n" << endl;
    viewProducts(conn);*/

    viewCustomers(conn);
    //addCustomer(conn, "GINNY", "1234 park DV", "757-677-0098");
    //deleteCustomer(conn, 15);
    closeConnection(conn);

    //Add explicit flush to ensure output appears before exit
    cout.flush();
    return 0;
}

