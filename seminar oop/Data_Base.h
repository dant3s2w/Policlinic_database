#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "policlinic.h"
#include <cstring>
struct data_base {
	int size;
	Policlinic* arr;
};
data_base add_medic(data_base base);
data_base delete_medic(data_base base);
int find_medic(data_base base, char* surname, char* name);
data_base* find_type_medic(data_base base, int specialty);
void print_medics(data_base base);