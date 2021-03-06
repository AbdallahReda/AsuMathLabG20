#pragma once
#include <iostream>	// istream, ostream
#include "string"

namespace asu {

class CMatrix {
private:
	size_t nRows, nColumns;
	double* values; // 1d are faster and simpler than 2d
public:
	CMatrix();
	~CMatrix();
	enum MI { MI_ZEROS, MI_ONES, MI_EYE, MI_RAND, MI_VALUE };
	CMatrix(size_t nRows, size_t nColumns,
	        int initialization = MI_ZEROS,
	        double initializationValue = 0.0);
	CMatrix(size_t nRows, size_t nColumns, double first, ...);
	CMatrix(const CMatrix& m);
	CMatrix(double d);
	CMatrix(const char* s);
	void CopyMatrix(std::string s);
	void CopyMatrix(const CMatrix& m);
	void CopyMatrix(double d);
	void CopyMatrix(const char* s);
	void reset();
	CMatrix operator=(const CMatrix& m);
	CMatrix operator=(double d);
	CMatrix operator=(const char* s);
	void setSubMatrix(size_t iR, size_t iC, const CMatrix& m);
	CMatrix getSubMatrix(size_t r, size_t c, size_t nr, size_t nc) const;
	CMatrix getCofactor(size_t r, size_t c) const;
	void addColumn(const CMatrix& m);
	void addRow(const CMatrix& m);
	double get(size_t i) const;
	double& get(size_t i);
	double get(size_t i, size_t j) const;
	double& get(size_t i, size_t j);
	double& operator[](size_t i);
	double operator[](size_t i) const;
	double operator()(size_t i) const;
	double& operator()(size_t i);
	double operator()(size_t r, size_t c) const;
	double& operator()(size_t r, size_t c);
	size_t getn() const;
	size_t getnRows() const;
	size_t getnColumns() const;
	double getDeterminant() const;
	CMatrix getTranspose() const;
	CMatrix getInverse() const;
    void sweep(size_t a,size_t b);
    void swaprow(size_t a,size_t b);
    void fix(size_t a,size_t b,double &flag);
};

#define fn(name) \
CMatrix name(const CMatrix& a, const CMatrix& b); \
CMatrix name(const CMatrix& a, double b);         \
CMatrix name(double a,         const CMatrix& b); \
CMatrix name(double a,         double b);
fn(add);
fn(sub);
fn(mul);
fn(div);
fn(amul);
fn(adiv);
#undef fn

bool operator==(const CMatrix& a, const CMatrix& b);
bool operator!=(const CMatrix& a, const CMatrix& b);
std::istream& operator>>(std::istream& is, CMatrix& C);
std::ostream& operator<<(std::ostream& os, const CMatrix& C);

}; // namespace asu

