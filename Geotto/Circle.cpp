#include "Circle.h"
#include "Fixture.h"
static const float SCALE = 30.0f;
Circle::Circle()
{
}


Circle::~Circle()
{
}


b2CircleShape Circle::createCircleShape(float X, float Y, float radius, bodyUserData* myStruct)
{
	b2CircleShape circleShape;
	circleShape.m_p.Set((X / 2) / SCALE, (Y / 2) / SCALE);
	myStruct->x = (X / 2) / SCALE;
	myStruct->y = (Y / 2) / SCALE;
	circleShape.m_radius = radius / SCALE;
	myStruct->radius = radius;
	return circleShape;
}

void Circle::createCircle(b2Body* body, b2CircleShape &circleShape, float density, float friction, float restituation,
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

}
