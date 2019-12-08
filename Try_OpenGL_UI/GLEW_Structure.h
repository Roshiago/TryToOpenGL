#ifndef _GLEW_STRUCTURE_HEADER_
#define _GLEW_STRUCTURE_HEADER_

#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>

namespace GLEW
{
	static bool InitGLEW()
	{
		glewExperimental = true;
		GLenum err = glewInit();
		if (err != GLEW_OK)
		{
			fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
			return false;
		}

		return true;
	};
}


#endif // !_GLEW_STRUCTURE_HEADER_
