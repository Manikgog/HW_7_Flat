#ifndef _GETSQUARE_H_
#define _GETSQUARE_H_


class GetSquare
{
protected:
	double square_;
public:
	GetSquare(double square) : square_(square) {}
	virtual double Square() = 0;
};

class GetSquareInMetres : public GetSquare
{
public:
	GetSquareInMetres(double square) : GetSquare(square) {}
	double Square() override {
		return square_;
	}
};

class GetSquareInFeet : public GetSquare
{
public:
	GetSquareInFeet(double square) : GetSquare(square) {}
	double Square() override {
		return square_ * 10.76;
	}
};





#endif // !_GETSQUARE_H_

