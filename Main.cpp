#include "DxLib.h"
#include <math.h>
#include "Source/ObjectFile/TargetObject.h"
#include "Source/ObjectFile/ObjectBase.h"
#include "Source/ObjectFile/ModelManager.h"
#include "Source/ObjectFile/Barrel.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	ObjectBase* tage = new TargetObject(ObjectBase::ObjectType::Test,VGet(1,0,0));
	ObjectBase* barrel = new Barrel(ObjectBase::Barrel,VGet(100,0,0));

	SetDrawScreen(DX_SCREEN_BACK);
	SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetGraphMode(200, 200, 64);
	SetCameraNearFar(0, 1000);
	SetCameraPositionAndTargetAndUpVec(VGet(0, 0, 0),tage->Pos,VGet(0,1,0));
	ModelManager::Instance()->LoadModel(Scene::SceneKind::Test);
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
		tage->Update();
		SetCameraPositionAndTargetAndUpVec(VGet(0, 0, 0), tage->Pos, VGet(0, 1, 0));
		barrel->Draw(ModelManager::Instance()->SetModelData(barrel->Type));

		ScreenFlip();
		ClearDrawScreen();
		int test = DrawSphere3D(VGet(10, 0, 0), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

	
		//tage->Draw(ModelManager::Instance()->SetModelData(tage->Type));
		
	}
	
	
	WaitKey();				// �L�[���͑҂�
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
