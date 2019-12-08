#ifndef _LINE_H_
#define _LINE_H_

#include "Math.h"
#include "GLEW_Structure.h"
#include "GLFW_Structure.h"
#include <vector>

namespace primitives {
	template<typename T>
	class Line
	{
	public:
		Line(math::Point3<T> s, math::Point3<T> e) {
			this->start = s;
			this->end = e;
			this->rotateDegree = 2;
		}
		void Rotate() {
			math::Point3<T> center = this->getCenter();
			glTranslatef(center.x, center.y, center.z);//tranlate by p where p is the point you want to rotate about
			glRotatef(rotateDegree, 0, 0, 1);//rotate by some degrees
			glTranslatef(-center.x, -center.y, -center.z);//tranlate back by -p
		}

		math::Point3<T> getCenter() {
			return math::Point3<T>((start.x + end.x) / 2, (start.y + end.y) / 2, (start.z + end.z) / 2);
		}

		std::vector<T> getData() {
			return {
				start.x, start.y, start.z,
				end.x, end.y, end.z,
			};
		}

		T getRotate() {
			return rotateDegree;
		}

		void setRotate(T degree) {
			rotateDegree = degree;
		}

	private:
		math::Point3<T> start, end;
		T rotateDegree;
	};
}

#endif // !_LINE_H_



