#pragma once
#include<random>
#include<ctime>
#include<stdexcept>
#include<limits>
#include<cmath>
#include<vector>
#include<string>
#include<cassert>
#include<iostream>

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

		static int plus(int l, int r) {
			if ((l > 0 && std::numeric_limits<int>::max() - l < r) || l<0 && std::numeric_limits<int>::min() - l>r) {
				throw std::invalid_argument("Range overflow");
			}
			return l + r;
		}

	public:
		static int uniform(int n) {
			if(n<=0) throw std::invalid_argument("Parameter N must be positive");
			if (n != upperbound)  {
				upperbound = n;
				iu= std::uniform_int_distribution<int>(0,upperbound-1);
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

		static int discrete(const std::vector<double> &probabilities) {
			double EPSILON = 1E-14;
			double sum = 0.0;
			for (std::vector<double>::size_type i = 0; i < probabilities.size(); ++i) {
				if(!(probabilities[i]>=0.0))
					throw std::invalid_argument("array entry"+std::to_string(i)+"must be nonnegative: "+std::to_string(probabilities[i]));
				sum += probabilities[i];
			}
			if(sum>1.0+EPSILON || sum<1.0-EPSILON)
				throw std::invalid_argument("sum of array entries does not approximately equal 1.0: " + std::to_string(sum));

			while (true) {
				double r = uniform();
				sum = 0.0;
				for (std::vector<double>::size_type i = 0; i < probabilities.size(); ++i) {
					sum += probabilities[i];
					if (sum > r) return i;
				}
			}
		}

		static int discrete(const std::vector<int> &frequencies) {
			int sum = 0;
			for (std::vector<int>::size_type i = 0; i < frequencies.size(); ++i) {
				if(frequencies[i]<0)
					throw std::invalid_argument("array entry" + std::to_string(i) + "must be nonnegative: " + std::to_string(frequencies[i]));
				sum = plus(sum, frequencies[i]);
			}
			if(sum==0)
				throw std::invalid_argument("at least one array entry must be positive");

			double r = uniform(sum);
			sum = 0;
			for (std::vector<int>::size_type i = 0; i < frequencies.size(); ++i) {
				sum += frequencies[i];
				if (sum > r) return i;
			}

			assert(false);
			return -1;
		}

		static double exp(double lambda) {
			if (!(lambda > 0.0))
				throw std::invalid_argument("Rate lambda must be positive");
			return -std::log(1 - uniform()) / lambda;
		}

		template<typename Item> 
		static void shuffle(std::vector<Item> &a) {
			std::vector<Item>::size_type n = a.size();
			for (std::vector<Item>::size_type i = 0; i < n; ++i) {
				int r = i + uniform(n - i);
				Item temp= a[i];
				a[i] = a[r];
				a[r] = temp;
			}
		}

		template<typename Item>
		static void shuffle(std::vector<Item> &a, int lo, int hi) {
			if (lo<0 || lo>hi || hi >= a.size()) {
				throw std::invalid_argument("Illegal subarray range");
			}
			for (int i = lo; i <= hi; ++i) {
				int r = i + uniform(hi - i + 1);
				Item temp = a[i];
				a[i] = a[r];
				a[r] = temp;
			}
		}


		static void setSeed(time_t s) {
			seed = s;
			random.seed(static_cast<unsigned int>(seed));
		}

		static time_t getSeed() {
			return seed;
		}

		public:

			static void mainTest(int argc = 0, char *argv[] = nullptr) {
				std::vector<double> probabilities{ 0.5,0.3,0.1,0.1 };
				std::vector<int> frequencies{ 5,3,1,1 };
				std::vector<std::string> a{ "A","B","C","D","E","F","G" };

				std::cout << "seed = " << getSeed() << std::endl;

				for (int i = 0; i < 5; ++i) {
					std::cout << uniform(100) << " "
						<< uniform(10.0, 99.0) << " "
						<< bernoulli(0.5) << " "
						<< discrete(probabilities) << " "
						<< discrete(frequencies) << " ";
					shuffle(a);
					for (const auto &s : a) {
						std::cout << s;
					}
					std::cout << std::endl;
				}


			}

	};

}