#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

template <typename Dauer, typename Func>
void timer(Dauer const & d, Func const & f)
{
	std::thread([d, f]() {
		std::this_thread::sleep_for(d);
		f();
	}).detach();
}