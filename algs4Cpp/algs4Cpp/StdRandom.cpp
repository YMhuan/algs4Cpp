#include"StdRandom.h"
using namespace algs4Cpp;

time_t StdRandom::seed = std::time(nullptr);
std::default_random_engine StdRandom::random(static_cast<unsigned int>(seed));
int StdRandom::upperbound = 1;
std::uniform_int_distribution<int> StdRandom::iu(0, upperbound);
std::uniform_real_distribution<double> StdRandom::du(0, 1);
