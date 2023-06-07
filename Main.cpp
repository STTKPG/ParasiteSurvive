#include "DxLib.h"
#include <math.h>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
		int x;
		int y;
		int bit;

	int Hundle = MV1LoadModel("ModelData/Floor_Standard.mv1");
	SetDrawScreen(DX_SCREEN_BACK);
	float Roll = 0.0f;
	SetGraphMode(200, 200, 64);
	SetCameraNearFar(0, 1000);
	SetCameraPositionAndTargetAndUpVec(VGet(0, 0, -500), VGet(0, 0, 0), VGet(0, 0, 0));
	MV1SetPosition(Hundle, VGet(0, 0, 0));
	GetScreenState(&x,&y,&bit);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// 左右キーでカメラの回転値を変更
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Roll -= DX_PI_F / 60.0f;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Roll += DX_PI_F / 60.0f;
		}
		SetMousePoint(x / 2, y / 2);
		SetCameraPositionAndTargetAndUpVec(VGet(0, 500, 1), VGet(0, 0, 0), VGet(0, 1, 0));
		ClearDrawScreen();
		MV1DrawModel(Hundle);
		ScreenFlip();
	}
	
	
	WaitKey();				// キー入力待ち
	MV1DeleteModel(Hundle);
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
