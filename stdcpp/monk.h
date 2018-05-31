#include "actor.h"

#ifndef __MONK__
#define __MONK__

class Monk : public Actor
{
private:
	string _monkName; //法名
public:
	void setName(string name);
	Monk(string name, string monkName);
	~Monk();
	void say(); //打招呼
	void patter(); //念经
};

#endif