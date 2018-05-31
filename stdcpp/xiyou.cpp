#include <typeinfo>
#include <iostream> 
using namespace std;

#include "monk.h" 
#include "monster.h" 
#include "god.h" 

void f15_4_2()
{
	Actor * tang = new Actor("唐三藏", true);
	Monster bone("白骨精", false, "白骨山");
	
	bone.say();
	bone.eat(tang);
}

void no_rtti()
{
Actor wang("王母娘娘", false);
Actor * ap = &wang;

Monster * mp = (Monster *)&wang;
	Actor * tang = new Monk("唐三藏", "唐玄奘");
mp->eat(tang);
}

void rtti()
{
Actor wang("王母娘娘", false);
Actor * ap = &wang;


Monster * mp = dynamic_cast<Monster *>(ap);
if(mp != NULL)
{
	Actor * tang = new Monk("唐三藏", "唐玄奘");
	mp->eat(tang);
}
else
{
	cout << "ap不是一个Monster *类型!" << endl;
}
}

void rtti_ref()
{
Actor wang("王母娘娘", false);

try
{
	Monster & mr = dynamic_cast<Monster &>(wang);

	Actor * tang = new Monk("唐三藏", "唐玄奘");
	mr.eat(tang);
}
catch(exception bc)
{
	cout << "wang不是一个Monster &类型!" << endl;
}
}

void rtti_novirtual()
{
class A
{
};

class B
{
};

A a;
//B * bp = dynamic_cast<B *>(&a);
}

void rtti_up()
{
Monster bone("白骨精", false, "白骨山");
Monk * mp = dynamic_cast<Monk *>(&bone);
if(mp != NULL)
{
	mp->say();
}
else
{
	cout << "ap不是一个Monster *类型!" << endl;
}
}

void virtual_base()
{
Buddha ru("如来", "释迦摩尼");
ru.patter();
ru.fly();
	//Actor * ap = &ru;
	//Monk * mp = &ru;
	//ru.say();
	//ru.setName("观音菩萨");
	//ru.printName();

}

void rtti_typeid()
{
Actor wang("王母娘娘", false);
Monster bone("白骨精", false, "白骨山");

Actor * ap1 = &wang;
Actor & ar1 = wang;
Actor * ap2 = &bone;
Actor & ar2 = bone;

cout << typeid(ap1).name() << endl;
cout << typeid(ar1).name() << endl;
cout << typeid(*ap1).name() << endl;

cout << typeid(ap2).name() << endl;
cout << typeid(ar2).name() << endl;
cout << typeid(*ap2).name() << endl;
}

void rtti_static()
{
Actor wang("王母娘娘", false);
Monster bone("白骨精", false, "白骨山");

Actor * ap1 = static_cast<Actor *>(&bone); //ok, 安全
Monster * ap2 = static_cast<Monster *>(&wang); //ok, 不安全

God chang("嫦娥", false);
Actor * ap = static_cast<Actor *>(&chang);
Monster * mp = static_cast<Monster *>(ap);
}

void rtti_static2()
{
God chang("嫦娥", false);
Actor * ap = static_cast<Actor *>(&chang); //ok, 安全
Monster * mp = static_cast<Monster *>(ap); //ok, 不安全
God * gp = reinterpret_cast<God *>(mp); //error, 安全


}

void rtti_typeid2()
{
class A
{
};

class B : public A
{
};

B b;
A * ap = &b;
A & ar = b;

A a;

cout << typeid(*ap).name() << endl;
cout << typeid(ar).name() << endl;
}

void rtti_const()
{
int const & i = 100;
//i = 200; //error: 不能修改const对象
int & m = const_cast<int &>(i);
m = 200;

cout << i << endl;
}

ostream & operator<<(ostream & os, const Actor & actor)
{
	//输出姓名和性别
	os << "[" << actor.getName() << ", " << (actor.getGender() ? "男" : "女") << "]";
	return os;
}

void pstream()
{
Monk tang("唐三藏", "唐玄奘");
Monster bone("白骨精", false, "白骨山");
cout << tang << endl;
cout << bone << endl;
}

void foo1(Actor actor)
{
	actor.say();
}

Actor foo2()
{
	return "孙悟空";
}

void ex()
{
string name = "唐三藏";
Actor tang = name; //隐式调用1
tang.say();

name = "猪八戒";
foo1(name); //隐式调用2

foo2().say(); //隐式调用3

}

void arr()
{
}

int main()
{
	//rtti();
	//f15_4_2();
	//rtti_up();
	//rtti_ref();
	//rtti_typeid2();

	//rtti_static2();
	virtual_base();

return 0;

}
