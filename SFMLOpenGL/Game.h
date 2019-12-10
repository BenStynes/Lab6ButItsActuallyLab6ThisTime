#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;
enum class Shape
{
	triangle,
	point,
	lines,
	line_strips,
	triangle_strips,
	quads,
	quad_strips,
	polygon,
	line_loop,
	triangle_fan
};
class Game
{
public:
	Game();
	~Game();
	void run();
	
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	Shape yeet; 
	bool roatating{ false };
	// // Uncomment for Part 2
	// // ********************
	 const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
	// // ********************
};