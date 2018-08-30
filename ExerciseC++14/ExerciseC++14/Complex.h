#pragma once

#include <iostream>
#include <memory>
#include "Trace.h"

class Complex
{
protected:

	int x = 1;
	int y = 1;
public:
	Complex(int x = 0, int y = 0) :x(x), y(y) { TRACE("Complex::Complex()"); }
	virtual ~Complex() { TRACE("Complex::~Complex()"); }
	Complex(const Complex& o) :x(o.x), y(o.y) { TRACE("Complex::Complex(const Complex& )"); }
	Complex& operator = (const Complex& o) { x = o.x, y = o.y;  TRACE("Complex& operator = (const Complex& o)"); }

	Complex(const Complex&& o) :x(o.x), y(o.y) { TRACE("Complex::Complex(const Complex&& )"); }
	Complex& operator = (const Complex&& o) { x = o.x, y = o.y;  TRACE("Complex& operator = (const Complex&& o)"); }


	virtual void Show() {
		TRACE("Complex::Show()"); LOG_VAR(this->x); LOG_VAR(this->y);
	}

	friend ostream& operator<<(ostream& out, const Complex& ptr)
	{
		cout << ptr.x << ":" << ptr.y;
		return out;
	}
	friend bool ComplexComp(const Complex& l, const Complex& r)
	{
		return ((l.x == r.x) && (l.y == r.y)) ? true : false;
	}
	friend bool ComplexComp(const unique_ptr<Complex> &l, const unique_ptr<Complex> &r)
	{
		return ((l->x == r->x) && (l->y == r->y)) ? true : false;
	}
	friend bool operator < (const unique_ptr<Complex> &l, const unique_ptr<Complex> &r) // required for map less comparision operator.
	{
		return ((l->x < r->x) && (l->y < r->y)) ? true : false;
	}
};
//==========================================================================================
class ComplexD : public Complex
{
	//int x = 11;
	//int y = 11;
	//using Complex::x;		//compiling , but what is the use?
	//using Complex::y;
	
	int z = 11;
public:
	ComplexD(int x1 = 0, int y1 = 0, int z1 = 0) :Complex(x1,y1), z(z1)
	{ TRACE("ComplexD::ComplexD()"); }

	~ComplexD() { TRACE("ComplexD::~ComplexD()"); }
	
	ComplexD(const ComplexD& o) :Complex(o), z(o.z) 
	{ TRACE("ComplexD::ComplexD(const ComplexD& )"); }

	ComplexD& operator = (const ComplexD& o) 
	{ 
		Complex::operator=(o);
		x = o.x, y = o.y;  
		TRACE("ComplexD& operator = (const ComplexD& o)"); 
	}

	ComplexD(const ComplexD&& o) :Complex(o), z(o.z) { TRACE("ComplexD::ComplexD(const ComplexD&& )"); }
	ComplexD& operator = (const ComplexD&& o) 
	{ 
		Complex::operator=(o);
		x = o.x, y = o.y;  
		TRACE("ComplexD& operator = (const ComplexD&& o)"); 
	}


	void Show() {
		TRACE("ComplexD::Show()"); 
		Complex::Show();
		LOG_VAR(this->z);
	}

	friend ostream& operator<<(ostream& out, const ComplexD& ptr)
	{
		cout << ptr.x << ":" << ptr.y << ":" << ptr.z;
		return out;
	}
	friend bool ComplexComp(const ComplexD& l, const ComplexD& r)
	{
		return ((l.x == r.x) && (l.y == r.y) && (l.z == r.z)) ? true : false;
	}
	friend bool ComplexComp(const unique_ptr<ComplexD> &l, const unique_ptr<ComplexD> &r)
	{
		return ((l->x == r->x) && (l->y == r->y) && (l->z == r->z)) ? true : false;
	}
	friend bool operator < (const unique_ptr<ComplexD> &l, const unique_ptr<ComplexD> &r) // required for map less comparision operator.
	{
		return ((l->x < r->x) && (l->y < r->y) && (l->z < r->z)) ? true : false;
	}
};