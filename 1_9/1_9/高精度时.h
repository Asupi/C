#pragma once

#include <windows.h>

class �߾��ȼ�ʱ
{
public:
	�߾��ȼ�ʱ(void)
	{
		QueryPerformanceFrequency(&CPUƵ��);
	}

	~�߾��ȼ�ʱ(void) {}

	void ��ʼ()
	{
		QueryPerformanceCounter(&��ʼʱ��);
	}

	void ����()
	{
		QueryPerformanceCounter(&����ʱ��);

		��� = ((double)����ʱ��.QuadPart - (double)��ʼʱ��.QuadPart) / (double)CPUƵ��.QuadPart;
	}

	double �������() const
	{
		return ��� * 1000;
	}

private:
	double ���;

	LARGE_INTEGER ��ʼʱ��;

	LARGE_INTEGER ����ʱ��;

	LARGE_INTEGER CPUƵ��;
};
