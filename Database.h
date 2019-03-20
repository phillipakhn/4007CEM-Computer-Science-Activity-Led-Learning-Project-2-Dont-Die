#pragma once
#include "libsqlite.hpp"
#include <vector>

int sqlSelect(char Axis, int play);
int sqlSelectMap(char Axis, int play);
int sqlUpdate(int x, int y);
int sqlUpdateMap(int xMap, int yMap);
std::vector<int> Position();
