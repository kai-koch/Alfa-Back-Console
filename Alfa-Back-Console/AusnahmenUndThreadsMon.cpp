#include "stdafx.h"
#include "AusnahmenUndThreadsMon.h"
#include <iostream>
#include <string>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <cstddef>
#include <functional>  // ref()
#include <vector>
using namespace std;
#include "ParameterListe.h"

bool AusnahmenUndThreadsMon::SetAusnahmenMonitorTrueFalse(bool)
{
	return false;
}

bool AusnahmenUndThreadsMon::StartAusnahmenMonitor()
{
	std::queue<int> ErstellteExceptionMatrix;
	std::mutex Exception_mutex;
	std::condition_variable cond_Exception;
	bool gemacht = false;
	bool informiert = false;
	bool ZusammenfassungState = true;

	std::thread ExceptionsAusloeser([&]() {

		while (AusnahmenMonitorStatus = true)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));

			//if Test Matrix Condition
			ParameterListe PL;
			ZusammenfassungState = PL.ZusammenfassungFunc();
			if (ZusammenfassungState == false)
			{ 
			std::unique_lock<std::mutex> lock(Exception_mutex);
			std::cout << "Ausnahme ausgeloest" << ZusammenfassungState << endl;
			ErstellteExceptionMatrix.push(ZusammenfassungState);
			informiert = true;
			cond_Exception.notify_one();
			}
			//if Test Matrix Condition
		}

		gemacht = true;
		informiert = true;
		cond_Exception.notify_one();
	});

	std::thread ExceptionsMonitor([&]() {
		std::unique_lock<std::mutex> lock(Exception_mutex);
		while (!gemacht) {
			while (!informiert) {  // Schleife, um st�rendes Aufwecken zu vermeiden
				cond_Exception.wait(lock);
			}
			while (!ErstellteExceptionMatrix.empty()) {
				std::cout << "Ausnahme wurde verwaltet" << ErstellteExceptionMatrix.front() << endl;
				ErstellteExceptionMatrix.pop();
			}
			informiert = false;
		}
	});

	ExceptionsAusloeser.join();
	ExceptionsMonitor.join();
	return true;
}


AusnahmenUndThreadsMon::AusnahmenUndThreadsMon()
{
}


AusnahmenUndThreadsMon::~AusnahmenUndThreadsMon()
{
}
