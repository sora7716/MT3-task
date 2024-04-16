#include "Math.h"
#include <math.h>

//コンストラクター
Function::Function()
{
	k = { 4.0f };
}

//デストラクター
Function::~Function()
{
}

//足し算
MyVector3 Function::Add(MyVector3 v1, MyVector3 v2)
{
	MyVector3 result = MyVector3();
	result = v1 + v2;
	return result;
}

//引き算
MyVector3 Function::Subtract(MyVector3 v1, MyVector3 v2) {
	MyVector3 result = MyVector3();
	result = v1 - v2;
	return result;
}

//スカラー倍
MyVector3 Function::Multiply(MyVector3 v) {
	MyVector3 result = MyVector3();
	result = v*k;
	return result;
}

//内積
float Function::Dot(MyVector3 v1, MyVector3 v2) {
	MyVector3 result = MyVector3();
	result = v1 * v2;
	float dot = result.GetX() + result.GetY() + result.GetZ();
	return dot;
}

//ノルム
float Function::Length(MyVector3 v) {
	MyVector3 result = MyVector3();
	result =v * v;
	float length = sqrtf(result.GetX() + result.GetY() + result.GetZ());
	return length;
}

//単位ベクトル
MyVector3 Function::Normalize(MyVector3 v) {
	float len = Length(v);
	v /= len;
	return v;
}