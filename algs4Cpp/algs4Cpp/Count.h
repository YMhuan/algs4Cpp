#pragma once
#include<fstream>
#include<set>
#include<map>
#include<iostream>

namespace algs4Cpp {
	class Count {
	public:
		Count(const Count &) = delete;
		Count &operator=(const Count &) = delete;
		~Count() = delete;

		static void mainTest(int argc = 0, char* argv[] = nullptr) {
			std::ifstream in("pi.txt");
			std::ifstream whitelist("input.txt");
			char c;
			std::set<char> alphabet;
			while (whitelist >> c) {
				alphabet.insert(c);
			}
			
			std::map<char, size_t> count;
			while (in >> c) {
				if (alphabet.find(c) != alphabet.end()) {
					++count[c];
				}
			}
			for (auto it = count.cbegin(); it != count.cend(); ++it) {
				std::cout << it->first << " " << it->second << std::endl;
			}
			
		}

	};
}