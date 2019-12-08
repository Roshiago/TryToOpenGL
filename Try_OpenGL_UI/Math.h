#ifndef _MATH_H
#define _MATH_H
#include <cmath>
#include <variant>

#define Type2Enum(T) std::is_same<T, float>::value ? (GL_FLOAT) : (std::is_same<T, double>::value ? GL_DOUBLE : GL_INT);

namespace math {
	using uchar = unsigned char;

	class Color {
	public:
		struct {
			uchar r, g, b, a;
		};
		Color() {
			r = 0;
			g = 0;
			b = 0;
			a = 255;
		}
		Color(int color) {
			r = color >> 3 * 8;
			g = (color << 1 * 8) >> 3 * 8;
			b = (color << 2 * 8) >> 3 * 8;
			a = (color << 3 * 8) >> 3 * 8;
		}
		Color(uchar r, uchar g, uchar b, uchar a = 255) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
		uchar* operator()() {
			return (uchar*)&r;
		}
		math::Color* operator->() {
			return this;
		}
	private:
		//uchar rgba[4];
	};

	template<typename T>
	class Point2 {
	public:
		Point2(T x, T y) {
			this->x = x;
			this->y = y;
		}
		Point2() {
			this->x = T();
			this->y = T();
		}
		Point2<T> operator+(Point2<T>& right) {
			Point2<T> temp(this->x, this->y);
			temp.x += right.x;
			temp.y += right.y;
			return temp;
		}
		Point2<T> operator-(Point2<T>& right) {
			Point2<T> temp(this->x, this->y);
			temp.x -= right.x;
			temp.y -= right.y;
			return temp;
		}
		template<typename H>
		Point2<T> operator*(H right) {
			Point2<T> temp(this->x, this->y);
			temp.x *= right;
			temp.y *= right;
			return temp;
		}
		template<typename H>
		Point2<T> operator/(H right) {
			Point2<T> temp(this->x, this->y);
			temp.x /= right;
			temp.y /= right;
			return temp;
		}
	public:
		T x;
		T y;
	};



	template<typename T>
	class Point3 {
	public:
		Point3(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Point3() {
			this->x = T();
			this->y = T();
			this->z = T();
		}
		Point3<T> operator+(Point3<T>& right) {
			Point3<T> temp(this->x, this->y, this->z);
			temp.x += right.x;
			temp.y += right.y;
			temp.z += right.z;
			return temp;
		}
		template<typename H>
		Point3<T> operator-(Point3<H>& right) {
			Point3<T> temp(this->x, this->y, this->z);
			temp.x -= right.x;
			temp.y -= right.y;
			temp.z -= right.z;
			return temp;
		}
		template<typename H>
		Point3<T> operator*(H right) {
			Point3<T> temp(this->x, this->y, this->z);
			temp.x *= right;
			temp.y *= right;
			temp.z *= right;
			return temp;
		}
		template<typename H>
		Point3<T> operator/(H right) {
			Point3<T> temp(this->x, this->y, this->z);
			temp.x /= right;
			temp.y /= right;
			temp.z /= right;
			return temp;
		}
	public:
		T x;
		T y;
		T z;
	};

	template<typename T>
	class Point4 {
	public:
		Point4(T x, T y, T z, T w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		Point4() {
			this->x = T();
			this->y = T();
			this->z = T();
			this->w = T();
		}
		Point4<T> operator+(Point4<T>& right) {
			Point4<T> temp(this->x, this->y, this->z, this->w);
			temp.x += right.x;
			temp.y += right.y;
			temp.z += right.z;
			temp.w += right.w;
			return temp;
		}
		Point4<T> operator-(Point4<T>& right) {
			Point4<T> temp(this->x, this->y, this->z);
			temp.x -= right.x;
			temp.y -= right.y;
			temp.z -= right.z;
			temp.w -= right.w;
			return temp;
		}
		template<typename H>
		Point4<T> operator*(H right) {
			Point4<T> temp(this->x, this->y, this->z);
			temp.x *= right;
			temp.y *= right;
			temp.z *= right;
			temp.w *= right;
			return temp;
		}
		template<typename H>
		Point4<T> operator/(H right) {
			Point4<T> temp(this->x, this->y, this->z);
			temp.x /= right;
			temp.y /= right;
			temp.z /= right;
			temp.w /= right;
			return temp;
		}
	public:
		T x;
		T y;
		T z;
		T w;
	};

	template<typename T, typename H>
	Point2<T> cast(Point2<H>& vector) {
		if (std::is_same<T, H>::value_type) {
			return vector;
		}
		T x = static_cast<T>(vector.x);
		T y = static_cast<T>(vector.y);
		return Point2<T>(x, y);
	}

	template<typename T, typename H>
	Point3<T> cast(Point3<H>& vector) {
		if (std::is_same<T, H>::value_type) {
			return vector;
		}
		T x = static_cast<T>(vector.x);
		T y = static_cast<T>(vector.y);
		T z = static_cast<T>(vector.z);
		return Point3<T>(x, y, z);
	}

	template<typename T, typename H>
	Point4<T> cast(Point4<H>& vector) {
		if (std::is_same<T, H>::value_type) {
			return vector;
		}
		T x = static_cast<T>(vector.x);
		T y = static_cast<T>(vector.y);
		T z = static_cast<T>(vector.z);
		T w = static_cast<T>(vector.w);
		return Point4<T>(x, y, z, w);
	}
}

#endif // !_MATH_H

