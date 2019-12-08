#pragma once
#ifndef _RENDERE_H_

#include "Math.h"

//---------------
#include "Triangle.h"
#include "Line.h"
//---------------

#include "GLEW_Structure.h"
#include "GLFW_Structure.h"

#include <iostream>

using namespace math;

#define RP RendererPrimitives::GetHandle()

class RendererPrimitives
{
private:
	RendererPrimitives() {

	}
public:
	static RendererPrimitives& GetHandle() {
		static RendererPrimitives handle;
		return handle;
	}

	template<typename T>
	void DrawPoint(Point2<T> point) {
		glEnableClientState(GL_VERTEX_ARRAY);
		GLfloat position[] = {
			point.x, point.y, 0
		};
		glPointSize(5.0f);
		glVertexPointer(3, GL_FLOAT, 0, position);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	template<typename T>
	void DrawLine(Point2<T> start, Point2<T> end) {
		GLfloat line[] = {
			start.x, start.y, 0,
			end.x, end.y, 0
		};
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, line);
		glDrawArrays(GL_LINES, 0, 2);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	template<typename T>
	void DrawTriangle(Point2<T> vec1, Point2<T> vec2, Point2<T> vec3) {
		glEnableClientState(GL_VERTEX_ARRAY);
		GLfloat line[] = {
			vec1.x, vec1.y, 0,
			vec2.x, vec2.y, 0,
			vec2.x, vec2.y, 0,
			vec3.x, vec3.y, 0,
			vec3.x, vec3.y, 0,
			vec1.x, vec1.y, 0
		};
		glVertexPointer(3, GL_FLOAT, 0, line);
		glDrawArrays(GL_LINES, 0, 6);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	template<typename T>
	void DrawTriangle(primitives::Triangle<T> t) {
		glEnableClientState(GL_VERTEX_ARRAY);
		std::vector<T> data = t.getData();
		GLenum type = Type2Enum(T);
		glPushMatrix();
		t.Rotate();
		if (t.IsFill()) {
			glVertexPointer(3, type, 0, data.data());
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		else {
			glVertexPointer(3, type, 0, data.data());
			glDrawArrays(GL_LINES, 0, 6);
		}
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	template<typename T>
	void DrawLine(primitives::Line<T> t) {
		glEnableClientState(GL_VERTEX_ARRAY);
		GLenum type = Type2Enum(T);
		std::vector<T> data = t.getData();
		glPushMatrix();
		t.Rotate();
		glVertexPointer(3, type, 0, data.data());
		glDrawArrays(GL_LINES, 0, 2);
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	
};


#endif // !_RENDERE_H_


