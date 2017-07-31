#include "Fixture.h"
static const float SCALE = 30.0f;

Fixture::Fixture()
{
}


Fixture::~Fixture()
{
}



/*b2PolygonShape Fixture::createBoxShape(float W, float S, bodyUserData* myStruct)
{
	b2PolygonShape cBoxShape;
	cBoxShape.SetAsBox((W/2)/SCALE, (S/2)/SCALE);
	myStruct->w = (W / 2) / SCALE;
	myStruct->s = (S / 2) / SCALE;
	return cBoxShape;
}


void Fixture::createBox(b2Body* body, b2PolygonShape &shape, float density, float friction,float restituation, 
	bodyUserData* myStruct, int number)
{
	//b2PolygonShape boxShape;
	//boxShape.SetAsBox(W, S);
	myStruct->number = number;
	myStruct->type = "Rect";
	b2FixtureDef boxFixDef;
	boxFixDef.shape = &shape;
	boxFixDef.density = density;
	boxFixDef.friction = friction;
	boxFixDef.restitution = restituation;
	//boxFixDef.userData = "Rect";
	body->SetUserData(myStruct);
	body->CreateFixture(&boxFixDef);

	
}

b2CircleShape Fixture::createCircleShape(float X, float Y, float radius, bodyUserData* myStruct)
{
	b2CircleShape circleShape;
	circleShape.m_p.Set((X / 2) / SCALE, (Y / 2) / SCALE);
	myStruct->x = (X / 2) / SCALE;
	myStruct->y = (Y / 2) / SCALE;
	circleShape.m_radius = radius / SCALE;
	myStruct->radius = radius;
	return circleShape;
}

void Fixture::createCircle(b2Body* body, b2CircleShape &circleShape, float density, float friction, float restituation,
	bodyUserData* myStruct, int number)
{
	myStruct->number = number;
	myStruct->type = "Circle";
	b2FixtureDef circleFixDef;
	circleFixDef.shape = &circleShape;
	circleFixDef.density = density;
	circleFixDef.friction = friction;
	circleFixDef.restitution = restituation;
	//circleFixDef.userData = "Circle";
	body->CreateFixture(&circleFixDef);
	body->SetUserData(myStruct);

} */

void Fixture::numbers(b2World* World)
{
	for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		b2Vec2 position = BodyIterator->GetPosition();
		bodyUserData* udStruct = (bodyUserData*)BodyIterator->GetUserData();
		int numer = udStruct->number;
		if ((position.x*SCALE > 200 && position.y*SCALE < 245) && BodyIterator->GetType() == b2_dynamicBody)
		{
			std::cout << numer << endl;	
		}
	}
}
