#include "Shoot.h"
#include "Resolver.h"

void Shoot::Action(/*������*/)
{
	/*��������, ��� � ��� ��������� ��� ���� ����� ������� ������������ id*/
	HashMap unicMapID;
	unicMapID["x"] = /*id �����*/["x"];
	unicMapID["y"] = /*id �����*/["y"];
	ArrayOfObject args;
	args["0"] = "Move";
	args[/*...*/] = /*id �������*/;
	args[/*...*/] = x/*�����������*/;
	args[/*...*/] = y/*�����������*/;
	Resolver *res = new Resolver;
	res->createAndUseCommand(args);
	delete res;
}