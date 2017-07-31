#include "CreateObject.h"
#include "Body.h"
#include "Fixture.h"
#include "Texture.h"

static const float SCALE = 30.0f;

CreateObject::CreateObject()
{
}


CreateObject::~CreateObject()
{
}

void CreateObject::createCircleObject(b2World* myWorld, Circle Body, float X, float Y, float R, float density,
	float friction, float restituation, string bodyType, int number)
{
	b2Body* circle = Body.bodyPointer;
	circle = Body.createBody(myWorld, bodyType, X, Y, 0);
	b2CircleShape testCircle = Body.createCircleShape(0, 0, R, Body.myStruct);
	Body.createCircle(circle, testCircle, density, friction,restituation, Body.myStruct, number);
}

void CreateObject::createBoxObject(b2World* myWorld, Box Body, float X, float Y, float W, float S,float density, 
	float friction, float restituation, string bodyType, int number)
{
	//Body.X = W;
	//Body.Y = S;
	b2Body* body = Body.bodyPointer;
	body = Body.createBody(myWorld, bodyType, X, Y, 0);
	b2PolygonShape testBody = Body.createBoxShape(W, S, Body.myStruct);
	Body.createBox(body, testBody, density, friction, restituation, Body.myStruct, number);
}

void CreateObject::createBoxObject2(b2World* myWorld, Box Body, float X, float Y, float W, float S, float density,
	float friction, float restituation, string bodyType, int number)
{
	//Body.X = W;
	//Body.Y = S;
	b2Body* body = Body.bodyPointer;
	body = Body.createBody(myWorld, bodyType, X, Y, 0.1);
	b2PolygonShape testBody = Body.createBoxShape(W, S, Body.myStruct);
	Body.createBox(body, testBody, density, friction, restituation, Body.myStruct, number);
}

void CreateObject::createTriangleObject(b2World* myWorld, Triangle Body, float X, float Y, float density,
	float friction, float restituation, string bodyType, int number)
{
	b2Body * trian = Body.createBody(myWorld, bodyType, X, Y, 0);
	b2PolygonShape testBody = Body.createTriangleShape();
	Body.createTriangle(trian, testBody, density, friction, restituation, Body.myStruct, number);

}

void CreateObject::createMap(b2World* myWorld)
{
	Box Ground;
	//Texture Ground;
	CreateObject groundObject;
	groundObject.createBoxObject2(myWorld, Ground, 0, 600, 1600, 40, 0.1, 0.1, 0.5, "stat", NULL); //690

	Box leftWall;
	//Texture leftWall;
	CreateObject leftWallObject;
	leftWallObject.createBoxObject(myWorld, leftWall, 10, 20, 30, 600 * SCALE, 0.1, 0.1, 0.5, "stat", NULL);

	Box rightWall;
	//Texture rightWall;
	CreateObject rightWallObject;
	rightWallObject.createBoxObject(myWorld, rightWall, 1010, 20, 30, 600 * SCALE, 0.1, 0.1, 0.5, "stat", NULL);

	Box upperWall;
	//Texture upperWall;
	CreateObject upperWallObject;
	upperWallObject.createBoxObject(myWorld, upperWall, 5, 5, 1024 * SCALE, 10, 0.1, 0.1, 0.5, "stat", NULL);

	Box middleWall;
	//Texture middleWall;
	CreateObject middleWallObject;
	middleWallObject.createBoxObject(myWorld, middleWall, 800, 250, 1200, 10, 0.1, 0.1, 0.5, "stat", NULL);
	
	Box miniWall;
	//Texture miniWall;
	CreateObject miniWallObject;
	miniWallObject.createBoxObject(myWorld, miniWall, 205, 200, 10, 100, 0.1, 0.1, 0.1, "stat", NULL);
}