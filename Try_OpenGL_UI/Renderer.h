#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

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
		PRINT_DEBUG("DRAW POINT");
		GLFW::print_error();
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
		PRINT_DEBUG("DRAW TRIANGLE");
		GLFW::print_error();
		std::vector<T> data = t.Data;
		glPushMatrix();
		glPushAttrib(GL_COLOR_BUFFER_BIT);
		t.ApplyColor();
		t.ApplyRotate();
		if (t.GetIsFill()) {
			glVertexPointer(3, t.Type, 0, data.data());
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		else {
			glVertexPointer(3, t.Type, 0, data.data());
			glDrawArrays(GL_LINES, 0, 6);
		}
		glPopAttrib();
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	template<typename T>
	void DrawLine(primitives::Line<T> t) {
		glEnableClientState(GL_VERTEX_ARRAY);
		PRINT_DEBUG("DRAW LINE");
		GLFW::print_error();
		std::vector<T> data = t.Data;
		glPushMatrix();
		glPushAttrib(GL_COLOR_BUFFER_BIT);
		t.ApplyColor();
		t.ApplyRotate();
		glVertexPointer(3, t.Type, 0, data.data());
		glDrawArrays(GL_LINES, 0, 2);
		glPopAttrib();
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	
};


#endif // !_RENDERER_H_


