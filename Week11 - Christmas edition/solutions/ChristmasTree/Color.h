#pragma once
class Color
{
private:
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	Color();
	Color(unsigned char _r, unsigned char _g, unsigned char _b);
	Color(const Color& other);
	unsigned char getR() const;
	unsigned char getG() const;
	unsigned char getB() const;
};

