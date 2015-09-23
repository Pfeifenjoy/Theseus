#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

/**
 * Represents a ball.
 * Also here: In a real Project, you would seperate Declaration and Definition in a *.h and a *.cpp file.
 */
class Ball : public sf::CircleShape
{
public:

	/**
	 * Initialisation
	 */
	Ball()
	{
		setSpeed(sf::Vector2f(0,0));
	}

	/**
	 * Sets the speed of the ball
	 */
	void setSpeed(sf::Vector2f value)
	{
		speed = value;
	}

	/**
	 * Returns the speed of the Ball
	 */
	sf::Vector2f getSpeed() const
	{
		return speed;
	}

	/**
	 * Returns the weight of the circle
	 * 
	 * This is important for physically correct bouncing.
	 */
	float getWeight() const
	{
		float radius = getRadius();
		return radius * radius * radius * 3.1415926535f * 4.f / 3.f;
	}

	/**
	 * Sets the radius of the ball
	 */
	void setRadius(float value)
	{
		sf::CircleShape::setRadius(value);
		sf::CircleShape::setOrigin(value, value);
	}

	/**
	 * Updates the position of the ball
	 */
	void update(float passedTime)
	{
		sf::Vector2f position = getPosition();
		position += speed * passedTime;
		setPosition(position);
	}

	/**
	 * Detects a collision to an other ball and reacts accordingly
	 */
	void detectCollision(Ball& other)
	{
		float minDistance = getRadius() + other.getRadius();
		sf::Vector2f relativePosition = other.getPosition() - getPosition();
		if(relativePosition == sf::Vector2f(0,0))
		{
			relativePosition = sf::Vector2f(0,1);
		}
		float distance = (float)sqrt(relativePosition.x * relativePosition.x + relativePosition.y * relativePosition.y);
		// d for direction (of the collision)
		// d_o is the vector which is orthogonal to the direction
		sf::Vector2f d = relativePosition / distance;
		sf::Vector2f d_o(d.y, -d.x);

		if (distance < minDistance)
		{
			// Collision detectd!
			
			// resolve the collision by moving both balls away from each other
			float overlap = minDistance - distance;
			sf::Vector2f move = d * (overlap / 2);
			sf::Vector2f position = getPosition();
			sf::Vector2f otherPosition = other.getPosition();
			position -= move;
			otherPosition += move;
			setPosition(position);
			other.setPosition(otherPosition);

			// Simulate an elastic collision
			// see: https://de.wikipedia.org/wiki/Sto%C3%9F_%28Physik%29#Elastischer_Sto.C3.9F

			// Seperate the speed into two components:
			//  - one p(arallel) to the direction of collision
			//  - one o(rthogonal) to the direction of collision
			sf::Vector2f speed = getSpeed();
			sf::Vector2f otherSpeed = other.getSpeed();
			float speed_p = speed.x * d.y - speed.y * d.x;
			float speed_o = speed.x * d.x + speed.y * d.y;
			float otherSpeed_p = otherSpeed.x * d.y - otherSpeed.y * d.x;
			float otherSpeed_o = otherSpeed.x * d.x + otherSpeed.y * d.y;
			// The new parallel speed is calculated according to the
			// formular for elastic collisions. The orthogonal speed 
			// does not change.
			float mass = getWeight();
			float otherMass = other.getWeight();
			float tmp = 2 * (mass*speed_p + otherMass * otherSpeed_p) / (mass + otherMass);
			float newSpeed_p = tmp - speed_p;
			float otherNewSpeed_p = tmp - otherSpeed_p;
			// join both speed components and update the ball speeds.
			setSpeed(d * newSpeed_p + d_o * speed_o);
			other.setSpeed(d * otherNewSpeed_p + d_o * otherSpeed_o);
		}
	}

