#pragma once
#include"StdRandom.h"
#include"Stopwatch.h"
#include"ThreeSum.h"
#include<vector>
#include<iostream>

namespace algs4Cpp {
	class DoublingRatio {
	public:
		DoublingRatio(const DoublingRatio &) = delete;
		DoublingRatio &operator=(const DoublingRatio &) = delete;
		~DoublingRatio() = delete;

	private:
		static constexpr int MAXIMUM_INTEGER = 1000000;

	public:
		static double timeTrial(size_t n) {
			std::vector<int> a;
			a.reserve(n);
			for (size_t i = 0; i < n; ++i) {
				a.push_back(StdRandom::uniform(-MAXIMUM_INTEGER, +MAXIMUM_INTEGER));
			}
			Stopwatch timer;
			ThreeSum::count(a);
			return timer.elapsedTime();
		}

		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			double prev = timeTrial(125);
			for (size_t n = 250; true; n += n) {
				double time = timeTrial(n);
				std::cout << n << " " << time << " " << time / prev << std::endl;
				prev = time;
			}
		}
	};
}