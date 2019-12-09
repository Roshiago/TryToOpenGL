#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Math.h"
#include "PropertyContainer.h"
#include "GLEW_Structure.h"
#include "GLFW_Structure.h"

#include <vector>

template<typename T>
class Object
{
public:
	Object(): Color(this,&Object::SetColor,&Object::GetColor),
			  Rotate(this, &Object::SetRotate, &Object::GetRotate),
			  IndexLayer(this, &Object::SetIndexLayer, &Object::GetIndexLayer),
			  Data(this, nullptr, &Object::GetData),
			  Center(this, &Object::SetCenter, &Object::GetCenter),
			  Type(this, nullptr, &Object::GetType)
	{
		type = Type2Enum(T);
		indexLayer = 0;
		rotate = 0;
		color = 0;
	}
	Object(GLenum type, int indexLayer, float rotate, math::Color color): Object() {
		this->type = type;
		this->indexLayer = indexLayer;
		this->rotate = rotate;
		this->color = color;
	}
	
	template<typename U>
	U* cast() {
		return dynamic_cast<U>(this);
	}

	void SetColor(math::Color color) {
		this->color = color;
	}
	math::Color GetColor() {
		return this->color;
	}

	void SetIndexLayer(int indexLayer) {
		this->indexLayer = indexLayer;
	}
	int GetIndexLayer() {
		return this->indexLayer;
	}

	void SetRotate(float rotate) {
		this->rotate = rotate;
	}
	float GetRotate() {
		return this->rotate;
	}

	virtual void SetCenter(math::Point3<T> center) {
		this->center = center;
	}
	virtual math::Point3<T> GetCenter() { return center; }


	virtual std::vector<T> GetData() { return std::vector<T>(); }
	virtual GLenum GetType() { return this->type; }

	Property<Object, math::Color> Color;
	Property<Object, float> Rotate;
	Property<Object, int> IndexLayer;
	Property<Object, math::Point3<T>> Center;

	Property<Object, std::vector<T>, READ_ONLY> Data;
	Property<Object, GLenum, READ_ONLY> Type;
	
	virtual void ApplyColor() 
	{
		PRINT_DEBUG("COLOR SET");
		math::Color color = this->Color;
		glColor4ubv(color());
		GLFW::print_error();
		PRINT_DEBUG("END COLOR SET");
	};
	virtual void Move(math::Point3<T> point) {};
	virtual void ApplyRotate() 
	{
		math::Point3<T> center = this->GetCenter();
		glTranslatef(center.x, center.y, center.z);//tranlate by p where p is the point you want to rotate about
		glRotatef(this->Rotate, 0, 0, 1);//rotate by some degrees
		glTranslatef(-center.x, -center.y, -center.z);//tranlate back by -p
	};
	
private:
	math::Point3<T> center;
	GLenum type;
	int indexLayer;
	float rotate;
	math::Color color;
};


#endif // !_OBJECT_H_