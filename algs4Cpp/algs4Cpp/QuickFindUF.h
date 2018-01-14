#pragma once
#include<vector>
#include<string>
#include<stdexcept>
#include<iostream>

namespace algs4Cpp {
	class QuickFindUF {
	private:
		std::vector<size_t> id;
		size_t count;

	public:
		QuickFindUF(size_t N):count(N),id() {
			id.reserve(N);
			for (size_t i = 0; i != N; ++i) {
				id.push_back(i);
			}
		}

		size_t siteCount() {
			return count;
		}

		size_t find(size_t p) {
			validate(p);
			return id[p];
		}

		bool connected(size_t p, size_t q) {
			validate(p);
			validate(q);
			return id[p] == id[q];
		}

		void unionSite(size_t p, size_t q) {
			validate(p);
			validate(q);
			size_t pID = id[p];
			size_t qID = id[q];

			if (pID == qID) return;

			for (size_t i = 0; i != id.size(); ++i) {
				if (id[i] == pID) id[i] = qID;
				--count;
			}
		}

	private:
		void validate(size_t p) {
			std::vector<size_t>::size_type N = id.size();
			if (p >= N) {
				throw std::out_of_range("index" + std::to_string(p) + "is not between 0 and " + std::to_string(N - 1));
			}
		}

	public:
		static void mainTest(int argc, char *argv[]) {
			size_t n;
			std::cin >> n;
			QuickFindUF uf(n);
			size_t p, q;
			while (std::cin >> p >> q) {
				if (uf.connected(p, q)) continue;
				uf.unionSite(p, q);
				std::cout << p << " " << q << std::endl;
			}
			std::cout << uf.siteCount() << " components";
		}
	};
}
