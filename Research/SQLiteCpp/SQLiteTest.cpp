#include <iostream>
#include "sqlite3.h"

static int callback(void* data, int argc, char** azValue, char** azColName) {
    for (int i = 0; i < argc; i++) 
    {
        std::cout << azColName[i] << " = " << (azValue[i] ? azValue[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main() 
{
    sqlite3* db;
    char* errMsg = 0;
    int rc;

    // Open database
    rc = sqlite3_open("D:\\Code\\Projects\\SQLite\\address_book.sqlite", &db);
    if (rc) 
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return(0);
    }
    else 
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Create SQL table
    const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS MyTable (id INTEGER PRIMARY KEY, value TEXT);";
    rc = sqlite3_exec(db, sqlCreateTable, callback, 0, &errMsg);

    if (rc != SQLITE_OK) 
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else 
    {
        std::cout << "Table created successfully" << std::endl;
    }

    // Insert data
    const char* sqlInsert = "INSERT INTO MyTable (value) VALUES ('Hello World');";
    rc = sqlite3_exec(db, sqlInsert, callback, 0, &errMsg);

    if (rc != SQLITE_OK) 
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else 
    {
        std::cout << "Data inserted successfully" << std::endl;
    }

    // Query data
    const char* sqlSelect = "SELECT * FROM MyTable;";
    rc = sqlite3_exec(db, sqlSelect, callback, 0, &errMsg);

    if (rc != SQLITE_OK) 
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Close database
    sqlite3_close(db);

    return 0;
}