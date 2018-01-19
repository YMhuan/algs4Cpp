#pragma once
#include <Windows.h>
#include<cmath>
#include<iostream>

namespace algs4Cpp {
	class StopwatchWin32 {
	private:
		long long PerformanceCounter() {
			LARGE_INTEGER li;
			::QueryPerformanceCounter(&li);
			return li.QuadPart;
		}
		const long long start= PerformanceCounter();

		static long long PerformanceFrequency() {
			LARGE_INTEGER li;
			::QueryPerformanceFrequency(&li);
			return li.QuadPart;
		}
		static const long long tickFrequency;




	public:
		StopwatchWin32() = default;
		StopwatchWin32(const StopwatchWin32 &) = default;
		StopwatchWin32 &operator=(const StopwatchWin32 &) = delete;
		~StopwatchWin32() = default;

		double elapsedTime() {
			long long finish = PerformanceCounter();
			double elapsedSeconds = static_cast<double>(finish - start) / tickFrequency;
			return elapsedSeconds;
		}

		static void mainTest(int argc = 0, char* argv[] = nullptr) {
			const int n = 100;

			StopwatchWin32 timer1;
			double sum1 = 0.0;
			for (size_t i = 1; i <= n; ++i) {
				sum1 += std::sqrt(i);
			}
			double time1 = timer1.elapsedTime();
			std::cout << time1 << " " << "seconds" << std::endl;

			StopwatchWin32 timer2;
			double sum2 = 0.0;
			for (size_t i = 1; i <= n; ++i) {
				sum2 += std::pow(i, 0.5);
			}
			double time2 = timer2.elapsedTime();
			std::cout << time2 << " " << "seconds" << std::endl;
		}
	};
}