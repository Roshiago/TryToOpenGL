#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Object.h"
#include "GLEW_Structure.h"
#include "GLFW_Structure.h"
#include <vector>

namespace primitives {
	template<typename T>
	class Triangle : public Object<T>
	{
	public:
		Triangle(math::Point3<T> f, math::Point3<T> s, math::Point3<T> t):
			IsFill(this, &Triangle::SetIsFill, &Triangle::GetIsFill)
		{
			this->first = f;
			this->second = s;
			this->third = t;
			this->IsFill = true;
			this->Rotate = 0;
			this->Center = this->calcCenter();
		}

		void Move(math::Point3<T> to) {
			math::Point3<T> center = this->Center;
			math::Point3<T> delta = to - center;
			first = first + delta;
			second = second + delta;
			third = third + delta;
			this->Center = to;
		}

		std::vector<T> GetData() {
			if (this->IsFill) {
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

		bool GetIsFill() {
			return isFill;
		}
		void SetIsFill(bool filled) {
			this->isFill = filled;
		}
		Property<Triangle, bool> IsFill;

	private:
		math::Point3<T> first, second, third;
		bool isFill;
		math::Point3<T> calcCenter() {
			return math::Point3<T>(first.x + second.x + third.x,
									first.y + second.y + third.y,
									first.z + second.z + third.z) / 3.0;
		}
	};
}


#endif // !_TRIANGLE_H_


