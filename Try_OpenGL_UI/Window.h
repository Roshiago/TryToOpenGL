#ifndef _WINDOW_H_

#include "Renderer.h"
#include <string>


class Window
{
public:
	Window(size_t width = 800, size_t height = 600, const char* title = "Window");

	void setEventFunc();

	bool IsTerminate();

	void MainLoop();

	size_t GetHeight();
	size_t GetWidth();

	void SetTitle(const char* title);

	void SetCursorPos(Point2<GLfloat> pos);

	~Window();
private:
	size_t uiHeight, uiWidth;
	GLFWwindow* windowHandler;
	std::string strTitle;
	float deltaTime;
	math::Point2<GLfloat> cursorPos;
};
namespace events 
{
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	//void character_callback(GLFWwindow* window, unsigned int codepoint)
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
}


#endif // !_WINDOW_H_
