#pragma once
#include <libpq-fe.h>
#include <ctime>
/*
primary key - id - integer
customerid - integer
orderdate - date
deliverydate - date
total decimal(10,2)
*/
void viewOrder(PGconn* conn); //orderid - get one order using orderid
void viewOrders(PGconn* conn); //customerid - get all orders using customerid
void addOrder(PGconn* conn, int customerId, time_t orderDate, time_t deliveryDate,double total); 
/*
cancel order
edit order
order status
*/

