#include "Math.h"
#include <cassert>


//コンストラクター
Math::Math(){

}

//デストラクター
Math::~Math() {

}

//加算
Matrix4x4 Math::Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	return result;
}

//減算
Matrix4x4 Math::Subtract(const Matrix4x4& m1, const Matrix4x4& m2)
{
	Matrix4x4 result = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];
		}
	}
	return result;
}

//掛け算
Matrix4x4 Math::Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return result;
}

//逆行列
Matrix4x4 Math::Inverse(const Matrix4x4& m)
{
	Matrix4x4 result{};
	float determinant = m.m[0][0] * (m.m[1][1] * m.m[2][2] * m.m[3][3] +
		m.m[2][1] * m.m[3][2] * m.m[1][3] +
		m.m[3][1] * m.m[1][2] * m.m[2][3] -
		m.m[3][1] * m.m[2][2] * m.m[1][3] -
		m.m[2][1] * m.m[1][2] * m.m[3][3] -
		m.m[1][1] * m.m[3][2] * m.m[2][3]) -
		m.m[0][1] * (m.m[1][0] * m.m[2][2] * m.m[3][3] +
			m.m[2][0] * m.m[3][2] * m.m[1][3] +
			m.m[3][0] * m.m[1][2] * m.m[2][3] -
			m.m[3][0] * m.m[2][2] * m.m[1][3] -
			m.m[2][0] * m.m[1][2] * m.m[3][3] -
			m.m[1][0] * m.m[3][2] * m.m[2][3]) +
		m.m[0][2] * (m.m[1][0] * m.m[2][1] * m.m[3][3] +
			m.m[2][0] * m.m[3][1] * m.m[1][3] +
			m.m[3][0] * m.m[1][1] * m.m[2][3] -
			m.m[3][0] * m.m[2][1] * m.m[1][3] -
			m.m[2][0] * m.m[1][1] * m.m[3][3] -
			m.m[1][0] * m.m[3][1] * m.m[2][3]) -
		m.m[0][3] * (m.m[1][0] * m.m[2][1] * m.m[3][2] +
			m.m[2][0] * m.m[3][1] * m.m[1][2] +
			m.m[3][0] * m.m[1][1] * m.m[2][2] -
			m.m[3][0] * m.m[2][1] * m.m[1][2] -
			m.m[2][0] * m.m[1][1] * m.m[3][2] -
			m.m[1][0] * m.m[3][1] * m.m[2][2]);



	if (determinant != 0) {
		result.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3] +
			m.m[2][1] * m.m[3][2] * m.m[1][3] +
			m.m[3][1] * m.m[1][2] * m.m[2][3] -
			m.m[3][1] * m.m[2][2] * m.m[1][3] -
			m.m[2][1] * m.m[1][2] * m.m[3][3] -
			m.m[1][1] * m.m[3][2] * m.m[2][3]) /
			determinant;

		result.m[0][1] = -(m.m[0][1] * m.m[2][2] * m.m[3][3] +
			m.m[2][1] * m.m[3][2] * m.m[0][3] +
			m.m[3][1] * m.m[0][2] * m.m[2][3] -
			m.m[3][1] * m.m[2][2] * m.m[0][3] -
			m.m[2][1] * m.m[0][2] * m.m[3][3] -
			m.m[0][1] * m.m[3][2] * m.m[2][3]) /
			determinant;

		result.m[0][2] = (m.m[0][1] * m.m[1][2] * m.m[3][3] +
			m.m[1][1] * m.m[3][2] * m.m[0][3] +
			m.m[3][1] * m.m[0][2] * m.m[1][3] -
			m.m[3][1] * m.m[1][2] * m.m[0][3] -
			m.m[1][1] * m.m[0][2] * m.m[3][3] -
			m.m[0][1] * m.m[3][2] * m.m[1][3]) /
			determinant;

		result.m[0][3] = -(m.m[0][1] * m.m[1][2] * m.m[2][3] +
			m.m[1][1] * m.m[2][2] * m.m[0][3] +
			m.m[2][1] * m.m[0][2] * m.m[1][3] -
			m.m[2][1] * m.m[1][2] * m.m[0][3] -
			m.m[1][1] * m.m[0][2] * m.m[2][3] -
			m.m[0][1] * m.m[2][2] * m.m[1][3]) /
			determinant;


		result.m[1][0] = -(m.m[1][0] * m.m[2][2] * m.m[3][3] +
			m.m[2][0] * m.m[3][2] * m.m[1][3] +
			m.m[3][0] * m.m[1][2] * m.m[2][3] -
			m.m[3][0] * m.m[2][2] * m.m[1][3] -
			m.m[2][0] * m.m[1][2] * m.m[3][3] -
			m.m[1][0] * m.m[3][2] * m.m[2][3]) /
			determinant;

		result.m[1][1] = (m.m[0][0] * m.m[2][2] * m.m[3][3] +
			m.m[2][0] * m.m[3][2] * m.m[0][3] +
			m.m[3][0] * m.m[0][2] * m.m[2][3] -
			m.m[3][0] * m.m[2][2] * m.m[0][3] -
			m.m[2][0] * m.m[0][2] * m.m[3][3] -
			m.m[0][0] * m.m[3][2] * m.m[2][3]) /
			determinant;

		result.m[1][2] = -(m.m[0][0] * m.m[1][2] * m.m[3][3] +
			m.m[1][0] * m.m[3][2] * m.m[0][3] +
			m.m[3][0] * m.m[0][2] * m.m[1][3] -
			m.m[3][0] * m.m[1][2] * m.m[0][3] -
			m.m[1][0] * m.m[0][2] * m.m[3][3] -
			m.m[0][0] * m.m[3][2] * m.m[1][3]) /
			determinant;

		result.m[1][3] = (m.m[0][0] * m.m[1][2] * m.m[2][3] +
			m.m[1][0] * m.m[2][2] * m.m[0][3] +
			m.m[2][0] * m.m[0][2] * m.m[1][3] -
			m.m[2][0] * m.m[1][2] * m.m[0][3] -
			m.m[1][0] * m.m[0][2] * m.m[2][3] -
			m.m[0][0] * m.m[2][2] * m.m[1][3]) /
			determinant;


		result.m[2][0] = (m.m[1][0] * m.m[2][1] * m.m[3][3] +
			m.m[2][0] * m.m[3][1] * m.m[1][3] +
			m.m[3][0] * m.m[1][1] * m.m[2][3] -
			m.m[3][0] * m.m[2][1] * m.m[1][3] -
			m.m[2][0] * m.m[1][1] * m.m[3][3] -
			m.m[1][0] * m.m[3][1] * m.m[2][3]) /
			determinant;

		result.m[2][1] = -(m.m[0][0] * m.m[2][1] * m.m[3][3] +
			m.m[2][0] * m.m[3][1] * m.m[0][3] +
			m.m[3][0] * m.m[0][1] * m.m[2][3] -
			m.m[3][0] * m.m[2][1] * m.m[0][3] -
			m.m[2][0] * m.m[0][1] * m.m[3][3] -
			m.m[0][0] * m.m[3][1] * m.m[2][3]) /
			determinant;

		result.m[2][2] = (m.m[0][0] * m.m[1][1] * m.m[3][3] +
			m.m[1][0] * m.m[3][1] * m.m[0][3] +
			m.m[3][0] * m.m[0][1] * m.m[1][3] -
			m.m[3][0] * m.m[1][1] * m.m[0][3] -
			m.m[1][0] * m.m[0][1] * m.m[3][3] -
			m.m[0][0] * m.m[3][1] * m.m[1][3]) /
			determinant;

		result.m[2][3] = -(m.m[0][0] * m.m[1][1] * m.m[2][3] +
			m.m[1][0] * m.m[2][1] * m.m[0][3] +
			m.m[2][0] * m.m[0][1] * m.m[1][3] -
			m.m[2][0] * m.m[1][1] * m.m[0][3] -
			m.m[1][0] * m.m[0][1] * m.m[2][3] -
			m.m[0][0] * m.m[2][1] * m.m[1][3]) /
			determinant;

		result.m[3][0] = -(m.m[1][0] * m.m[2][1] * m.m[3][2] +
			m.m[2][0] * m.m[3][1] * m.m[1][2] +
			m.m[3][0] * m.m[1][1] * m.m[2][2] -
			m.m[3][0] * m.m[2][1] * m.m[1][2] -
			m.m[2][0] * m.m[1][1] * m.m[3][2] -
			m.m[1][0] * m.m[3][1] * m.m[2][2]) /
			determinant;

		result.m[3][1] = (m.m[0][0] * m.m[2][1] * m.m[3][2] +
			m.m[2][0] * m.m[3][1] * m.m[0][2] +
			m.m[3][0] * m.m[0][1] * m.m[2][2] -
			m.m[3][0] * m.m[2][1] * m.m[0][2] -
			m.m[2][0] * m.m[0][1] * m.m[3][2] -
			m.m[0][0] * m.m[3][1] * m.m[2][2]) /
			determinant;

		result.m[3][2] = -(m.m[0][0] * m.m[1][1] * m.m[3][2] +
			m.m[1][0] * m.m[3][1] * m.m[0][2] +
			m.m[3][0] * m.m[0][1] * m.m[1][2] -
			m.m[3][0] * m.m[1][1] * m.m[0][2] -
			m.m[1][0] * m.m[0][1] * m.m[3][2] -
			m.m[0][0] * m.m[3][1] * m.m[1][2]) /
			determinant;

		result.m[3][3] = (m.m[0][0] * m.m[1][1] * m.m[2][2] +
			m.m[1][0] * m.m[2][1] * m.m[0][2] +
			m.m[2][0] * m.m[0][1] * m.m[1][2] -
			m.m[2][0] * m.m[1][1] * m.m[0][2] -
			m.m[1][0] * m.m[0][1] * m.m[2][2] -
			m.m[0][0] * m.m[2][1] * m.m[1][2]) /
			determinant;
	}

	return result;
}

//転置行列
Matrix4x4 Math::Transpose(const Matrix4x4& m) {
	Matrix4x4 result{};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m.m[j][i];
		}
	}

	return result;
}

//単位行列
Matrix4x4 Math::MakeIdentity4x4() {
	Matrix4x4 result{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	return result;
}

//拡縮
Matrix4x4 Math::MakeScaleMatrix(const Vector3& scale)
{
	Matrix4x4 result{
		scale.x,0,0,0,
		0,scale.y,0,0,
		0,0,scale.z,0,
		0,0,0,1
	};

	return result;
}

//平行移動
Matrix4x4 Math::MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result{
		1.0f,0,0,0,
		0,1.0f,0,0,
		0,0,1.0f,0,
		translate.x,translate.y,translate.z,1.0f
	};

	return result;
}

//同次座標系で計算しデカルト座標系に変換
Vector3 Math::Transform(const Vector3& vector, const Matrix4x4& matrix)
{
	Vector3 result{};
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w  = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}