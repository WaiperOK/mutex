#pragma once
#include <chrono>
#include <iostream>
using namespace std;
class SimpleTimer
{
public:
	SimpleTimer();

	~SimpleTimer();

private:

	chrono::time_point<std::chrono::steady_clock> start, end;
	chrono::duration<float> duration;

}; 



using namespace std;

SimpleTimer::SimpleTimer()
{
	start = chrono::high_resolution_clock::now(); // Возвращает момент времени, представляющий текущий момент времени.
}

SimpleTimer::~SimpleTimer()
{
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	float result = duration.count();
	cout << " Прошло времени " << result << " секунд " << std::endl;
} 


// сам код ↓

 #include <iostream>
#include <thread> // библиотека для многопоточности
#include <chrono>
#include <mutex>
using namespace std;

mutex mtx;

void Print(char ch)
{
	mtx.lock(); // Метод закрытого доступа
	for (int i = 0; i < 5; ++i)
	{
		for ( int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::microseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	mtx.unlock(); // Метод открыт
}



int main()
{
	setlocale(LC_ALL, "rus");

	SimpleTimer Timer; // Таймер для программы.

	thread t1(Print, '*');
	thread t2(Print, '#');

	Print('*');
	Print('#');

	t1.join();
	t2.join();

	return 0;
}




