#pragma once

#include <windows.h>

class 高精度计时
{
public:
	高精度计时(void)
	{
		QueryPerformanceFrequency(&CPU频率);
	}

	~高精度计时(void) {}

	void 开始()
	{
		QueryPerformanceCounter(&开始时间);
	}

	void 结束()
	{
		QueryPerformanceCounter(&结束时间);

		间隔 = ((double)结束时间.QuadPart - (double)开始时间.QuadPart) / (double)CPU频率.QuadPart;
	}

	double 间隔毫秒() const
	{
		return 间隔 * 1000;
	}

private:
	double 间隔;

	LARGE_INTEGER 开始时间;

	LARGE_INTEGER 结束时间;

	LARGE_INTEGER CPU频率;
};
