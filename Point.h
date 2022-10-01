#include <iostream>
#ifndef POINT_H
#define POINT_H
#pragma once

using namespace std;
//������Ͽ� iostream�̶� usingnamespace ���ϸ� ��û�� �������� ������ �� ��.
class Point
{
	/*Why friend ??? -- << �� >> �� �翬�ϴ�.cout ��ü �ȿ��ٰ� �����ε� �Լ� ������ �Ұųİ�~~
	�������� �׳� ������ L-Value�� ���� ���� ��Ȳ�� ���� �׷��� �Ѱ� �ƴұ�?*/
	friend ostream& operator<<(ostream&, const Point&);
	//ĳ�����̵��� �����ؾ��ϱ� ������, ������ Lvalue�� ����������Ѵ�.
	//const�� ���� ���� : cout << (p1 + p2);���� << ������ Rvalue��. �̰� ���� �� �־���Ѵ�. �ٸ� ������� ���� �����غ��� �ڵ��̴�.
	//���� const�� &�� ���� rV�� �޴´ٸ�? �������� �߻��Ͽ� ȿ������. �׷� +�������� ������ �����ڷ�(lV��) �ϰ� const�� ���ٸ�? ���� �������� �޸𸮰� �����Ǵ� ��ü�� �����ع�����.
	//�׷� Point&&�� �ȵǳ���? - �׷� �������� �����ݾ�!
	friend istream& operator>>(istream&, Point&);
	//cin >> p1 >> p2;cin���� ��Ʈ������ ������ p1 p2�� ����. ĳ�����̵��� �����ؾ���. ������ �����Ѵ�.
	//��ü ������ ���� ����������ϱ� ������ const�� ���� ������, &�� �ʿ��ϴ�(���ϸ� �Է°� �ݿ��� ���������� ��).
	friend int operator*(const Point&, const Point&);
	//������ ����, p1 * p2 = x1 * x2 + y1 * y2��� �ϳ��� ���̴�. �� ���� ���� ���Ե� ��ü�� �ƴϴ�. �׷��� �׳� intŸ������ ����.
	//�̳��� ���� p1 + p2 * p2������ ����� p1 + int�� ���� �� �ִ� �Լ��� �� �����߰���. ���� ����� r���� ��ü�� �޴� +�Լ� ���̴�. but �׷� �Է��� ������ �߰��� �������� �ʰ���.
	friend Point& operator-=(Point&, const Point&);
	//���մ��Կ�����. ������ �׻� Lv�� ��ü�� �����ϰ�, �������� �������� �𸣴ϱ� �׳� const�� ����.
	//�̳��� ĳ�����̵� �Ǿ����. ���۷��� �ٿ��� lv�� ����. ex) rv += 3�̷��� �ȵǴϱ�.
	friend Point operator++(Point&, int);
	//���� ������. �ӽð�ü�� �����ϰ� ������ +1�� �� �ӽð�ü�� �����Ѵ�.(������ �����ϸ� ���ǹ�����. �� �޸� ������ ������ü �����ؼ� ���Ҷ��?)
	//�׸��� ���� �����ڴ� ĳ�����̵��� �Ұ����ϴ�. rv�� �����ؾ���. ������ ������. int�� ���������ڿ� �����ϱ� ���� ���� �Ű�����.
	friend bool operator!=(const Point&, const Point&);
	//�񱳿�����... �����̳� ���׿� lvalue�� �� ����, rvalue�� �� ���� ������ const�� �ٿ����.
	friend bool operator<=(const Point&, const Point&);
	//���� ����.
public:
	Point();
	Point& operator++();
	//���� ������. ++a; �׳� ȣ���� ��ü ������ ������ +1���ְ� ������ �����Ѵ�. ���� ���� �Ű������� �ʿ����. �׸��� lv�� �����ؾ� ĳ�����̵� ����.
	//++(5) ������ �ȵǴϱ�.
	bool operator==(const Point&);
	//���� ȣ���ѰŶ�... �Ű������� �ϳ��� �ʿ��ϴ�.
	Point operator+(const Point&);
	//�ȿ��� ���� ���� ���� �ӽð�ü�� �������ֱ� ������ value�� �����Ѵ�. �̰� ���۷����� �ϸ� �޸� ���Ѵ�. �׷��ٰ� *this�� �����ϸ� +�� �������϶� ��ü�� ���� �ٲ�� ��� �߻�.
	Point& operator+=(const Point&);
	//����̰�, ���׿��� lv�� ���ϱ� ���� �Ű澵 �ʿ� ���� ���׸� �Ű�������. ������ l or r
	//a += 3orb ĳ�����̵� �����ϰ� lv
	bool operator>(const Point&);
	//����� �϶�� �ϼ����� ���׿� ��ü�� ��. ���׸� �־��ְ�, �̳��� r or l

private:
	int _x;
	int _y;
};

#endif