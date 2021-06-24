#include<bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	int width, height;

public:
	Rectangle(int width, int height) {
		this->width = width;
		this->height = height;
	}

	const int get_width() {
		return this->width;
	}

	const int get_height() {
		return this->height;
	}

	void set_width(int width) {
		if(0 < width && width <= 1000)
			this->width = width;
	}

	void set_height(int height) {
		if(0 < height && height <= 2000)
			this->height = height;
	}

	const int area() {
		return this->width * this->height;
	}

	const int perimeter() {
		return 2 * (this->width + this->height);
	}

	const bool is_square() {
		if (this->width == this->height) return true;
		else return false;
	}
};