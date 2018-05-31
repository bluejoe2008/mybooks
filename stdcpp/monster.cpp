#include "monster.h"

Monster::Monster(string name, bool gender, string place)
	: Actor(name, gender), _place(place)
{
}

void Monster::say()
{
	//我乃常山赵子龙是也...
	Actor::say("我乃" + _place + _name + "是也...");
}

void Monster::eat(Actor * & food)
{
	cout << _name << "吃掉" << food->_name << "..." << endl;

	//销毁掉actor对象
	delete food;
	food = 0;
}

NativeMonster::NativeMonster(string name, bool gender, string place)
	: Monster(name, gender, place)
{
}

ExoticMonster::ExoticMonster(string name, bool gender, string place)
	: Monster(name, gender, place)
{
}

void ExoticMonster::say()
{
	Actor::say("我乃仙子下凡" + _name + "是也...");
}
