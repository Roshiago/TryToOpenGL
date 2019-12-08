#include "Window.h"

Window::Window(size_t width, size_t height, const char* title) {
	this->uiHeight = height;
	this->uiWidth = width;
	this->strTitle = title;
	this->windowHandler = GLFW::GetWindow(this->uiWidth, this->uiHeight, title);
	glfwMakeContextCurrent(this->windowHandler);

	glViewport(0, 0, this->uiWidth, this->uiHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, this->uiWidth, 0, this->uiHeight, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glfwSetWindowUserPointer(this->windowHandler, (void*)this);
	this->setEventFunc();
}

void Window::setEventFunc()
{
	glfwSetKeyCallback(this->windowHandler, events::key_callback);
	glfwSetCursorPosCallback(this->windowHandler, events::cursor_position_callback);
	glfwSetMouseButtonCallback(this->windowHandler, events::mouse_button_callback);
}

inline bool Window::IsTerminate() {
	return GLFW::CanTerminate(this->windowHandler);
}

void Window::MainLoop()
{
	Point3<GLfloat> start = { 200.0f, 100.0f, 0.0f };
	Point3<GLfloat> end = { 100.0f, 300.0f, 0.0f };

	primitives::Line<GLfloat> line(start, end);

	Point3<GLfloat> first = { 200.0f, 100.0f, 0.0f };
	Point3<GLfloat> second = { 200.0f, 200.0f, 0.0f };
	Point3<GLfloat> third = { 300.0f, 100.0f, 0.0f };

	primitives::Triangle<GLfloat> triangle(first, second, third);

	triangle.setIsFill(false);

	double prevTime = 0.0;

	math::Color color(0xFF000000);
	std::cout << sizeof(math::Color) << std::endl;
	while (this->IsTerminate())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		double currTime = glfwGetTime();
		triangle.Move(Point3(cursorPos.x, cursorPos.y, 0.0f));
		RP.DrawTriangle(triangle);
		RP.DrawLine(line);
		deltaTime = currTime - prevTime;
		prevTime = currTime;
		/*GLfloat r = line.getRotate();
		r += 20.0f * deltaTime;
		line.setRotate(r);*/

		auto cT = triangle.getCenter(), cL = line.getCenter();

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
		glColor4ubv(color());
		RP.DrawPoint(math::Point2(cT.x,cT.y));
		glPopAttrib();

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
		glColor4ubv(color());
		RP.DrawPoint(math::Point2(cL.x, cL.y));
		glPopAttrib();

		double fps = 1.0 / deltaTime;
		std::cout << fps << std::endl;

		glfwSwapBuffers(this->windowHandler);
		glfwPollEvents();
	}
}

size_t Window::GetHeight()
{
	return this->uiHeight;
}

size_t Window::GetWidth()
{
	return this->uiWidth;
}

void Window::SetTitle(const char* title) {
	glfwSetWindowTitle(this->windowHandler, title);
	this->strTitle = title;
}

void Window::SetCursorPos(Point2<GLfloat> pos)
{
	cursorPos = pos;
}

Window::~Window() {
	GLFW::Terminate(this->windowHandler);
}

void events::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* current_window = GLFW::getUserPointer<Window>(window);
	if (key == 'T' && action == GLFW_PRESS) {
		current_window->SetTitle("THIS IS WORK FINE!");
	}
	else if(action == GLFW_PRESS) {
		std::cout << key << "\r\n";
	}
}

void events::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* current_window = GLFW::getUserPointer<Window>(window);
	float x = static_cast<float>(xpos);
	float y = static_cast<float>(current_window->GetHeight() - ypos);
	current_window->SetCursorPos(Point2(x, y));
}

void events::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* current_window = GLFW::getUserPointer<Window>(window);
	
}
