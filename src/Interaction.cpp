
#include "Interaction.hpp"
#include <math.h>

Interaction::Interaction()
{
}

Interaction::~Interaction()
{
}

bool Interaction::chase(Bug &b, Goat g)
{

    float xDistance = b.get_Offset()->x - g.get_Offset()->x;
    float zDistance = b.get_Offset()->z - g.get_Offset()->z;
    float distance = ROUND_2_DECIMAL(sqrt(xDistance*xDistance + zDistance*zDistance));

    float goatRelX = ROUND_2_DECIMAL(xDistance / distance);
    float goatRelZ = ROUND_2_DECIMAL(zDistance / distance);

    float bugDirectionX = cos(b.get_Rotation()->y);
    float bugDirectionZ = sin(b.get_Rotation()->y);

    float dotPosDir = goatRelX * bugDirectionX + goatRelZ * bugDirectionZ; // dot product

    // Bug state: decide

    if (b.get_State() == DIVING_DOWN)
    {
    	if (g.collidesWithPoint(b.get_Offset()->x, b.get_Offset()->y, b.get_Offset()->z))
    	{
        	return true;
    	}

	    if (b.get_FramesInCurrentState() > b.get_DiveDuration() / 2)
	    {
	        b.diveUp();
	    }
	}
    else if (b.get_State() == DIVING_UP)
    {
    	if (g.collidesWithPoint(b.get_Offset()->x, b.get_Offset()->y, b.get_Offset()->z))
      	{
      		return true;
      		//START_SCREEN
      	}

    	if (b.get_FramesInCurrentState() > b.get_DiveDuration() / 2)
    	{
    		b.flightStraight();
    		//bugOffset->y = 0.0f + b.get_FlightHeight(); // Correction of possible rounding errors
    	}
    }
    else
    {
    	if (distance > b.get_DiveDistance())
      	{
        	if (dotPosDir < 0.98f) 
          	{
        		b.turn();
          	}
        	else
          	{
        		b.flightStraight();
        	}
        }
        else
      	{
        	b.diveDown();
      	}
    }
    return false;
}

void Interaction::field(Movil &m, Plane p)
{
	shared_ptr<glm::vec3> mOffset = m.get_Offset();

	if(p.maxZ() == p.minZ())
	{
		if(mOffset->z > p.maxZ() && mOffset->z - p.maxZ() < 0.2f && mOffset->x > p.minX()-0.1f && mOffset->x < p.maxX()+0.1f && mOffset->y <= p.maxY())
			mOffset->z=p.maxZ()+0.2f;
		if(mOffset->z < p.maxZ() && p.maxZ() - mOffset->z < 0.2f && mOffset->x > p.minX()-0.1f && mOffset->x < p.maxX()+0.1f && mOffset->y <= p.maxY())
			mOffset->z=p.maxZ()-0.2f;
	}
	else if(p.maxX() == p.minX())
	{
		if(mOffset->x > p.maxX() && mOffset->x - p.maxX() < 0.2f && mOffset->z > p.minZ()-0.1f && mOffset->z < p.maxZ()+0.1f && mOffset->y <= p.maxY())
			mOffset->x=p.maxX()+0.2f;
		if(mOffset->x < p.maxX() && p.maxX() - mOffset->x < 0.2f && mOffset->z > p.minZ()-0.1f && mOffset->z < p.maxZ()+0.1f && mOffset->y <= p.maxY())
			mOffset->x=p.maxX()-0.2f;
	}
	else
	{
		if(mOffset->z > p.maxZ())
			mOffset->z=p.maxZ();
		if(mOffset->z < p.minZ())
			mOffset->z=p.minZ();

		if(mOffset->x > p.maxX())
			mOffset->x=p.maxX();
		if(mOffset->x < p.minX())
			mOffset->x=p.minX();
	}

	m.set_Offset(mOffset);
}