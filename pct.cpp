#pragma once

#include <vector>
#include <algorithm>

#include "stats.hpp"
#include "istatistics.hpp"

void Pct::update(double next) {
	m_data.push_back(next);
	if (m_data.size() > 1){
		std::sort(m_data.begin(), m_data.end());
		int t_value {m_value * static_cast<int>(m_data.size())};
			
		if(t_value%100) {
			t_value = t_value/100+1;
		}
		else t_value /=100;

		while((m_data[t_value-1] == m_data[t_value-2]) && (t_value < m_data.size())){
			++t_value;
		}

		m_pct = m_data[t_value-1];
	}
	else return;
}