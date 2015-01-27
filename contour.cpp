/**
 * @file contour.cpp
 * @authors Aurélien CHEMIER, Romane LHOMME
 * @date janvier 2015
 */
#include "contour.h"

#include <assert.h>

Contour::Contour()
{}

Contour::Contour(const std::vector< std::complex<double> > & tabComplexe)
{
	m_data = tabComplexe;
}

Contour::~Contour()
{
	std::vector< std::complex<double> >().swap(m_data);
}

int Contour::getDataSize() const {
	return m_data.size();
}

std::vector<std::complex<double> > Contour::getData() const {
	return m_data;
}

std::complex<double> Contour::operator()(const int i) const {
	
	assert(i >= 0 && i < m_data.size());
		return m_data[i];
}
