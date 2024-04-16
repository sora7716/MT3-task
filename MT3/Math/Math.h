#pragma once
#include "Vector3.h"
class MyVector3
{
private:
	float x, y, z;
public:
	/// <summary>
	/// デフォルトコンストラクター
	/// </summary>
	MyVector3() {
		x = 0;
		y = 0;
		z = 0;
	}

	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="num">xyzの座標</param>
	MyVector3(Vector3 num) {
		x = num.x;
		y = num.y;
		z = num.z;
	}

	/// <summary>
	/// 足し算
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	MyVector3 operator+(const MyVector3& num) {
		MyVector3 result{};
		result.x =x + num.x;
		result.y =y + num.y;
		result.z =z + num.z;
		return result;
	}

	/// <summary>
	/// 引き算
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	MyVector3 operator-(const MyVector3& num) {
		MyVector3 result{};
		result.x = x - num.x;
		result.y = y - num.y;
		result.z = z - num.z;
		return result;
	}

	/// <summary>
	/// スカラー倍
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	MyVector3 operator*(float k) {
		MyVector3 result{};
		result.x = x * k;
		result.y = y * k;
		result.z = z * k;
		return result;
	}

	/// <summary>
	/// 掛け算(ベクトル同士)
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	MyVector3 operator*(const MyVector3& num) {
		MyVector3 result{};
		result.x = x * num.x;
		result.y = y * num.y;
		result.z = z * num.z;
		return result;
	}

	/// <summary>
	/// 単位ベクトル
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	MyVector3& operator/=(float len) {
		if (len != 0.0f) {
			x /= len;
			y /= len;
			z /= len;
		}
		return *this;
	}

	/// <summary>
	/// xのゲッター
	/// </summary>
	/// <returns></returns>
	float GetX() { return x; };

	/// <summary>
	/// yのゲッター
	/// </summary>
	/// <returns></returns>
	float GetY() { return y; };

	/// <summary>
	/// zのゲッター
	/// </summary>
	/// <returns></returns>
	float GetZ() { return z; };

};

class Function:private MyVector3 {
private:
	float k;
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Function();

	/// <summary>
	/// デストラクター
	/// </summary>
	~Function();

	/// <summary>
	/// 足し算
	/// </summary>
	/// <param name="v1">ベクトル1</param>
	/// <param name="v2">ベクトル2</param>
	/// <returns></returns>
	MyVector3 Add(MyVector3 v1, MyVector3 v2);

	/// <summary>
	/// 引き算
	/// </summary>
	/// <param name="v1">ベクトル1</param>
	/// <param name="v2">ベクトル2</param>
	/// <returns></returns>
	MyVector3 Subtract(MyVector3 v1, MyVector3 v2);

	/// <summary>
	/// スカラー倍
	/// </summary>
	/// <param name="v">ベクトル</param>
	/// <returns></returns>
	MyVector3 Multiply(MyVector3 v);

	/// <summary>
	/// 内積
	/// </summary>
	/// <param name="v1">ベクトル1</param>
	/// <param name="v2">ベクトル2</param>
	/// <returns></returns>
	float Dot(MyVector3 v1, MyVector3 v2);

	/// <summary>
	///	ノルム
	/// </summary>
	/// <param name="v">ベクトル</param>
	/// <returns></returns>
	float Length(MyVector3 v);

	/// <summary>
	/// 単位ベクトル
	/// </summary>
	/// <param name="v">ベクトル</param>
	/// <returns></returns>
	MyVector3 Normalize(MyVector3 v);
};

