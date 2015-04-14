#pragma once

#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>

class Plane
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	char *name;
	char *route;

	float max_z;
	float min_z;
	float max_y;
	float min_y;
	float max_x;
	float min_x;

public:
	Plane(void);
	virtual ~Plane(void);
	void load(shared_ptr<small3d::Renderer> &r, char *_route, char *_name);
	void render(shared_ptr<small3d::Renderer> &r, bool perspective);
	void setColor(int, int, int);
	void setPos(float maxX, float minX, float maxY, float minY, float maxZ, float minZ);
	float maxX();
	float minX();
	float maxY();
	float minY();
	float maxZ();
	float minZ();
	
	//float Distancia(Vector2D punto, Vector2D *direccion);

	friend class Interaction;
};


//#include "Plane.h"
#include <string.h>

Plane::Plane(void)
{
}

Plane::~Plane(void)
{
}

void Plane::load(shared_ptr<small3d::Renderer> &r, char *_route, char *_name)
{
	name=new char[strlen(_name)+1];
    strcpy(name, _name);

    route=new char[strlen(_route)+1];
    strcpy(route, _route);

	unique_ptr<Image> groundTexture(new Image(route));
    r->generateTexture(name, groundTexture->getData(), groundTexture->getWidth(), groundTexture->getHeight());

}

void Plane::setColor(int red, int green, int blue)
{
	rojo=red;
	verde=green;
	azul=blue;
}

void Plane::setPos(float maxX, float minX, float maxY, float minY, float maxZ, float minZ)
{
	max_x=maxX;
	min_x=minX;
	max_y=maxY;
	min_y=minY;
	max_z=maxZ;
	min_z=minZ;
}

void Plane::render(shared_ptr<small3d::Renderer> &r, bool perspective)
{
	float verts[16];

	if(min_x==max_x)
	{
		if(r->cameraPosition.x < min_x)
		{
			verts[0]=min_x; verts[1]=min_y; verts[2]=min_z, verts[3]=1.0f;
			verts[4]=min_x;  verts[5]=min_y;  verts[6]=max_z;  verts[7]=1.0f;
			verts[8]=min_x;  verts[9]=max_y;  verts[10]=max_z;  verts[11]=1.0f;
			verts[12]=min_x;  verts[13]=max_y;  verts[14]=min_z; verts[15]=1.0f;
		}
		else
		{
			verts[0]=min_x;  verts[1]=min_y;  verts[2]=max_z;  verts[3]=1.0f;
			verts[4]=min_x;  verts[5]=min_y;  verts[6]=min_z;  verts[7]=1.0f;
			verts[8]=min_x;  verts[9]=max_y;  verts[10]=min_z; verts[11]=1.0f;
			verts[12]=min_x; verts[13]=max_y; verts[14]=max_z, verts[15]=1.0f;
		}
    }
    else
	{
      	verts[0]=min_x;  verts[1]=min_y;  verts[2]=max_z;  verts[3]=1.0f;
		verts[4]=max_x;  verts[5]=min_y;  verts[6]=max_z;  verts[7]=1.0f;
		verts[8]=max_x;  verts[9]=max_y;  verts[10]=min_z; verts[11]=1.0f;
		verts[12]=min_x; verts[13]=max_y; verts[14]=min_z, verts[15]=1.0f;
	}

    if(perspective)
    	r->renderImage(&verts[0], name, true);
    else
    	r->renderImage(&verts[0], name, false);												

}

/*float Plane::Distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u=(punto-limite1);
	Vector2D v=(limite2-limite1).unitario();
	float longitud=(limite1-limite2).modulo();
	Vector2D dir;
	float valor=u*v;
	float distancia=0;

	if(valor<0)
		dir=u;
	else if(valor>longitud)
		dir=(punto-limite2);
	else
		dir=u-v*valor;
	distancia=dir.modulo();
	if(direccion!=0)
		*direccion=dir.unitario();
	return distancia;
}
*/

float Plane::maxX()
{
	return max_x;
}

float Plane::minX()
{
	return min_x;
}

float Plane::maxY()
{
	return max_y;
}

float Plane::minY()
{
	return min_y;
}

float Plane::maxZ()
{
	return max_z;
}

float Plane::minZ()
{
	return min_z;
}