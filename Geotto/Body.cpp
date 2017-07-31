#include "Body.h"
#include <SFML\Graphics.hpp>
static const float SCALE = 30.0f;


Body::Body()
{
}


Body::~Body()
{
}


b2Body* Body::createBody(b2World* World, string bodyType, int pozX, int pozY, float32 kat)
{
	if (bodyType == "dyn")
	{
		b2BodyDef  dynBodyDef;
		dynBodyDef.type = b2_dynamicBody;
		dynBodyDef.position = b2Vec2(pozX / SCALE, pozY / SCALE);
		dynBodyDef.angle = kat;
		//dynBodyDef.fixedRotation = true;
		b2Body* dynamicBody = World->CreateBody(&dynBodyDef);
		//dynamicBody->SetTransform(dynBodyDef.position, dynBodyDef.angle);
		return dynamicBody;
	}
	else if (bodyType == "stat")
	{
		b2BodyDef  statBodyDef;
		statBodyDef.type = b2_staticBody;
		statBodyDef.position.Set(pozX/SCALE, pozY/SCALE);
		statBodyDef.angle = kat;

		b2Body* staticBody = World->CreateBody(&statBodyDef);
		return staticBody;
	}
}

void Body::deleteBody(b2World* World, b2Body* body)
{
	World->DestroyBody(body);
}

