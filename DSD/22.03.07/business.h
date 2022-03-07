#pragma once
#include"Class.h"


void query(FlightList* flight, char* t);
bool refund(NormalOrderList* ODList, FlightList* flight);
void booking(FlightList* flight, NormalOrderList* ODList, char* Ft, int tnum);
