// CPropertiesReader.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PropertiesReader.h"
#include "Properties.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	CProperties ps;
	ifstream in("sample.properties");
	ps.loadFrom(in);

	CString hotelName = ps.getProperty("hotelName")->getString();
	CString boss = ps.getProperty("boss")->getString();
	int maxClients = ps.getProperty("maxClients")->getInteger();
	bool isOpen = ps.getProperty("isOpen")->getBoolean();

	printf("酒店: %s\r\n老板: %s\r\n最大顾客数: %d\r\n状态: %s\r\n", hotelName, boss, maxClients, isOpen ? "开张" : "打烊"); 
}
