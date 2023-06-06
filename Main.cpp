#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int Hundle = MV1LoadModel("ModelData/Wall.mv1");
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetGraphMode(200, 200, 64);
	ChangeWindowMode(true);
	SetCameraNearFar(0, 1000);
	SetCameraPositionAndTargetAndUpVec(VGet(0, 10, 0), VGet(1, 10, 0), VGet(0, 1, 0));
	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ

	MV1SetPosition(Hundle, VGet(0, 0, 0));
	MV1DrawModel(Hundle);
	
	WaitKey();				// キー入力待ち
	MV1DeleteModel(Hundle);
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
