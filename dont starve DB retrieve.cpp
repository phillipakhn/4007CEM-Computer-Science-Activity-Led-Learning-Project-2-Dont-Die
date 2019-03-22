//
//  main.cpp
//  DontStarveOriginal
//
//  Created by Avelino Tomas on 04/03/2019.
//  Copyright © 2019 Avelino Tomas. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

/* void*, Data provided in the 4th argument of sqlite3_exec() */
/* int,  The number of columns in row */
/* char**, An array of strings representing fields in the row */
/* char** An array of strings representing column names */

static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    
    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n");
    return 0;
}

int main(int argc, char* argv[])
{
    sqlite3* DB;
    int exit = 0;
    
    /* Open database */
    exit = sqlite3_open("DontStarve.db", &DB);
    string data("CALLBACK FUNCTION");
    
    /* Create SQL statement and retrieves a table*/
    string sql ("SELECT * FROM Chest;");
    
    if (exit) {
        std::cerr << "Error to open DataBase " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
        
    
    /* Execute SQL statement */
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);
    
    if (rc != SQLITE_OK)
        cerr << "SQL Error SELECT" << endl;
    else {
        cout << "Operation done successfully\n" << endl;
    }
    
    sqlite3_close(DB);
    return (0);
}
