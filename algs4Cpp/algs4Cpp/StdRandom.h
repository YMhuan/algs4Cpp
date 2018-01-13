#pragma once
#include<random>
#include<ctime>
#include<stdexcept>
#include<limits>
#include<cmath>

namespace algs4Cpp {

	class StdRandom final{
	public:
		StdRandom(const StdRandom &) = delete;
		StdRandom &operator=(const StdRandom &) = delete;
		~StdRandom() = delete;

	private:
		static time_t seed;
		static std::default_random_engine random;
		static int upperbound;
		static std::uniform_int_distribution<int> iu;
		static std::uniform_real_distribution<double> du;

		static int minus(int l, int r) {
			if ((l < 0 && r>0 && l < std::numeric_limits<int>::min()) || (l >= 0 && r < 0 && std::numeric_limits<int>::max() + r < l)) {
				throw std::invalid_argument("Range overflow");
			}
			return l - r;
		}

	public:
		static int uniform(int n) {
			if(n<=0) throw std::invalid_argument("Parameter N must be positive");
			if (n != upperbound)  {
				upperbound = n;
				iu= std::uniform_int_distribution<int>(0,upperbound);
			}
			return iu(random);
		}

		static double uniform() {
			return du(random);
		}

		static int uniform(int a, int b) {
			if(b<=a) throw std::invalid_argument("Invalid range");
			return a+uniform(minus(b,a));
		}

		static double uniform(double a, double b) {
			if(b<=a) throw std::invalid_argument("Invalid range");
			return a + uniform()*(b - a);
		}

		static bool bernoulli(double p) {
			if (!(p >= 0.0 && p <= 1.0)) {
				throw std::invalid_argument("Probability must be between 0.0 and 1.0");
			}
			return uniform() < p;
		}

		static bool bernoulli() {
			return bernoulli(0.5);
		}

		static double gaussian() {
			double r, x, y;
			do {
				x = uniform(-1.0, 1.0);
				y = uniform(-1.0, 1.0);
			} while (r >= 1 || r == 0);
			return x*std::sqrt(-2 * std::log(r));
		}

		static double gaussian(double mu, double sigma) {
			return mu + sigma*gaussian();
		}

		static int geometric(double p) {
			if (!(p >= 0.0 && p <= 1.0)) {
				throw std::invalid_argument("Probability must be between 0.0 and 1.0");
			}
			return static_cast<int>(std::ceil(std::log(uniform()) / std::log(1.0 - p)));
		}

		static int poisson(double lambda) {
			if (!(lambda > 0.0)) {
				throw std::invalid_argument("Parameter lambda must be positive");
			}
			if (std::isinf(lambda)) {
				throw std::invalid_argument("Parameter lambda must not be infinite");
			}
			int k = 0;
			double p = 1.0;
			double L = std::exp(-lambda);
			do {
				++k;
				p *= uniform();
			} while (p >= L);
			return k - 1;
		}

		static double pareto() {
			return pareto(1.0);
		}

		static double pareto(double alpha) {
			if(!(alpha>0.0)) throw std::invalid_argument("Shape parameter alpha must be positive");
			return std::pow(1 - uniform(),- 1.0 / alpha) - 1.0;
		}

		static double cauchy() {
			return std::tan(std::_Pi*(uniform() - 0.5));
		}



	};

	time_t StdRandom::seed = std::time(nullptr);
	std::default_random_engine StdRandom::random(seed);
	int StdRandom::upperbound =1;
	std::uniform_int_distribution<int> StdRandom::iu(0, upperbound);
	std::uniform_real_distribution<double> StdRandom::du(0,1);

}