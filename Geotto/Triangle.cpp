#include "Triangle.h"


Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

b2PolygonShape Triangle::createTriangleShape()
{
	b2Vec2 vertices[3];
	vertices[0].Set(0, -1);
	vertices[1].Set(1, 1);
	vertices[2].Set(-1, 1);

	b2PolygonShape polygonShape;
	polygonShape.Set(vertices, 3);

	return polygonShape;
}


void Triangle::createTriangle(b2Body* body, b2PolygonShape &shape, float density, float friction, float restituation,
	bodyUserData* myStruct, int number)
{
	//b2PolygonShape boxShape;
	//boxShape.SetAsBox(W, S);
	myStruct->number = number;
	myStruct->type = "Triangle";
	b2FixtureDef boxFixDef;
	boxFixDef.shape = &shape;
	boxFixDef.density = density;
	boxFixDef.friction = friction;
	boxFixDef.restitution = restituation;
	//boxFixDef.userData = "Rect";
	body->SetUserData(myStruct);
	body->CreateFixture(&boxFixDef);


}