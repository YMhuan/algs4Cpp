#pragma once
#include"StdRandom.h"
#include<string>
#include<vector>
#include<iostream>

namespace algs4Cpp {
	class Counter {
	public:
		Counter(const Counter &) = default;
		Counter &operator=(const Counter &) = default;
		Counter(Counter &&) noexcept  = default;
		Counter &operator=(Counter &&) noexcept = default;
		Counter(std::string id):name(id) {};
		~Counter() = default;

	private:
		const std::string name;
		size_t count = 0;

	public:
		void increment() {
			++count;
		}

		size_t tally() {
			return count;
		}

		std::string toString() {
			return std::to_string(count) + " " + name;
		}

		int compareTo(const Counter &that) {
			if (count < that.count) return -1;
			else if (count > that.count) return +1;
			else return 0;
		}

		static void mainTest(int argc = 0, char* argv[] = nullptr) {
			constexpr size_t n = 6;
			constexpr size_t trials = 600000;

			std::vector<Counter> hits;
			for (size_t i = 0; i < n; ++i) {
				hits.push_back(Counter("counter" + std::to_string(i)));
			}

			for (size_t t = 0; t < trials; ++t) {
				hits[StdRandom::uniform(n)].increment();
			}

			for (size_t i = 0; i < n; ++i) {
				std::cout << hits[i].toString() << std::endl;
			}
		}
	};
}