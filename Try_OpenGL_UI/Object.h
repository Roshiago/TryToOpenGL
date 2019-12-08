#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "GLFW_Structure.h"
#include "Math.h"
#include <vector>
#include "PropertyContainer.h"

template<typename T>
class Object
{
public:
	Object(): Color(this,&Object::SetColor,&Object::GetColor),
			  Rotate(this, &Object::SetRotate, &Object::GetRotate),
			  IndexLayer(this, &Object::SetIndexLayer, &Object::GetIndexLayer){
		type = Type2Enum(T);
		indexLayer = 0;
		rotate = 0;
		color = 0;
	}
	Object(GLenum type, int indexLayer, float rotate, math::Color color) {
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
	Property<Object, math::Color> Color;
	Property<Object, float> Rotate;
	Property<Object, int> IndexLayer;

	virtual void Move() {};
	virtual void ApplyRotate() {};
	virtual const std::vector<T> data() { return std::vector<T>(); }
protected:
	GLenum type;
	int indexLayer;
	float rotate;
	math::Color color;
};


#endif // !_OBJECT_H_


