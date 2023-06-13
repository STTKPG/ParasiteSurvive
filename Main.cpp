#include "DxLib.h"
#include <math.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	int x;
	int y;	
	int bit;
	int Testx;
	int Testy;
	VECTOR TargetPos = VGet(0,0,-1);

	int Hundle = MV1LoadModel("ModelData/Wall.mv1");
	SetDrawScreen(DX_SCREEN_BACK);
	float Roll = 0.0f;
	MATRIX Horizontal = MGetIdent();
	SetGraphMode(200, 200, 64);
	SetCameraNearFar(0, 1000);
	ChangeLightTypeDir(VGet(0, 0, -1));
	SetCameraPositionAndTargetAndUpVec(VGet(0, 0, 0), VGet(0, 0, -1), VGet(0, 1, 0));
	MV1SetPosition(Hundle, VGet(0, 0, -800));
	GetScreenState(&x,&y,&bit);
	SetMousePoint(x / 2, y / 2);
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
		int a;
		GetMousePoint(&Testx, &Testy);
		float TestX = ((Testx - (x / 2)) / 10)* 1 / GetFPS();
		float TestY = Testy - (y / 2) * 1 / GetFPS();

		SetMousePoint(x / 2, y / 2);

		if (TestX != 0)
		{
			Testx = 0;
		}
		//MATRIX Vertical = MGetRotY(Testy);
	    Horizontal = MGetRotX(TestX);
		/*
		MATRIX Test3 = MGetTranslate(VTransform(VGet(0, 0, 0), Test));
		MATRIX Test2 = MInverse(Test3);
		TargetPos = VAdd(VScale(VTransform(VGet(0, 0, 1) , MMult(Test , Test2)), 0.1),TargetPos);*/
		//TargetPos = VScale(TargetPos, 3);

		ClearDrawScreen();
		MV1DrawModel(Hundle);
		ScreenFlip();
	}
	
	
	WaitKey();				// �L�[���͑҂�
	MV1DeleteModel(Hundle);
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
