#include "Database.h"
#include <vector>

std::vector<int> readPosition;
int play;

/*Function to retrieve the xAxis and yAxis values of a given player from the database.
Input: char "Axis"
Output: int 0 / int 1
References: Database Module 4005CEM Week 6 C++ Sqlite*/
int sqlSelect(char Axis)
{
	std::string sqliteFile = "DontDieDB.db"; // Sets a string to the name of the database.

	try
	{
		sqlite::sqlite db(sqliteFile); // Opens up the database using the "libsqlite.hpp" sprite class.
		auto cur = db.get_statement(); // Sets cur to be used to execute all other functions using the given database.

		if (Axis =='x') // Used to decide which Axis to select from the database.
		{
			cur->set_sql("select Player_ID, xAxis "
				"from POSITION "
				"where Player_ID = ?"); // Sests the SQLite query using the given string.
			cur->prepare(); // Prepares the query.
			cur->bind(1, play); // Binds a value to the given placeholder, in this case Player_ID = play
		}
		else
		{
			cur->set_sql("SELECT Player_ID, yAxis "
				"FROM POSITION "
				"WHERE Player_ID = ?");
			cur->prepare();
			cur->bind(1, play);
		}
		while (cur->step()) // Executes the SQL
			if (Axis == 'x') // Makes sure the X axis value is always pushed before the Y Axis.
			{
				readPosition.push_back(cur->get_int(1)); // Pushes the value of the xAxis to the vector.
				sqlSelect('y'); // Calls the fucntion again but to select the y Axis.
			}
			else
			{
				readPosition.push_back(cur->get_int(1)); // Pushes the Y Axis value to the vector.
			}
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

/*Function to retrieve the xMap and yMap values of a given player from the database.
Input: char "Axis"
Output: int 0 / int 1
References: Database Module 4005CEM Week 6 C++ Sqlite*/
int sqlSelectMap(char Axis) // This function is exactly the same as"sqlSelect" but is used to select the Map values instead.
{
	std::string sqliteFile = "DontDieDB.db";
	try
	{
		sqlite::sqlite db(sqliteFile);
		auto cur = db.get_statement();

		if (Axis == 'x')
		{
			cur->set_sql("select Player_ID, xMap "
				"from POSITION "
				"where Player_ID = ?");
			cur->prepare();
			cur->bind(1, play);
		}
		else
		{
			cur->set_sql("SELECT Player_ID, yMap "
				"FROM POSITION "
				"WHERE Player_ID = ?");
			cur->prepare();
			cur->bind(1, play);
		}
		while (cur->step())
			if (Axis == 'x')
			{
				readPosition.push_back(cur->get_int(1));
				sqlSelectMap('y');
			}
			else
			{
				readPosition.push_back(cur->get_int(1));
			}
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

/*Function to update the xAxis and yAxis values of a given player to the database.
Input: int x, int y
Output: int 0 / int 1
References: Database Module 4005CEM Week 6 C++ Sqlite & <https://www.tutorialspoint.com/sqlite/sqlite_update_query.htm> [online] Date Accessed 15/03/2019*/
int sqlUpdate(int x , int y)
{
	std::string sqliteFile = "DontDieDB.db"; // Sets a string to the name of the database.
	try
	{
		sqlite::sqlite db(sqliteFile);// Opens up the database using the "libsqlite.hpp" sprite class.
		auto cur = db.get_statement();// Sets cur to be used to execute all other functions using the given database.

		cur->set_sql("UPDATE POSITION "
			"SET xAxis = ?, yAxis = ? "
			"WHERE Player_ID = ?");// Sests the SQLite query using the given string.
		cur->prepare();// Prepares the query.
		cur->bind(1, x); // Binds a value to the given placeholder, in this case xAxis = x
		cur->bind(2, y);
		cur->bind(3, play);

		cur->step();
		return 0;
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

/*Function to update the xMap and yMap values of a given player to the database.
Input: int xMap, int yMap
Output: int 0 / int 1
References: Database Module 4005CEM Week 6 C++ Sqlite & <https://www.tutorialspoint.com/sqlite/sqlite_update_query.htm> [online] Date Accessed 15/03/2019*/
int sqlUpdateMap(int xMap, int yMap) // This function is exactly the same as "sqlUpdate" but updates the Map values in the database instead.
{
	std::string sqliteFile = "DontDieDB.db";
	try
	{
		sqlite::sqlite db(sqliteFile);
		auto cur = db.get_statement();

		cur->set_sql("UPDATE POSITION "
			"SET xMap = ?, yMap = ? "
			"WHERE Player_ID = ?");
		cur->prepare();
		cur->bind(1, xMap);
		cur->bind(2, yMap);
		cur->bind(3, play);

		cur->step();
		return 0;
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

/*Function to ask the user to choose which player they want to access which is then used to select and update the database.
Input: N/A
Output: Vector "readPosition"*/
std::vector<int> Position()
{
	std::cout << "Which Player? "; // Asks the player which player to load.
	std::cin >> play; // sets the input to equal the int play.

	sqlSelect('x'); //calls the sqlSelect function to retrieve the Axis coordinates values stored in the database.
	sqlSelectMap('x'); //call the sqlSelectMap function to retrieve the Map values stored in the database.
	return readPosition; // Returns the Vector containing the Axis coordinates and the Maps values
}
