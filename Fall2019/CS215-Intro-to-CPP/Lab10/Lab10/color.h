#pragma once
class color {
public:
	color();

	// Accessors
	int getRed();
	int getBlue();
	int getGreen();

	// Mutators
	void set(int r, int g, int b);

	// Representation
	void print();

	// Operators Friends
	friend color operator + (color a, color b);
	friend color operator - (color a, color b);
private:
	int red;
	int green;
	int blue;
};

// Overloaded Operators
color operator + (color a, color b);
color operator - (color a, color b);
color operator * (int b, color a);
color operator / (color a, int b);