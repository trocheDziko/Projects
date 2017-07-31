#include "Texture.h"
#include <SFML\Graphics\CircleShape.hpp>
#include<iostream>
#include "Fixture.h"
static const float SCALE = 30.0f;

Texture::Texture()
{
}


Texture::~Texture()
{
}


void Texture::bodyTexture(b2World* World, sf::RenderWindow &Window)
{
	int BodyCount = 0;
	for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		bodyUserData* udStruct = (bodyUserData*)BodyIterator->GetUserData();
		if (BodyIterator->GetType() == b2_dynamicBody)// && BodyIterator->GetFixtureList()->GetUserData() == "Rect")
		{
			
			if (udStruct->type == "Rect")
			{
				float w = udStruct->w;
				float s = udStruct->s;
				sf::RectangleShape rectangle;
				rectangle.setSize(sf::Vector2f(2*w*SCALE, 2*s*SCALE));
				rectangle.setOutlineColor(sf::Color::Blue);
				rectangle.setOutlineThickness(1);
				rectangle.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				rectangle.setOrigin(w*SCALE, s*SCALE);
				float angle = ((180 / b2_pi)*BodyIterator->GetAngle());
				rectangle.setRotation(angle);
				Window.draw(rectangle);


				/*sf::Texture BoxTexture;
				BoxTexture.loadFromFile("box.png");
				sf::Sprite Sprite;
				Sprite.setTexture(BoxTexture);
				Sprite.setOrigin(16.f, 16.f);
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
				Window.draw(Sprite); */
				++BodyCount;
			}
			else if (udStruct->type == "Circle")
			{
				float r = udStruct->radius;
				sf::CircleShape circle;
				circle.setRadius(r);
				circle.setOrigin(r, r);
				circle.setOutlineColor(sf::Color::Red);
				circle.setOutlineThickness(1);
				circle.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Window.draw(circle);
				
				
				
				/*sf::Texture CircleTexture;
				CircleTexture.loadFromFile("circle.png");
				sf::Sprite StaticSprite;
				StaticSprite.setTexture(CircleTexture);
				StaticSprite.setOrigin(16.f, 16.f);
				StaticSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
				StaticSprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
				Window.draw(StaticSprite); */
				++BodyCount;
			}
			else if (udStruct->type == "Triangle")
			{

				//sf::VertexArray triangle(sf::Triangles, 3);
				// define the position of the triangle's points
				sf::ConvexShape sftra;
				sftra.setPointCount(3);
				sftra.setPoint(0, SCALE* sf::Vector2f(0, -1));
				sftra.setPoint(1, SCALE* sf::Vector2f(1, 1));
				sftra.setPoint(2, SCALE* sf::Vector2f(-1, 1));
				//float r = udStruct->radius;
				sftra.setOutlineColor(sf::Color::Green);
				sftra.setOutlineThickness(1);
				static b2MassData msda;
				BodyIterator->GetMassData(&msda);
				sftra.setOrigin(msda.center.x, msda.center.y); //ConvexShape
				sftra.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
				float angle = ((180 / b2_pi)*BodyIterator->GetAngle());
				sftra.setRotation(angle);

				Window.draw(sftra);
				++BodyCount;
			}
			/*if (BodyIterator->GetType() == b2_staticBody)
			{
			sf::Texture GroundTexture;
			GroundTexture.loadFromFile("ground.png");

			sf::Sprite GroundSprite;
			GroundSprite.setTexture(GroundTexture);
			GroundSprite.setOrigin(400.f, 8.f);
			GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
			GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
			Window.draw(GroundSprite);
			} /**/
			}
		else if (BodyIterator->GetType() == b2_staticBody)
			{
			float w = udStruct->w;
			float s = udStruct->s;
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(2*SCALE*w, 2*SCALE*s));
			rectangle.setOrigin(SCALE*w, SCALE*s);
			rectangle.setOutlineColor(sf::Color::Black);
			rectangle.setOutlineThickness(1);
			rectangle.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
			rectangle.setOrigin(w*SCALE, s*SCALE);
			float angle = ((180 / b2_pi)*BodyIterator->GetAngle());
			rectangle.setRotation(angle);
			Window.draw(rectangle);
			++BodyCount;
			}
		//b2Vec2 position = BodyIterator->GetPosition();
		//if (position.x*SCALE > 820 && position.y*SCALE > 500)  //dla 820 dobrze
		//{
		
		//	BodyIterator->ApplyLinearImpulse(b2Vec2(-10, -10), BodyIterator->GetPosition(), false); //b2Vec2(-20, -20)
		//}
	}
}