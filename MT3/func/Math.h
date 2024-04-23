#pragma once
#include <Matrix4x4.h>
#include <Vector3.h>
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
	static Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 引き算
	/// </summary>
	/// <param name="m1">マトリックス1</param>
	/// <param name="m2">マトリックス2</param>
	/// <returns>2つのマトリックスの差</returns>
	static Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 掛け算
	/// </summary>
	/// <param name="m1">マトリックス1</param>
	/// <param name="m2">マトリックス2</param>
	/// <returns>2つのマトリックスの積</returns>
	static Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 逆行列
	/// </summary>
	/// <param name="m">マトリックス</param>
	/// <returns>マトリックスの逆行列</returns>
	static Matrix4x4 Inverse(const Matrix4x4& m);

	/// <summary>
	/// 転置行列
	/// </summary>
	/// <param name="m">マトリック</param>
	/// <returns>マトリックスの転置行列</returns>
	static Matrix4x4 Transpose(const Matrix4x4& m);

	/// <summary>
	/// 単位行列
	/// </summary>
	/// <returns>単位行列</returns>
	static Matrix4x4 MakeIdentity4x4();

	/// <summary>
	/// 拡大縮小
	/// </summary>
	/// <param name="scale">スケール</param>
	/// <returns>スケールのマトリックス</returns>
	static Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	/// <summary>
	/// 平行移動
	/// </summary>
	/// <param name="translate">トランスレイト</param>
	/// <returns>トランスレイトのマトリックス</returns>
	static Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

	/// <summary>
	/// 同次座標系で計算し、デカルト座標系で返す
	/// </summary>
	/// <param name="vector">ベクトル</param>
	/// <param name="matrix">マトリックス</param>
	/// <returns>デカルト座標系</returns>
	static Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

	/// <summary>
	/// x座標を軸に回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>x座標を軸の回転</returns>
	static Matrix4x4 MakeRotateXMatrix(float radian);

	/// <summary>
	/// y座標を軸に回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>y座標を軸の回転</returns>
	static Matrix4x4 MakeRotateYMatrix(float radian);

	/// <summary>
	/// z座標を軸に回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>z座標を軸の回転</returns>
	static Matrix4x4 MakeRotateZMatrix(float radian);

	/// <summary>
	/// x,y,z座標で回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>回転</returns>
	static Matrix4x4 MakeRotateXYZMatrix(Vector3 radian);

	static Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& radian, const Vector3& translate);
};