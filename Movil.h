#pragma once

class Movil
{
protected:
	shared_ptr<small3d::SceneObject> Object;
	float RotationSpeed;
	float Speed;
	~Movil();
public:
	Movil();
	void dontMove();
	void set_RotationSpeed(float rs);
	float get_RotationSpeed();
	void set_Speed(float s);
	float get_Speed();
	void set_Offset(shared_ptr<glm::vec3> off);
	shared_ptr<glm::vec3> get_Offset();
	void set_Rotation(shared_ptr<glm::vec3> rot);
	shared_ptr<glm::vec3> get_Rotation();

	virtual void move();
	virtual void init();
	virtual void render(shared_ptr<small3d::Renderer> &r);

};

Movil::Movil()
{

}

Movil::~Movil()
{
	
}

void Movil::set_RotationSpeed(float rs)
{
	RotationSpeed=rs;
}

float Movil::get_RotationSpeed()
{
	return RotationSpeed;
}

void Movil::set_Offset(shared_ptr<glm::vec3> off)
{
	Object->setOffset(off->x, off->y, off->z);
}

shared_ptr<glm::vec3> Movil::get_Offset()
{
	return Object->getOffset();
}

void Movil::dontMove()
{
	Object->stopAnimating();
}

void Movil::set_Speed(float s)
{
	Speed = s;
}

float Movil::get_Speed()
{
	return Speed;
}

void Movil::init()
{

}

void Movil::move()
{
	
}

void Movil::render(shared_ptr<small3d::Renderer> &r)
{
	r->renderSceneObject(Object);
}

void Movil::set_Rotation(shared_ptr<glm::vec3> rot)
{
	Object->setRotation(rot->x, rot->y, rot->z);	
}

shared_ptr<glm::vec3> Movil::get_Rotation()
{
	return 	Object->getRotation();
}