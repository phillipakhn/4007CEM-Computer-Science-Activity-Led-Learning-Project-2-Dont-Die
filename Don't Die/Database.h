#pragma once
#include "libsqlite.hpp"
#include <vector>

int sqlSelect(char Axis);
int sqlSelectMap(char Axis);
int sqlUpdate(int x, int y);
int sqlUpdateMap(int xMap, int yMap);
std::vector<int> Position();
