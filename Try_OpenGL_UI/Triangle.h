#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Math.h"
#include "GLEW_Structure.h"
#include "GLFW_Structure.h"
#include <vector>

namespace primitives {
	template<typename T>
	class Triangle
	{
	public:
		Triangle(math::Point3<T> f, math::Point3<T> s, math::Point3<T> t) {
			this->first = f;
			this->second = s;
			this->third = t;
			this->isFill = true;
			this->rotateDegree = 50;
		}

		void Rotate() {
			math::Point3<T> center = this->getCenter();
			glTranslatef(center.x, center.y, center.z);//tranlate by p where p is the point you want to rotate about
			glRotatef(rotateDegree, 0, 0, 1);//rotate by some degrees
			glTranslatef(-center.x, -center.y, -center.z);//tranlate back by -p
		}

		void Move(math::Point3<T> to) {
			math::Point3<T> center = this->getCenter();
			math::Point3<T> delta;
			delta = to - center;
			first = first + delta;
			second = second + delta;
			third = third + delta;
		}

		math::Point3<T> getCenter() {
			return math::Point3<T>(first.x + second.x + third.x, first.y + second.y + third.y, first.z + second.z + third.z) / 3.0;
		}
		std::vector<T> getData() {
			if (this->isFill) {
				return {
					first.x, first.y, first.z,
					second.x, second.y, second.z,
					third.x, third.y, third.z
				};
			}
			else {
				return {
					first.x, first.y, first.z,
					second.x, second.y, second.z,
					second.x, second.y, second.z,
					third.x, third.y, third.z,
					third.x, third.y, third.z,
					first.x, first.y, first.z
				};
			}
		}
		bool IsFill() {
			return isFill;
		}
		void setIsFill(bool filled) {
			this->isFill = filled;
		}

		T getRotate() {
			return rotateDegree;
		}

		void setRotate(T degree) {
			rotateDegree = degree;
		}
	private:
		math::Point3<T> first, second, third;
		bool isFill;
		T rotateDegree;
	};
}


#endif // !_TRIANGLE_H_


