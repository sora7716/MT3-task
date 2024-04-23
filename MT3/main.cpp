#include <Novice.h>
#include "func/Math.h"

const char kWindowTitle[] = "GC2B_01_イイヅカ_ソラ_title";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void MatrixScreenPrintf(int x, int y, Matrix4x4 matrix,const char* type) {
	Novice::ScreenPrintf(x, y, "%s", type);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, (y + row * kRowHeight)+20, "%6.02f", matrix.m[row][column]);
		}
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Math* math = new Math;

	Matrix4x4 m1{
		3.2f,0.7f,9.6f,4.4f,
		5.5f,1.3f,7.8f,2.1f,
		6.9f,8.0f,2.6f,1.0f,
		0.5f,7.2f,5.1f,3.3f
	};
	Matrix4x4 m2{
		4.1f,6.5f,3.3f,2.2f,
		8.8f,0.6f,9.9f,7.7f,
		1.1f,5.5f,6.6f,0.0f,
		3.3f,9.9f,8.8f,2.2f
	};

	Matrix4x4 resultAdd{};
	Matrix4x4 resultSubtract{};
	Matrix4x4 resultMultiply{};
	Matrix4x4 resultInverseM1{};
	Matrix4x4 resultInverseM2{};
	Matrix4x4 resultTransposeM1{};
	Matrix4x4 resultTransposeM2{};
	Matrix4x4 resultIdentity{};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		resultAdd = math->Add(m1, m2);
		resultSubtract = math->Subtract(m1, m2);
		resultMultiply = math->Multiply(m1, m2);
		resultInverseM1 = math->Inverse(m1);
		resultInverseM2 = math->Inverse(m2);
		resultTransposeM1 = math->Transpose(m1);
		resultTransposeM2 = math->Transpose(m2);
		resultIdentity = math->MakeIdentity4x4();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		MatrixScreenPrintf(0, 0, resultAdd,"Add");
		MatrixScreenPrintf(0, kRowHeight * 5, resultSubtract,"Subtract");
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, resultMultiply,"Multiply");
		MatrixScreenPrintf(0, kRowHeight * 5 * 3, resultInverseM1,"InverseM1");
		MatrixScreenPrintf(0, kRowHeight * 5 * 4, resultInverseM2,"InverseM2");
		MatrixScreenPrintf(kColumnWidth * 5, 0, resultTransposeM1,"TransposeM1");
		MatrixScreenPrintf(kColumnWidth * 5, kRowHeight * 5, resultTransposeM2,"TransposeM2");
		MatrixScreenPrintf(kColumnWidth * 5, kRowHeight * 5 *2 , resultIdentity,"Identity");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete math;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
