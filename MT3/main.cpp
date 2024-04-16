#include <Novice.h>
#include "Math/Math.h"

const char kWindowTitle[] = "GC1B_01_イイヅカ_ソラ_title";

static const int kColumnWidth = 60;
static const int kRowHeight   = 30;

void VectorScreenPrintf(int x, int y, MyVector3 vector, const char* label) {
	vector = MyVector3(vector);
	Novice::ScreenPrintf(x, y, "%.02f", vector.GetX());
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.GetY());
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.GetZ());
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Function* function = new Function;

	MyVector3 v1({ 1.0f,3.0f,-5.0f });
	MyVector3 v2({ 4.0f,-1.0f,2.0f });
	MyVector3 resultAdd      = MyVector3();
	MyVector3 resultSubtract = MyVector3();
	MyVector3 resultMultiply = MyVector3();
	float resultDot    = 0;
	float resultLength = 0;
	MyVector3 resultNormalize = MyVector3();
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
		resultAdd      = function->Add(v1, v2);
		resultSubtract = function->Subtract(v1, v2);
		resultMultiply = function->Multiply(v1);
		resultDot      = function->Dot(v1, v2);
		resultLength   = function->Length(v1);
		resultNormalize = function->Normalize(v2);
		///
		/// ↑更新処理ここまで
		///
		VectorScreenPrintf(0, 0, resultAdd, " :Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, " :Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, " :Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f : Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, " :Normalize");
		///
		/// ↓描画処理ここから
		///

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

	delete function;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
