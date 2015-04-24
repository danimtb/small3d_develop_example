

#include "Plane.hpp"
#include <string.h>

using namespace small3d;

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