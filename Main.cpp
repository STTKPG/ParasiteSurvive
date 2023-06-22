#include "DxLib.h"
#include <math.h>
#include "Source/ObjectFile/TargetObject.h"
#include "Source/ObjectFile/ObjectBase.h"
#include "Source/ObjectFile/ModelManager.h"
#include "Source/ObjectFile/ObjectManager.h"
#include "Source/ObjectFile/Barrel.h"
#include "Source/Camera.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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

		//// ���E�L�[�ŃJ�����̉�]�l��ύX
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
	
	
	WaitKey();				// �L�[���͑҂�
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
