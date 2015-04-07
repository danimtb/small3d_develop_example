#include "Vector3D.h"
#include <math.h>


Vector3D::~Vector3D(void)
{
}

float Vector3D::modulo()
{
	return (float)sqrt(sqrt(x*x+y*y)*sqrt(x*x+y*y)+z*z);
}

float Vector3D::argumento()
{
	return atan2(y, x);
}

Vector2D Vector3D::unitario()
{
	Vector3D retorno(x, y, z);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod;
		retorno.z/=mod;
	}
	return retorno;
}