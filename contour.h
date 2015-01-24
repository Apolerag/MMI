#ifndef CONTOUR_H
#define CONTOUR_H

#include <complex>
#include <vector>

class Contour 
{
private:
	std::vector< std::complex<double> > m_data;

public:
	Contour();
	Contour(const std::vector< std::complex<double> > & tabComplexe);
	~Contour();


	int getDataSize() const;
	std::complex<double> operator()(const int i) const;
};

#endif

