



#include <Game.h>


bool flip = false;
int current = 1;
  

 Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(10)
{
	 
	 index = glGenLists(primatives);

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
			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case  sf::Keyboard::A:
					glRotatef(5, 0.0f, 0.0f, 0.5f);
					break;
				case  sf::Keyboard::D:
					glRotatef(5, 0.0f, 0.0f, -0.5f);
					break;
				case sf::Keyboard::Right:
					glTranslatef(1.0f, 0.0f, 0.0f);
					break;
				case sf::Keyboard::Left:
					glTranslatef(-1.0f, 0.0f, 0.0f);
					break;

				case sf::Keyboard::Up:
					glScalef(1.0f, 1.0f, 0.5f);
					break;
				case sf::Keyboard::Down:
					glScalef(1.0f, 1.0f, 2.0f);
					break;
				case sf::Keyboard::R:
					glLoadIdentity();
					break;
				case sf::Keyboard::Space:
					current++;
					if (current > primatives)
					{
						current = 1;
					}
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

	 
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(index, GL_COMPILE);

	glBegin(GL_TRIANGLES); {

		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(0.1, 0.5, 0.21);

		glVertex3f(2.0, -2.0, -5.0);
		glColor3f(0.1, 0.5, 0.21);
	}

	
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glPointSize(5.0f);

	glBegin(GL_POINTS); {

		glVertex3f(0.0, 2.0, -5.0);
		glColor3f(0.1, 0.5, 0.21);

		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(0.1, 0.5, 0.21);

		glVertex3f(2.0, -2.0, -5.0); }

	glEnd();
	glEndList();
	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN); {

		glVertex3f(3.0, -1.0, -9.0);
		glColor3f(1, 0, 0);

		glVertex3f(1.0, 1.0, -9.0);
		glColor3f(0, 1, 0);

		glVertex3f(2.0, 2.0, -9.0);
		glColor3f(1, 0, 1);

		glVertex3f(3.0, 1.0, -9.0);
		glColor3f(1, 1, 0);
		glVertex3f(3.5, 2.0, -9.0);
	}

	glEnd();
	glEndList();
	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINES); {

		glVertex3f(0.0, 2.0, -5.0);
		glColor3f(0, 1, 0);

		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(1, 0, 1);

		glVertex3f(2.0, -2.0, -5.0);
		glColor3f(1, 1, 0);
	}

	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP); {
		glColor3f(1, 1, 1);

		glVertex3f(-3.0, -1.0, -9.0);
		glColor3f(1, 0, 0);

		glVertex3f(-2.0, 1.0, -9.0);
		glColor3f(0, 1, 0);

		glVertex3f(-1.0, -1.0, -9.0);
		glColor3f(1, 0, 1);

		glVertex3f(0.0, 1.0, -9.0);
		glColor3f(1, 1, 0);
		glVertex3f(1.0, -1.0, -9.0);
	}

	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);

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
	glEndList();

	
	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_LINE_STRIP); {

		glVertex3f(0.0, 2.0, -5.0);
		glColor3f(0, 1, 0);

		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(1, 1, 0);

		glVertex3f(2.0, -2.0, -5.0);
		glColor3f(1, 0, 1);
	}

	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);

	glBegin(GL_QUAD_STRIP); {

		glColor3f(1, 1, 1);

		glVertex3f(-2.0f, -2.0f, -5.0f);
		glColor3f(1, 1, 1);

		glVertex3f(-2.0f, 0.0f, -5.0f);
		glColor3f(1, 1, 0);

		glVertex3f(0.0f, -1.0f, -5.0f);
		glColor3f(1, 1, 1);

		glVertex3f(0.0f, 1.0f, -5.0f);
		glColor3f(1, 1, 1);

		glVertex3f(1.0f, -1.0f, -5.0f);
		glColor3f(1, 1, 1);

		glVertex3f(1.0f, 1.0f, -5.0f);

	}
	glEnd();
	glEndList();

	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_POLYGON); {

		glVertex3f(0.0, -2.0, -9.0);
		glColor3f(1, 0, 0);

		glVertex3f(-2.0, -3.0, -9.0);
		glColor3f(0, 1, 0);

		glVertex3f(2.0, -2.0, -9.0);
		glColor3f(1, 0, 1);

		glVertex3f(-2.0, 3.0, -9.0);
		glColor3f(1, 1, 0);

		glVertex3f(2.0, 3.0, -9.0);
		glColor3f(1, 1, 0);
	}

	glEnd();
	glEndList();

	
	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_LINE_LOOP); {


		glVertex3f(0.0, 2.0, -5.0);
		glColor3f(0, 1, 0);

		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(1, 0, 1);

		glVertex3f(2.0, -2.0, -5.0);
		glColor3f(1, 1, 0);
	}

	glEnd();
	glEndList();
	
}

void Game::update()
{

			
		


	cout << "Update up" << endl;
}

void Game::draw()
{

	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	

	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}