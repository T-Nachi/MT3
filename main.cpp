#include <Novice.h>
#include <Matrix4x4.h>
const char kWindowTitle[] = "LD2A_08_ツクイナチ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	float kRowHight = 0.0f;
	Vector3 rotate{ 0.4f,1.43f,-0.0f };
	Matrix4x4 rotateXMatrix = Matrix4x4Ex::MakeRoatateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = Matrix4x4Ex::MakeRoatateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = Matrix4x4Ex::MakeRoatateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = Matrix4x4Ex::Multiply(rotateXMatrix, Matrix4x4Ex::Multiply(rotateYMatrix, rotateZMatrix));

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Matrix4x4Ex::MatrixScreenPrintf(0, 0, rotateXMatrix, "rotateXMatrix");
		Matrix4x4Ex::MatrixScreenPrintf(0, kRowHight * 5, rotateYMatrix, "rotateYMatrix");
		Matrix4x4Ex::MatrixScreenPrintf(0, kRowHight * 5 * 2, rotateZMatrix, "rotateZMatrix");
		Matrix4x4Ex::MatrixScreenPrintf(0, kRowHight * 5 * 3, rotateXYZMatrix, "rotateXYZMatrix");

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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
