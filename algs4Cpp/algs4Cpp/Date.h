#pragma once
#include<array>
#include<stdexcept>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<cassert>

namespace algs4Cpp {
	class Date {
		friend bool operator<(const Date &, const Date &);
		friend bool operator>(const Date &, const Date &);
		friend bool operator==(const Date &, const Date &);
		friend bool operator<=(const Date &, const Date &);
		friend bool operator>=(const Date &, const Date &);
		friend int compare(const Date &, const Date &);

	public:
		Date(const Date &) = default;
		Date &operator=(const Date &) = default;
		~Date() = default;

		Date(size_t _month, size_t _day, size_t _year): month_(_month),day_(_day),year_(_year){
			if (!isValid(month_, day_, year_)) throw std::invalid_argument("invalid date");
		}

		Date(const std::string &date) {
			std::vector<std::string> fields = split(date, '/');
			if (fields.size() != 3) {
				throw std::invalid_argument("Invalid date");
			}
		    month_ = std::stoi(fields[0]);
			day_ = std::stoi(fields[1]);
			year_ = std::stoi(fields[2]);
			if (!isValid(month_, day_, year_)) throw std::invalid_argument("invalid date");
		}

	private:
		static constexpr std::array<size_t, 13> DAYS = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
		size_t month_=0;
		size_t day_=0;
		size_t year_=0;

		static std::vector<std::string> split(const std::string &s, char delim) {
			std::vector<std::string> elems;
			std::string item;
			std::istringstream ss(s);
			while (std::getline(ss, item, delim)) {
				elems.push_back(item);
			}
			return elems;
		}

		static bool isValid(size_t m, size_t d, size_t y) {
			if (m < 1 || m > 12)      return false;
			if (d < 1 || d > DAYS[m]) return false;
			if (m == 2 && d == 29 && !isLeapYear(y)) return false;
			return true;
		}

		static bool isLeapYear(size_t y) {
			if (y % 400 == 0) return true;
			if (y % 100 == 0) return false;
			return y % 4 == 0;
		}

	public:
		size_t month() const {
			return month_;
		}

		size_t day() const {
			return day_;
		}

		size_t year() const {
			return year_;
		}

		Date next() const {
			if (isValid(month_, day_ + 1, year_)) return Date(month_, day_ + 1, year_);
			else if (isValid(month_ + 1, 1, year_)) return  Date(month_ + 1, 1, year_);
			else return Date(1, 1, year_ + 1);
		}

		std::string toString() const {
			return std::to_string(month_) + "/" + std::to_string(day_) + "/" + std::to_string(year_);
		}

		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			Date today(1, 18, 2018);
			std::cout << today.toString() << std::endl;
			for (size_t i = 0; i < 20; ++i) {
				today = today.next();
				std::cout << today.toString() << std::endl;
			}

			assert(!(today > today.next()));
			assert(!(today > today));
			assert(today.next() > today);
		}

	};
	bool operator<(const Date &, const Date &);
	bool operator>(const Date &, const Date &);
	bool operator==(const Date &, const Date &);
	bool operator<=(const Date &, const Date &);
	bool operator>=(const Date &, const Date &);
	int compare(const Date &, const Date &);
}