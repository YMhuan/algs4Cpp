#pragma once
#include<vector>
#include<initializer_list>
#include<stdexcept>
#include<cmath>
#include<iostream>

namespace algs4Cpp {
	class Vector {
	private:
		size_t d;
		std::vector<double> data;

	public:
		Vector(int D):d(D),data(std::vector<double>(d)) {

		}

		Vector(std::initializer_list<double> a):d(a.size()) {
			data.reserve(d);
			for (double x : a) {
				data.push_back(x);
			}
		}

		size_t length() const {
			return d;
		}

		size_t dimension() const {
			return d;
		}

		double dot(const Vector &that) const {
			check(that);
			double sum = 0.0;
			for (size_t i = 0; i != d;++i) {
				sum += (data[i] * that.data[i]);
			}
			return sum;
		}

		double magnitude() const {
			return std::sqrt(dot(*this));
		}

		double distanceTo(const Vector &that) const {
			return (*this-that).magnitude();
		}

		Vector operator+(const Vector &that) const {
			check(that);
			Vector c(d);
			for (size_t i = 0; i != d; ++i) {
				c.data[i] = data[i] + that.data[i];
			}
			return c;
		}

		Vector operator-(const Vector &that) const {
			check(that);
			Vector c(d);
			for (size_t i = 0; i != d; ++i) {
				c.data[i] = data[i] - that.data[i];
			}
			return c;
		}

		bool operator==(const Vector &that) const {
			if (dimension() != that.dimension()) return false;
			for (size_t i = 0; i != d; ++i) {
				if (data[i] != that.data[i]) return false;
			}
			return true;
		}

		bool operator!=(const Vector &that) const {
			return !(*this == that);
		}

		double cartesian(size_t i) const {
			return data[i];
		}

		Vector times(double alpha) {
			return scale(alpha);
		}

		Vector scale(double alpha) const {
			Vector c(d);
			for (size_t i = 0; i != d; ++i) {
				c.data[i] = alpha*data[i];
			}
			return c;
		}

		Vector direction() const {
			if (magnitude() == 0.0) throw std::overflow_error("Zero-vector has no direction");
			return scale(1.0 / magnitude());
		}

	private:
		void check(const Vector &that) const {
			if (d != that.d) throw std::invalid_argument("Dimensions don't agree");
		}

	};
}