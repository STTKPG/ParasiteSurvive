#include "DxLib.h"
#include <math.h>
#include "Source/ObjectFile/TargetObject.h"
#include "Source/ObjectFile/ObjectBase.h"
#include "Source/ObjectFile/ModelManager.h"
#include "Source/ObjectFile/ObjectManager.h"
#include "Source/ObjectFile/Barrel.h"
#include "Source/Camera.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	ObjectManager::Instance()->Entry(ObjectBase::Player);
	ObjectManager::Instance()->Entry(ObjectBase::Target);
	SetMousePoint(320, 240);
	SetDrawScreen(DX_SCREEN_BACK);
	//SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetGraphMode(200, 200, 64);
	ModelManager::Instance()->LoadModel(Scene::SceneKind::Test);
	Camera camera;
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
		ObjectManager::Instance()->Update();
		//SetCameraPositionAndTargetAndUpVec(ObjectManager::Instance()->GetObjectPos(ObjectBase::Player),ObjectManager::Instance()->GetObjectPos(ObjectBase::Target), VGet(0, 1, 0));
		camera.SetPositionAndTarget(ObjectManager::Instance()->GetObjectPos(ObjectBase::Player),ObjectManager::Instance()->GetObjectPos(ObjectBase::Target));
		ScreenFlip();
		ClearDrawScreen();
		int test = DrawSphere3D(VGet(0, 0, 10), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		//DrawSphere3D(VAdd(ObjectManager::Instance()->GetObjectPos(ObjectBase::Target),VGet(0,0,10)), 1, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);

	
		//tage->Draw(ModelManager::Instance()->SetModelData(tage->Type));
		
	}
	
	
	WaitKey();				// キー入力待ち
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
