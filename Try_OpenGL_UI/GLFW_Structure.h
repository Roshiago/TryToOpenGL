#ifndef _GLFW_STRUCTURE_HEADER_
#define _GLFW_STRUCTURE_HEADER_

#include <GLFW/glfw3.h>

namespace GLFW
{
	static bool InitGLFW()
	{
		

		//init GLFW
		int err = glfwInit();

		if (err == GLFW_FALSE) {
			return false;
		}


		//required option

		/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);*/
		/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);*/

		

		return true;
	}

	static bool CanTerminate(GLFWwindow* window)
	{
		return glfwWindowShouldClose(window) == 0;
	}

	static void Terminate(GLFWwindow* window)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	template<typename T>
	static T* getUserPointer(GLFWwindow* window)
	{
		return (T*)glfwGetWindowUserPointer(window);
	}

	static GLFWwindow* GetWindow(GLint width, GLint height, const char * title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL)
	{
		return glfwCreateWindow(width, height, title, monitor, share);
	}
}



#endif // !_GLFW_STRUCTURE_HEADER_
