#pragma once

class Vector2D
{
public:
	Vector2D(float ix=0, float iy=0):x(ix),y(iy)
	{
	}

	float x;
	float y;
	~Vector2D(void);
	Vector2D operator+(Vector2D op)
	{
		return Vector2D(x+op.x, y+op.y);
	}

	Vector2D operator-(Vector2D op)
	{
		return Vector2D(x-op.x, y-op.y);
	}

	float operator*(Vector2D op)
	{
		return x*op.x+y*op.y; //producto escalar
	}

	Vector2D operator*(float f)
	{
		return Vector2D(x*f, y*f);
	}

	float modulo();
	float argumento();
	
	Vector2D unitario();

};
