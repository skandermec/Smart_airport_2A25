#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("betterair");
db.setUserName("system");
db.setPassword("skander2002");

if (db.open())
test=true;





    return  test;
}
