#pragma once
#include <Matrix4x4.h>
class Math {
public:
	
	/// <summary>
	/// コンストラクター
	/// </summary>
	Math();

	/// <summary>
	/// デストラクター
	/// </summary>
	~Math();

	/// <summary>
	/// 足し算
	/// </summary>
	/// <param name="m1">マトリックス1</param>
	/// <param name="m2">マトリックス2</param>
	/// <returns>2つのマトリックスの和</returns>
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 引き算
	/// </summary>
	/// <param name="m1">マトリックス1</param>
	/// <param name="m2">マトリックス2</param>
	/// <returns>2つのマトリックスの差</returns>
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 掛け算
	/// </summary>
	/// <param name="m1">マトリックス1</param>
	/// <param name="m2">マトリックス2</param>
	/// <returns>2つのマトリックスの積</returns>
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 逆行列
	/// </summary>
	/// <param name="m">マトリックス</param>
	/// <returns>マトリックスの逆行列</returns>
	Matrix4x4 Inverse(const Matrix4x4& m);

	/// <summary>
	/// 転置行列
	/// </summary>
	/// <param name="m">マトリック</param>
	/// <returns>マトリックスの転置行列</returns>
	Matrix4x4 Transpose(const Matrix4x4& m);

	/// <summary>
	/// 単位行列
	/// </summary>
	/// <returns>単位行列</returns>
	Matrix4x4 MakeIdentity4x4();
};