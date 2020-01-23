#include "color.h"
#include <iostream>
#include <string>

using namespace std;

/*==========================================================
							color()
============================================================*/
color::color() {
	red = 0;
	green = 0;
	blue = 0;
}

/*==========================================================
							getRed()
============================================================*/
int color::getRed()
{
	return red;
}

/*==========================================================
							getBlue()
============================================================*/
int color::getBlue()
{
	return blue;
}

/*==========================================================
							getGreen()
============================================================*/
int color::getGreen()
{
	return green;
}

/*==========================================================
							set(r, g, b)
============================================================*/
void color::set(int r, int b, int g)
{
	if (r > 255)
	{
		red = 255;
	}
	else if (r < 0)
	{
		red = 0;
	}
	else
	{
		red = r;
	}

	if (b > 255)
	{
		blue = 255;
	}
	else if (b < 0)
	{
		blue = 0;
	}
	else
	{
		blue = b;
	}

	if (g > 255)
	{
		green = 255;
	}
	else if (g < 0)
	{
		green = 0;
	}
	else
	{
		green = g;
	}
} // set()

/*==========================================================
							print()
============================================================*/
void color::print()
{
	cout << "R:" << red << " B:" << blue << " G:" << green << endl;
}

/*==========================================================
							+ overload
============================================================*/
color operator+(color a, color b)
{
	color newColor;
	int newR = a.red + b.red;
	int newB = a.blue + b.blue;
	int newG = a.green + b.green;

	if (newR > 255)
	{
		newR = 255;
	}
	if (newB > 255)
	{
		newB = 255;
	}
	if (newG > 255)
	{
		newG = 255;
	}

	newColor.red = newR; newColor.blue = newB; newColor.green = newG;
	return newColor;
} // + overload


/*==========================================================
							- overload
============================================================*/
color operator-(color a, color b)
{
	color newColor;
	int newR = a.red - b.red;
	int newB = a.blue - b.blue;
	int newG = a.green - b.green;

	if (newR < 0)
	{
		newR = 0;
	}
	if (newB < 0)
	{
		newB = 0;
	}
	if (newG < 0)
	{
		newG = 0;
	}
	
	newColor.red = newR; newColor.blue = newB; newColor.green = newG;
	return newColor;
} // - overload

/*==========================================================
							* overload
============================================================*/
color operator*(int b, color a)
{
	color newColor;
	int newR = a.getRed() * b;
	int newB = a.getBlue() * b;
	int newG = a.getGreen() * b;

	newColor.set(newR, newB, newG);
	return newColor;
}

/*==========================================================
							/ overload
============================================================*/
color operator/(color a, int b)
{
	if (b == 0)
	{
		return color();
	}
	color newColor;
	int newR = a.getRed() / b;
	int newB = a.getBlue() / b;
	int newG = a.getGreen() / b;

	newColor.set(newR, newB, newG);
	return newColor;
}
