#include <SFML\Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include "Body.h"
#include "Fixture.h"
#include "Texture.h"
#include "CreateObject.h"
#include "Draw.h"
#include <cstdlib>
#include <ctime>
#include "Triangle.h"
static const float SCALE = 30.0f;

int main()
{
	srand(time(NULL));
	sf::Event event;

	sf::RenderWindow Window(sf::VideoMode(1024,680, 32), "Lotto");
	Window.setFramerateLimit(60);

	b2Vec2 Gravity(0.f, 9.8f);
	b2World* myWorld = new b2World(Gravity);	

	Body Main;
	string bodyType = "dyn";
	
	Box testB;
	Triangle testT;
	b2Body* trian = testT.bodyPointer;
	//Texture testB;
	CreateObject boxObject;
	CreateObject circleObject;
	Circle testC;
	//Texture testC;
	//b2Body* circle = testC.bodyPointer;
	
	Texture test;
	test.X = 50.f;
	test.Y = 50.f;
	b2Body* testBoxx = test.bodyPointer;
	
	Box losowanie1[48];
	Circle losowanie2[48];
	Triangle losowanie3[48];
	CreateObject losowanie;

	CreateObject Map;
	Map.createMap(myWorld);

	Draw lotto;
	bool stop;
	while (Window.isOpen())
	{
		stop = lotto.countShapes(myWorld);
		lotto.air(myWorld, stop);
		losowanie1[0].numbers(myWorld);
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				int MouseX = sf::Mouse::getPosition(Window).x;
				int MouseY = sf::Mouse::getPosition(Window).y;
				
				
				//boxObject.createBoxObject(myWorld, testB, MouseX, MouseY, 32, 32, 0.1, 0.1, 0.1, "dyn", NULL);
				trian = testT.createBody(myWorld, bodyType, MouseX, MouseY, 0);
				b2PolygonShape testBoox = testT.createTriangleShape();
				testT.createTriangle(trian, testBoox ,0.1, 0.1, 0.1, testT.myStruct, NULL); 
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				int MouseX = sf::Mouse::getPosition(Window).x;
				int MouseY = sf::Mouse::getPosition(Window).y;
				
				circleObject.createCircleObject(myWorld, testC, MouseX, MouseY, 16, 0.5, 0.5, 0.5, "dyn", NULL);

				/*circle = testC.createBody(myWorld, bodyType, MouseX, MouseY, 0);
				b2CircleShape testCircle = testC.createCircleShape(0, 0, 16, testC.myStruct);
				testC.createCircle(circle, testCircle, 0.5, 0.5, testC.myStruct); */
			}
			if (event.type == sf::Event::KeyPressed && sf::Keyboard::Q)
			{
			//	testBoxx = test.createBody(myWorld, bodyType, 40, 40, 0);
			//	b2PolygonShape testBoxxx = test.createBoxShape(test.X, test.Y, test.myStruct);
			//	testB.createBox(testBoxx, testBoxxx, 10, 0.1,0.5, test.myStruct);
			}
			if (event.type == sf::Event::KeyPressed && sf::Keyboard::S)
			{
				//float density = 0.5;
				//float friction = 0.5;
				//float restitution = 0.5;
				int i = 0;
				for (int i = 0; i < 48;i++)
				{
					float density = (float)(rand()) / (RAND_MAX - 1);
					float friction = (float)(rand()) / (RAND_MAX - 1);
					float restitution = (float)(rand()) / (RAND_MAX - 1);
					

					//int sizeX = rand() % 50;
					/*int sizeY = sizeX;
					int X = rand() % 400 + 450;
					int Y = (rand() % 400) + 250;
					float number = rand() % 2; */
					int sizeX = rand() % 45;
					int sizeY = sizeX;
					int X = (rand() % 400) + 550;
					int Y = (rand() % 400) + 250;
					//float number = (float)(rand()) / (RAND_MAX - 1);
					int number = (rand() % 4);
					int radius = rand() % 40; 
					
					if (number == 1)
					{
						losowanie.createBoxObject(myWorld, losowanie1[i], X, Y, sizeX, sizeY, density, friction, restitution, "dyn", i);
						
					}
					else if (number== 2)
					{

						losowanie.createCircleObject(myWorld, losowanie2[i], X, Y, radius, density, friction, restitution, "dyn", i);
						
					}
					else if (number == 3)
					{

						losowanie.createTriangleObject(myWorld, losowanie3[i], X, Y, density, friction, restitution, "dyn", i);

					}
				}
			}
			if (event.type == sf::Event::Closed){
				Window.close();
			}
		}



		//myWorld->Step(1 / 60.f, 8, 3);

		
		Window.clear(sf::Color::White);
		test.bodyTexture(myWorld, Window);
		myWorld->Step(1 / 60.f, 8, 3);
		Window.display();
	}

	//for (b2Body* BodyIterator = myWorld->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	//{
	//	Main.deleteBody(myWorld, BodyIterator);
	//}
	return 0;
}
