#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if(event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Num1:
					yeet = Shape::point;
					break;

				case sf::Keyboard::Num2:
					yeet = Shape::lines;
					break;
				case sf::Keyboard::Num3:
					yeet = Shape::line_strips;
					break;
				case sf::Keyboard::Num4:
					yeet = Shape::quads;
					break;
				case sf::Keyboard::Num5:
					yeet = Shape::quad_strips;
					break;;
				case sf::Keyboard::Num6:
					yeet = Shape::polygon;
					break;
				case sf::Keyboard::Num7:
					yeet = Shape::triangle_strips;
					break;
				case sf::Keyboard::Num8:
					yeet = Shape::triangle_fan;
					break;
				case sf::Keyboard::Num9:
					yeet = Shape::line_loop;
					break;
				case sf::Keyboard::Num0:
					yeet = Shape::triangle;
					break;


				}
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	switch (yeet)
	{
	case Shape::triangle:

		glBegin(GL_TRIANGLES); { 

			glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(0.1, 0.5, 0.21);

		glVertex3f(2.0, -2.0, -5.0);
		glColor3f(0.1, 0.5, 0.21);
		}
		glEnd();
		break;
	case Shape::point:
		glPointSize(5.0f);

		glBegin(GL_POINTS); {

			glVertex3f(0.0, 2.0, -5.0);
			glColor3f(0.1, 0.5, 0.21);

			glVertex3f(-2.0, -2.0, -5.0);
			glColor3f(0.1, 0.5, 0.21);

			glVertex3f(2.0, -2.0, -5.0); }
		glEnd();
		break;
	case Shape::lines:

		glBegin(GL_LINES); {

			glVertex3f(0.0, 2.0, -5.0);
			glColor3f(0, 1, 0);

			glVertex3f(-2.0, -2.0, -5.0);
			glColor3f(1, 0, 1);

			glVertex3f(2.0, -2.0, -5.0);
			glColor3f(1, 1, 0);
		}
		glEnd();
		break;
	case Shape::line_strips:

		glBegin(GL_LINE_STRIP); {

			glVertex3f(0.0, 2.0, -5.0);
			glColor3f(0, 1, 0);

			glVertex3f(-2.0, -2.0, -5.0);
			glColor3f(1, 1, 0);

			glVertex3f(2.0, -2.0, -5.0);
			glColor3f(1, 0, 1);
		}
		glEnd();
		break;
	case Shape::triangle_strips:

		glBegin(GL_TRIANGLE_STRIP); {

			glVertex3f(0.0, -2.0, -9.0);
			glColor3f(1, 0, 0);

			glVertex3f(-2.0, -3.0, -9.0);
			glColor3f(0, 1, 0);

			glVertex3f(2.0, -2.0, -9.0);
			glColor3f(1, 0, 1);

			glVertex3f(-2.0, 3.0, -9.0);
			glColor3f(1, 1, 0);

	}
	
		glEnd();
		break;
	case Shape::quads:

		glBegin(GL_QUADS); {

			glVertex3f(-2.0, 2.0, -5.0);
			glColor3f(1, 0, 0);

			glVertex3f(-2.0, -2.0, -5.0);
			glColor3f(0, 1, 0);

			glVertex3f(2.0, -2.0, -5.0);
			glColor3f(1, 0, 1);

			glVertex3f(2.0, 2.0, -5.0);
			glColor3f(1, 1, 0);

		}
		glEnd();
		break;
	case Shape::quad_strips:
		glBegin(GL_QUAD_STRIP); {

			glVertex3f(-2.0, 1.0, -5.0);
			glVertex3f(-2.0, -1.0, -5.0);
			glVertex3f(2.0, -1.0, -5.0);
			glVertex3f(2.0, 1.0, -5.0);
		}
		glEnd();
		break;
	case Shape::polygon:
		break;
	case Shape::line_loop:
		break;
	case Shape::triangle_fan:
		break;
	default:
		break;
	}
	
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

