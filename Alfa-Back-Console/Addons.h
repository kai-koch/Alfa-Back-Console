#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

template <typename Dauer, typename Func>
void timer(Dauer const & d, Func const & f)
{
	std::thread([d, f]() {
		std::this_thread::sleep_for(d);
		f();
	}).detach();
}


void pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void cls()
{
	pos(0, 0);
	for (int j = 0; j<100; j++)
		cout << string(100, ' ');
	pos(0, 0);
}