	/**
	 * Detects a collision with the window frame and reacts accordingly.
	 */
	void detectCollision(sf::Vector2u windowSize)
	{
		sf::Vector2f position = getPosition();
		sf::Vector2f speed = getSpeed();
		int windowWidth = windowSize.x;
		int windowHeigth = windowSize.y;
		float radius = getRadius();
		if (position.x < radius)
		{
			position.x = radius;
			if (speed.x < 0)
				speed.x = -speed.x;
		}
		if (position.x > windowWidth - radius)
		{
			position.x = windowWidth - radius;
			if (speed.x > 0)
				speed.x = -speed.x;
		}
		if (position.y < radius)
		{
			position.y = radius;
			if (speed.y < 0)
				speed.y = -speed.y;
		}
		if (position.y > windowHeigth - radius)
		{
			position.y = windowHeigth - radius;
			if (speed.y > 0)
				speed.y = -speed.y;
		}
		setPosition(position);
		setSpeed(speed);
	}

private:
	sf::Vector2f speed;
};

void insert_element(std::vector<Ball>& balls, const std::vector<Ball>::iterator& element)
{
	auto currentElement = element;
	float x = currentElement->getPosition().x;
	while (currentElement != balls.begin())
	{
		auto previous = currentElement - 1;
		float previousX = previous->getPosition().x;
		if (x < previousX)
		{
			Ball tmp = *previous;
			*previous = *currentElement;
			*currentElement = tmp;
			currentElement = previous;
		}
		else
		{
			return;
		}
	}
}

// Main method
int main()
{

	// Create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setVerticalSyncEnabled(true);

	// Load the ball texture
	sf::Texture ballTexture;
	if (!ballTexture.loadFromFile("ball.png"))
	{
		std::cerr << "Could not load file 'ball.png'!" << std::endl;
		return 1;
	}

	// timing
	sf::Clock clock;

	// fpsMeasurement
	sf::Clock fpsMeasurementClock;
	int framesCounter = 0;

	// array of balls
	std::vector<Ball> balls;

	// start with one ball on the screen
	Ball firstBall;
	firstBall.setRadius(50);
	firstBall.setSpeed(sf::Vector2f(100,100));
	firstBall.setTexture(&ballTexture);
	balls.push_back(firstBall);

	// Main loop
	while(window.isOpen())
	{
		// Measure fps
		framesCounter++;
		if (fpsMeasurementClock.getElapsedTime().asSeconds() > 1)
		{
			std::cout << "FPS: " << framesCounter 
				<< " Objects: " << balls.size() << std::endl;
			framesCounter = 0;
			fpsMeasurementClock.restart();
		}

		// process events
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed: 		// Window was closed - end the game
				window.close();
				break;

			case sf::Event::MouseButtonPressed: 	// Mouse was pressed - create a new ball
				{
					for (int i = 0; i < 100; i++){

				
					Ball newBall;
					newBall.setPosition(event.mouseButton.x + i, event.mouseButton.y);
					newBall.setRadius(10);
					newBall.setSpeed(sf::Vector2f(0, 0));
					newBall.setTexture(&ballTexture);
					balls.push_back(newBall);
				}
				break;
				}
			default:
				break;
			}
		}

		// update all entities
		sf::Time elapsedTime = clock.getElapsedTime();
		clock.restart();
		float elapsedSeconds = elapsedTime.asSeconds();
		for(auto& ball: balls)
			ball.update(elapsedSeconds);
		
		// resort the balls
		for (auto it = balls.begin(); it != balls.end(); it++)
		{
			insert_element(balls, it);
		}
		
		// detect collisions by comparing all balls to each other
		for(auto it1 = balls.begin(); it1 != balls.end(); it1++)
		{
			// collision with the window frame
			it1->detectCollision(window.getSize());

			// collision with other balls
			float x = it1->getPosition().x;
			for (auto it2 = it1 + 1; it2 != balls.end() && it2->getPosition().x - x < 61; it2++) {
				it1->detectCollision(*it2);
			}
		}

		// draw
		window.clear(sf::Color(50,255,20));
		for (const auto& ball: balls)
			window.draw(ball);
		window.display();
	}

	return 0;
}

