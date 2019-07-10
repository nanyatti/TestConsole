#pragma once

// 2¬•ª‚Ìfloat’l‚ğˆµ‚¤ƒNƒ‰ƒX
class Float2 {

public:

	float x;
	float y;

	Float2() {}
	Float2(float x, float y) : x(x), y(y) {}
	~Float2() {}

	Float2 operator+(Float2 const & f) const {
		return Float2(x + f.x, y + f.y);
	}

	Float2 operator-(Float2 const & f) const {
		return Float2(x - f.x, y - f.y);
	}

};