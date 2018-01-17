#pragma once
#include"Stopwatch.h"
#include<vector>
#include<algorithm>
#include<stdexcept>
#include<iostream>
#include<fstream>

namespace algs4Cpp {
	class ThreeSumFast {
	public:
		ThreeSumFast(const ThreeSumFast &) = delete;
		ThreeSumFast &operator=(const ThreeSumFast &) = delete;
		~ThreeSumFast() = delete;

	private:
		static bool containDuplicates(const std::vector<int> &a) {
			for (size_t i = 1; i < a.size(); ++i) {
				if (a[i] == a[i - 1]) return true;
			}
			return false;
		}

		template<typename Iter,typename T> 
		static Iter binary_find(Iter beg, Iter end, const T &val) {
			Iter it = std::lower_bound(beg, end, val);
			if (it != end && !(val < *it))
				return it;
			else
				return end;
		}

	public:
		static void printAll(std::vector<int> &a) {
			std::sort(a.begin(), a.end());
			if (containDuplicates(a)) throw std::invalid_argument("array contains duplicate integers");
			for (auto it = a.cbegin(); it != a.cend();++it) {
				for (auto it2 = it + 1; it2 != a.cend();++it2) {
					auto it3 = binary_find(a.cbegin(), a.cend(), -(*it + *it2));
					if ((it3!=a.cend()) && (it2<it3)) std::cout << *it << " " << *it2 << " " << *it3 << std::endl;
				}
			}
		}

		static size_t count(std::vector<int> &a) {
			std::sort(a.begin(), a.end());
			if (containDuplicates(a)) throw std::invalid_argument("array contains duplicate integers");
			size_t cnt = 0;
			for (auto it = a.cbegin(); it != a.cend(); ++it) {
				for (auto it2 = it + 1; it2 != a.cend(); ++it2) {
					auto it3 = binary_find(a.cbegin(), a.cend(), -(*it + *it2));
					if ((it3 != a.cend()) && (it2<it3)) ++cnt;
				}
			}
			return cnt;
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