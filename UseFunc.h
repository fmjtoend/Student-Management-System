#pragma once
#include"vectors.h"
class UseFunc {
public:
	UseFunc() {

	}
	~UseFunc() {

	}
	//UseInfor infors;//ʹ��ѧ����Ϣ�����Է���

	void static UseMainMnue(vectors* v);// �����˵����ܵĵ���
	void static UseInputMenu(vectors* v);// ������¼��˵����ܵĵ���
	void static UseAlterMenu(vectors* v);// �������޸Ĳ˵����ܵĵ���
	void static UseCXMenu(vectors* v);// �����ݲ�ѯ�˵����ܵĵ���
	void static UseAnaMenu(vectors* v);// �����ݷ����˵����ܵĵ���
};

