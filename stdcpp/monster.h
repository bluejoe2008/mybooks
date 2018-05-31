#include "actor.h"

class Monster : public Actor
{
private:
	string _place; //住所
public:
	Monster(string name, bool gender, string place);

	void say(); //打招呼
	void eat(Actor * & food); //妖怪吃人
};

class NativeMonster : public Monster
{
private:
	long _days; //修行时间
public:
	NativeMonster(string name, bool gender, string place);
};

class ExoticMonster : public Monster
{
private:
	string _home; //出生地
public:
	void say();
	ExoticMonster(string name, bool gender, string place);
};