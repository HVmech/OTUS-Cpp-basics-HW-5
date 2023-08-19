#pragma once

#include <limits>
#include <vector>
#include <string>
#include <algorithm>

#include "istatistics.hpp"

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	std::string name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::lowest()} {}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	std::string name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() : m_mean{0}, m_count{0} {
	}

	void update(double next) override {
		m_mean += next;
		++m_count;
	}

	double eval() const override {
		return m_mean/static_cast<double>(m_count);
	}

	std::string name() const override {
		return "mean";
	}

private:
	int m_count;
	double m_mean;
};

class Std : public IStatistics {
public:
	Std() : m_std{0}, m_count{0}, m_mean{0} {}

	void update(double next) override {
		m_mean += next;
		m_std += pow(next, 2);
		++m_count;
	}

	double eval() const override {
		return
			sqrt(-pow(m_mean/(static_cast<double>(m_count)), 2)
			+m_std/(static_cast<double>(m_count)));
	}

	std::string name() const override {
		return "std";
	}

private:
	int m_count;
	double m_mean;
	double m_std;
};

class Pct : public IStatistics {
public:
	Pct(int value) : m_value{value}, m_pct{0} {}

	void update(double next) override;

	double eval() const override {
		return m_pct;
	}

	std::string name() const override {
		return "pct" + std::to_string(m_value);
	}

private:
	std::vector <double> m_data = {};
	int m_value;
	double m_pct;
};
