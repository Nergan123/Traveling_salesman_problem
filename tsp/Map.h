#include <vector>
#include <GLFW/glfw3.h>


using namespace std;

class Map
{
private:
	vector< vector<int> > matrix;
	int size_x = 600, size_y = 600;

public:
	Map(int x, int y) {
		size_x = x;
		size_y = y;

		cout << "Map initialized" << endl;
	}
	void create_window() {
		glfwInit();
		GLFWwindow* window;

		if (!glfwInit()) {
			cout << "Init glfw error" << endl;
			glfwTerminate();
		}

		window = glfwCreateWindow(size_x, size_y, " TSP by Nergan", 0, 0);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(window);
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			drawCircle(0.0, 0.0, 0.03, 360);
			

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}

	void drawCircle(float cx, float cy, float r, int num_segments)
	{
		float theta = 3.1415926 * 2 / float(num_segments);
		float tangetial_factor = tanf(theta);

		float radial_factor = cosf(theta);

		float x = r;

		float y = 0;
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		for (int ii = 0; ii < num_segments; ii++)
		{
			glVertex2f(x + cx, y + cy);

			float tx = -y;
			float ty = x;

			x += tx * tangetial_factor;
			y += ty * tangetial_factor;

			x *= radial_factor;
			y *= radial_factor;
		}
		glEnd();
	}

};

