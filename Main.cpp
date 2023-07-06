#include "DxLib.h"
#include <math.h>
#include "Source/ObjectFile/TargetObject.h"
#include "Source/ObjectFile/ObjectBase.h"
#include "Source/ObjectFile/ModelManager.h"
#include "Source/ObjectFile/ObjectManager.h"
#include "Source/ObjectFile/Barrel.h"
#include "Source/Camera.h"
#include "Source/InputFile/Mouse.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	ObjectManager::Instance()->Entry(ObjectBase::Player,Vector(0,-200,0));
	ObjectManager::Instance()->Entry(ObjectBase::Target,Vector(0,0,0));
	int handle = MV1LoadModel("ModelData/Floor_Standard.mv1");

	int handleW = MV1LoadModel("ModelData/Wall.mv1");

	int handleA = MV1LoadModel("ModelData/Revolver1.mv1");
	SetMousePoint(320, 240);
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetGraphMode(200, 200, 64);
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
		ObjectManager::Instance()->Update();
		//SetCameraPositionAndTargetAndUpVec(ObjectManager::Instance()->GetObjectPos(ObjectBase::Player),ObjectManager::Instance()->GetObjectPos(ObjectBase::Target), VGet(0, 1, 0));
		//camera.SetPositionAndTarget(ObjectManager::Instance()->GetObjectPos(ObjectBase::Player),ObjectManager::Instance()->GetObjectPos(ObjectBase::Target));
		ScreenFlip();
		ClearDrawScreen();
		//int test = DrawSphere3D(VGet(0, 0, 10), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		//DrawSphere3D(VGet(0, 0, -10), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
	    //DrawCone3D(VGet(0,-10,10), VGet(0,10,10), 5, 16, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(0, 10, 0), 5, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(10, 0, 0), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(-10, 0, 0), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(0, -10, 0), 5, 32, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(0, 0, 10), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(0, 0, -10), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

		//DrawLine3D(VGet(0, 0, 0), VGet(0, -200, 0), GetColor(255, 0, 0));

		DrawLine3D(VGet(0, 0, 0), VGet(0, 0,100), GetColor(255, 0, 0));
		MV1SetPosition(handle,VGet(0,0,0));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(200, 0, 0));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(0, 0, 200));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(0, 0, -200));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(-200, 0, 0));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(200, 0, 200));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(200, 0, -200));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(-200, 0, 200));
		MV1DrawModel(handle);
		MV1SetPosition(handle, VGet(-200, 0, -200));
		MV1DrawModel(handle);

		MV1SetPosition(handleW, VGet(0, -600, 0));
		MV1DrawModel(handleW);
		MV1SetPosition(handleA, VGet(20, -200, 0));
		MV1SetRotationXYZ(handleA, VGet(DX_PI, 0, 0));
		MV1SetScale(handleA, VGet(0.5f, 0.5f, 0.5f));
		MV1DrawModel(handleA);
		DrawLine3D(VGet(0, -400, 0), VGet(0, -800, 0), GetColor(255, 0, 0));

		//DrawSphere3D(VAdd(ObjectManager::Instance()->GetObjectPos(ObjectBase::Target),VGet(0,0,10)), 1, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);

	
		//tage->Draw(ModelManager::Instance()->SetModelData(tage->Type));
		
	}
	
	
	WaitKey();				// キー入力待ち
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
