#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int Hundle = MV1LoadModel("ModelData/Wall.mv1");
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetGraphMode(200, 200, 64);
	ChangeWindowMode(true);
	SetCameraNearFar(0, 1000);
	SetCameraPositionAndTargetAndUpVec(VGet(0, 10, 0), VGet(1, 10, 0), VGet(0, 1, 0));
	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	MV1SetPosition(Hundle, VGet(0, 0, 0));
	MV1DrawModel(Hundle);
	
	WaitKey();				// �L�[���͑҂�
	MV1DeleteModel(Hundle);
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
