#ifndef _LINE_H_
#define _LINE_H_

#include "GLEW_Structure.h"
#include "GLFW_Structure.h"

#include "Object.h"

namespace primitives {
	template<typename T>
	class Line : public Object<T>
	{
	public:
		Line(math::Point3<T> s, math::Point3<T> e) {
			this->start = s;
			this->end = e;
			this->Center = math::Point3<T>({start.x+end.x, start.y + end.y, start.z + end.z}) / 2.0;
		}
		void ApplyRotate() {
			math::Point3<T> center = this->Center;
			glTranslatef(center.x, center.y, center.z);//tranlate by p where p is the point you want to rotate about
			glRotatef(this->Rotate, 0, 0, 1);//rotate by some degrees
			glTranslatef(-center.x, -center.y, -center.z);//tranlate back by -p
		}

		void Move(math::Point3<T> to) {
			math::Point3<T> center = this->Center;
			math::Point3<T> delta = to - center;
			start = start + delta;
			end = end + delta;
			this->Center = to;
		}

		std::vector<T> GetData() {
			return {
				start.x, start.y, start.z,
				end.x, end.y, end.z,
			};
		}

	private:
		math::Point3<T> start, end;
	};
}

#endif // !_LINE_H_



