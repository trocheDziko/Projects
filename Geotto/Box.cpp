#include "Box.h"
static const float SCALE = 30.0f;

Box::Box()
{
}


Box::~Box()
{
}

b2PolygonShape Box::createBoxShape(float W, float S, bodyUserData* myStruct)
{
	b2PolygonShape cBoxShape;
	cBoxShape.SetAsBox((W / 2) / SCALE, (S / 2) / SCALE);
	myStruct->w = (W / 2) / SCALE;
	myStruct->s = (S / 2) / SCALE;
	return cBoxShape;
}


void Box::createBox(b2Body* body, b2PolygonShape &shape, float density, float friction, float restituation,
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