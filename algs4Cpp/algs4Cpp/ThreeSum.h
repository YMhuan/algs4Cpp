#pragma once
#include"Stopwatch.h"
#include<vector>
#include<iostream>
#include<fstream>

namespace algs4Cpp {
	class ThreeSum {
	public:
		ThreeSum(const ThreeSum &) = delete;
		ThreeSum &operator=(const ThreeSum &) = delete;
		~ThreeSum() = delete;

		static void printAll(const std::vector<int> &a) {
			size_t n = a.size();
			for (size_t i = 0; i < n; ++i) {
				for (size_t j = i + 1; j < n; ++j) {
					for (size_t k = j + 1; k < n; ++k) {
						if (a[i] + a[j] + a[k] == 0) {
							std::cout << a[i] << " " << a[j] << " " << a[k] << std::endl;
						}
					}
				}
			}
		}

		static size_t count(const std::vector<int> &a) {
			size_t n = a.size();
			size_t total = 0;
			for (size_t i = 0; i < n; ++i) {
				for (size_t j = i + 1; j < n; ++j) {
					for (size_t k = j + 1; k < n; ++k) {
						if (a[i] + a[j] + a[k] == 0) {
							++total;
						}
					}
				}
			}
			return total;
		}

		static void mainTest(int argc = 0, char* argv[] = nullptr) {
			std::ifstream in("1Kints.txt");
			std::vector<int> a;
			int x;
			while (in >> x) {
				a.push_back(x);
			}
			Stopwatch timer;
			size_t cnt = count(a);
			std::cout << "elapsed time = " << timer.elapsedTime() << std::endl;
			std::cout << cnt << std::endl;
		}
	};
}