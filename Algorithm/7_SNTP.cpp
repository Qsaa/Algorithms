/*
7 SNTP
����������� �������	1 �������
����������� ������	64Mb
����	����������� ���� ��� input.txt
�����	����������� ����� ��� output.txt

��� ���� ����� ���������� ������������ ���������� �����, ��� ����� ���������� � �������� 
������� ������� SNTP(Simple Network Time Protocol).� ���������, ��������� �� ����� ������ 
�������� ����� � �������, ������ ��� ���������� �� ���� ��������� �� ��������� : ���� 
��������� � ������� �������� ����� �� ����������, ��� �������� ���� ������������.
�������� �������������� �������(����������, �������������� ������ �����) � 
�������(����������, ��������� ������ �����) �������� ��������� ������� :

1. ������ ���������� ������ �� ������ � ���������� ����� ����������� A(�� ����������� �������).
2. ������ �������� ������ � ������ ������� B(�� ������� ���������� �������) � 
���������� ������� ���������, ���������� ����� B.
3. ������ �������� ����� �� ���� ������ � ������ ������� C(�� ����������� �������) � 
���������� ���.������ ������, �� �������������, ��� ������� �������� ��� �������� 
��������� �� ������� ������� � �� ������� ������� ���������, ����� ���������� � 
���������� ���� ������ �����, ��������� ��������� �������� A, B, C.

��� ��������� ����������� ��������, � ��������� �� ������� ������������ ������ ����� ��� 
��������� �� ������� �� ��������� A, B � C.��� ������������� ��������� ��������� �� ������ 
����� ������ �� �������� ����������(� ������� �������, ���� ������� ����� �����
	������ 1 / 2, ����� � ������� �������).

��������, ���, ���� ������ ������ ������, �� ����������� ������� ������ ��������� ����� 
�����, ������ ��������, ��� ����� ��������� �������� ������� � ���������� ������ �� 
������� ������ ����� 24 �����.


������ �����
��������� �������� �� ���� ��� ��������� ����� A, B, C, �� ����� � ������ ������.��� ��������� 
����� ������������ � ������� �hh : mm:ss�, ��� �hh� � ��� ����, �mm� � ������, �ss� � �������.
����, ������ � ������� ������������ ����� ����� ������� ������(��������, � ��������������� ������ � ������ �����).

������ ������
��������� ������ ������� ���� ��������� ����� � �������, ��������� �� ������� ������, � ����������� 
������ ����� ��� ��������� �� �������.� ������ �� ������ ���� ��������, ������ ����� � ������ ������.

������
����
15:01:00
18:09:45
15:01:40
�����
18:10:05

https ://contest.yandex.ru/contest/45469/problems/7/
*/


#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Time
{	
public:
	Time(const char (&str)[9])
	{
		hour_ = (str[0] - 48) * 10 + (str[1] - 48);
		min_ = (str[3] - 48) * 10 + (str[4] - 48);
		sec_ = (str[6] - 48) * 10 + (str[7] - 48);
	}
	Time(int hour, int min, int sec) :hour_(hour), min_(min), sec_(sec)
	{}

	void print()
	{
		string out = "00:00:00";
		out[0] = (hour_ / 10) + 48;
		out[1] = (hour_ % 10) + 48;

		out[3] = (min_ / 10) + 48;
		out[4] = (min_ % 10) + 48;

		out[6] = (sec_ / 10) + 48;
		out[7] = (sec_ % 10) + 48;
		cout << out << endl;
	}
	Time operator-(const Time& t) const
	{
		int p_min = 0;
		int p_hour = 0;

		int hour;
		int min;
		int sec;

		sec = sec_ - t.sec_;
		if (sec < 0)
		{
			sec += 60;
			p_min = 1;
		}

		min = min_ - (t.min_ + p_min);
		if (min < 0)
		{
			min += 60;
			p_hour = 1;
		}

		hour = hour_ - (t.hour_ + p_hour);
		if (hour < 0)
		{
			hour += 24;
		}
		return Time(hour, min, sec);
	}
	Time operator+(const Time& t) const
	{
		int p_min = 0;
		int p_hour = 0;

		int hour;
		int min;
		int sec;

		sec = sec_ + t.sec_;
		if (sec >= 60)
		{
			sec -= 60;
			p_min = 1;
		}

		min = min_ + (t.min_ + p_min);
		if (min >= 60)
		{
			min -= 60;
			p_hour = 1;
		}

		hour = hour_ + (t.hour_ + p_hour);
		if (hour >= 24)
		{
			hour -= 24;
		}
		return Time(hour, min, sec);
	}

	Time operator/ (float del) const
	{
		int sec = round((((hour_ * 60) + min_) * 60 + sec_) / del);
		int min = sec / 60;
		int hour = min / 60;

		sec %= 60;
		min %= 60;

		return Time(hour, min, sec);
	}


private:
	int hour_;
	int min_;
	int sec_;
};

Time SNTP(const Time& out, const Time& time, const Time& in)
{
	return Time(time + (in - out) / 2);
}

int test_SNTP()
{
	char str_out[9]; cin >> str_out;
	char str_time[9]; cin >> str_time;
	char str_in[9]; cin >> str_in;

	SNTP(Time(str_out), Time(str_time), Time(str_in)).print();
	return 0;
}