#pragma once

#include "Vector2D.h"
#include <dimitrikourk/small3d/SceneObject.hpp>
#include <dimitrikourk/small3d/Renderer.hpp>

class Pared
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	char *name;
	char *route;

	Vector2D limite1;
	Vector2D limite2;

public:
	Pared(void);
	virtual ~Pared(void);
	void load(shared_ptr<small3d::Renderer> &r, char *_route, char *_name);
	void render(shared_ptr<small3d::Renderer> &r);
	void setColor(int, int, int);
	void setPos(float, float, float, float);
	friend class Interaccion;
	float Distancia(Vector2D punto, Vector2D *direccion);
	Vector2D getLimite1();
	Vector2D getLimite2();

protected:
	char fondo[255];
};


//#include "Pared.h"
#include <string.h>

Pared::Pared(void)
{
}

Pared::~Pared(void)
{
}

void Pared::load(shared_ptr<small3d::Renderer> &r, char *_route, char *_name)
{
	name=new char[strlen(_name)+1];
    strcpy(name, _name);

    route=new char[strlen(_route)+1];
    strcpy(route, _route);

	unique_ptr<Image> groundTexture(new Image(route));
    r->generateTexture(name, groundTexture->getData(), groundTexture->getWidth(), groundTexture->getHeight());

}

void Pared::setColor(int red, int green, int blue)
{
	rojo=red;
	verde=green;
	azul=blue;
}

void Pared::setPos(float a, float b, float c, float d)
{
	limite1.x=a;
	limite1.y=b;
	limite2.x=c;
	limite2.y=d;
}

void Pared::render(shared_ptr<small3d::Renderer> &r)
{
    float groundVerts[16] =
      {
        -25.0f, GROUND_Y, MAX_Z, 1.0f,
        25.0f, GROUND_Y, MAX_Z, 1.0f,
        25.0f, GROUND_Y,  MIN_Z, 1.0f,
        -25.0f, GROUND_Y, MIN_Z, 1.0f
      };

    r->renderImage(&groundVerts[0], name, true, glm::vec3(0.0f, 0.0f, 0.0f));
}

/*float Pared::Distancia(Vector2D punto, Vector2D *direccion)
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

Vector2D Pared::getLimite1()
{
	return limite1;
}
	
Vector2D Pared::getLimite2()
{
	return limite2;
}