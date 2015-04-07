#pragma once

class Vector3D
{
public:
	Vector3D(float ix=0, float iy=0, float iz=0):x(ix),y(iy),z(iz)
	{
	}

	float x;
	float y;
	float z;

	~Vector2D(void);
	
	Vector2D operator+(Vector2D op)
	{
		return Vector2D(x+op.x, y+op.y, z+op.z);
	}

	Vector2D operator-(Vector2D op)
	{
		return Vector2D(x-op.x, y-op.y, z-op.z);
	}

	float operator*(Vector2D op)
	{
		return x*op.x+y*op.y+z*op.z; //producto escalar
	}

	Vector2D operator*(float f)
	{
		return Vector2D(x*f, y*f, y*f);
	}

	float modulo();
	float argumento();
	
	Vector2D unitario();

};