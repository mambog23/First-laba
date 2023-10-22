#pragma once
#include <fstream>
#include "figures.h"
#include "keeper.h"
using namespace std;

class Figures {
public:
	Figures();
	virtual ~Figures();
	virtual void setVal() = 0;
};