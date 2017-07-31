#include "Draw.h"
#include <iostream>
#include "Body.h"
#include "Fixture.h"
static const float SCALE = 30.0f;

Draw::Draw()
{
}


Draw::~Draw()
{
}

void Draw::air(b2World* World, bool stop)
{
	for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		b2Vec2 position = BodyIterator->GetPosition();
		if (stop == false)
		{
			if (position.x*SCALE > 820 && position.y*SCALE > 500)  //dla 820 dobrze
			{

				BodyIterator->ApplyLinearImpulse(b2Vec2(-50, -10), BodyIterator->GetPosition(), false); //b2Vec2(-20, -20)
			}
		}
		else
		{
			BodyIterator->ApplyLinearImpulse(b2Vec2(0, 0), BodyIterator->GetPosition(), false);
		}
	}
}

bool Draw::countShapes(b2World* World)
{
	int shapesCounter=0;
	bool stop= false;
	for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		b2Vec2 position = BodyIterator->GetPosition();
		if ((position.x*SCALE > 200 && position.y*SCALE < 245) && BodyIterator->GetType() == b2_dynamicBody)  //dla 820 dobrze
		{
			shapesCounter++;
			//std::cout << shapesCounter;
			if (shapesCounter == 6)
			{
				stop = true;
			}
		}
	}
	return stop;
}
