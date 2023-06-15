#include "DxLib.h"
#include <math.h>
#include "Source/ObjectFile/TargetObject.h"
#include "Source/ObjectFile/ObjectBase.h"
#include "Source/ObjectFile/ModelManager.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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

		
		ClearDrawScreen();
		ScreenFlip();

		tage->Draw(ModelManager::Instance()->SetModelData(tage->Type));
	}
	
	
	WaitKey();				// �L�[���͑҂�
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
