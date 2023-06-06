#include <iostream>

#include <cstdlib>
#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#define STORAGE_MIN 10
#define STORAGE_MAX 20

int storage = STORAGE_MIN;

std::mutex globalMutex;
std::condition_variable condition;

/* Функция потока потребителя */
void consumer()
{
	std::cout << "[CONSUMER] thread started" << std::endl;
	int toConsume = 0;

	while (true)
	{
		std::unique_lock<std::mutex> lock(globalMutex);
		/* Если значение общей переменной меньше максимального,
		 * то поток входит в состояние ожидания сигнала о достижении
		 * максимума */
		if (storage < STORAGE_MAX)
		{
			condition.wait(lock, [] {return storage >= STORAGE_MAX; }); // Атомарно _отпускает мьютекс_ и сразу же блокирует поток
			toConsume = storage - STORAGE_MIN;
			std::cout << "[CONSUMER] storage is maximum, consuming "
				<< toConsume << std::endl;
		}
		/* "Потребление" допустимого объема из значения общей
		 * переменной */
		storage -= toConsume;
		std::cout << "[CONSUMER] storage = " << storage << std::endl;
	}
}

/* Функция потока производителя */
void producer()
{
	std::cout << "[PRODUCER] thread started" << std::endl;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		std::unique_lock<std::mutex> lock(globalMutex);
		++storage;
		std::cout << "[PRODUCER] storage = " << storage << std::endl;
		/* Если значение общей переменной достигло или превысило
		 * максимум, поток потребитель уведомляется об этом */
		if (storage >= STORAGE_MAX)
		{
			std::cout << "[PRODUCER] storage maximum" << std::endl;
			condition.notify_one();
		}
	}
}

int stack_with_error_protection()
{
	std::thread thProducer(producer);
	std::thread thConsumer(consumer);

	thProducer.join();
	thConsumer.join();

	return 0;
}

/*
int stack_with_error_protection()
{
	if (auto a = 1; a)
	{
		std::cout << "SA" << std::endl;
	}
	std::cout << "SA" << std::endl;
	return 0;
}//*/


int test_stack_with_error_protection()
{
	return stack_with_error_protection();
}