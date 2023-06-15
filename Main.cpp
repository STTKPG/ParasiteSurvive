#include "DxLib.h"
#include <math.h>
#include "Source/ObjectFile/TargetObject.h"
#include "Source/ObjectFile/ObjectBase.h"
#include "Source/ObjectFile/ModelManager.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	TargetObject* tage = new TargetObject(ObjectBase::ObjectType::Test);


	SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(200, 200, 64);
	SetCameraNearFar(0, 1000);
	ChangeLightTypeDir(VGet(0, 0, -1));
	SetCameraPositionAndTargetAndUpVec(VGet(0, 0, 0), tage->Pos, VGet(0, 1, 0));
	ModelManager::Instance()->LoadModel(Scene::SceneKind::Test);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{

		//// 左右キーでカメラの回転値を変更
		//if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		//{
		//	Roll -= DX_PI_F / 60.0f;
		//}
		//if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		//{
		//	Roll += DX_PI_F / 60.0f;
		//}
		tage->Update();

		
		ClearDrawScreen();
		ScreenFlip();

		tage->Draw(ModelManager::Instance()->SetModelData(tage->Type));
	}
	
	
	WaitKey();				// キー入力待ち
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
