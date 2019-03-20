#include "Database.h"
#include <vector>

std::vector<int> readPosition;

int sqlSelect(char Axis, int play)
{
	std::string sqliteFile = "DontDieDB.db";

	try
	{
		sqlite::sqlite db(sqliteFile);
		auto cur = db.get_statement();

		if (Axis =='x')
		{
			cur->set_sql("select Player_ID, xAxis "
				"from POSITION "
				"where Player_ID = ?");
			cur->prepare();
			cur->bind(1, play);
		}
		else
		{
			cur->set_sql("SELECT Player_ID, yAxis "
				"FROM POSITION "
				"WHERE Player_ID = ?");
			cur->prepare();
			cur->bind(1, play);
		}
		while (cur->step())
			if (Axis == 'x')
			{
				readPosition.push_back(cur->get_int(1));
				sqlSelect('y',play);
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

int sqlSelectMap(char Axis, int play)
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
				sqlSelectMap('y', play);
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

int sqlUpdate(int x , int y)
{
	std::string sqliteFile = "DontDieDB.db";
	try
	{
		sqlite::sqlite db(sqliteFile);
		auto cur = db.get_statement();

		cur->set_sql("UPDATE POSITION "
			"SET xAxis = ?, yAxis = ? "
			"WHERE Player_ID = ?");
		cur->prepare();
		cur->bind(1, x);
		cur->bind(2, y);
		cur->bind(3, 1);

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

int sqlUpdateMap(int xMap, int yMap)
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
		cur->bind(3, 1);

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

std::vector<int> Position()
{
	std::cout << "Which Player? ";
	int play;
	std::cin >> play;

	sqlSelect('x',play);
	sqlSelectMap('x',play);
	return readPosition;
}
