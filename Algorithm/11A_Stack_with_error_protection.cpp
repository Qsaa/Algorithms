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

/* ������� ������ ����������� */
void consumer()
{
	std::cout << "[CONSUMER] thread started" << std::endl;
	int toConsume = 0;

	while (true)
	{
		std::unique_lock<std::mutex> lock(globalMutex);
		/* ���� �������� ����� ���������� ������ �������������,
		 * �� ����� ������ � ��������� �������� ������� � ����������
		 * ��������� */
		if (storage < STORAGE_MAX)
		{
			condition.wait(lock, [] {return storage >= STORAGE_MAX; }); // �������� _��������� �������_ � ����� �� ��������� �����
			toConsume = storage - STORAGE_MIN;
			std::cout << "[CONSUMER] storage is maximum, consuming "
				<< toConsume << std::endl;
		}
		/* "�����������" ����������� ������ �� �������� �����
		 * ���������� */
		storage -= toConsume;
		std::cout << "[CONSUMER] storage = " << storage << std::endl;
	}
}

/* ������� ������ ������������� */
void producer()
{
	std::cout << "[PRODUCER] thread started" << std::endl;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		std::unique_lock<std::mutex> lock(globalMutex);
		++storage;
		std::cout << "[PRODUCER] storage = " << storage << std::endl;
		/* ���� �������� ����� ���������� �������� ��� ���������
		 * ��������, ����� ����������� ������������ �� ���� */
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