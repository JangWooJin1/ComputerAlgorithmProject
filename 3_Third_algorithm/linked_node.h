#ifndef LINKEDNODE_H
#define LINKEDNODE_H

//��ũ����Ʈ�� ����Դϴ�.
class linked_node{
public:
	int start, end, priority; //���� �ð�, �� �ð�, �켱����
	linked_node* next = nullptr; // ���� ����� �ּҰ� ����� linked_node ������ ����

	// start, end�� ����� �� �״�� ���� �Ǵ� ���� �ƴ϶� ���� ���·� �����Ѵ�.
	linked_node(float st, float en, int pri) : start((st - 1) / 0.5), end((en - 1) / 0.5), priority (pri) {}

	// ������ ����̴�.
	// �� �л��� ������ �ð�ǥ�� ��ũ ����Ʈ�� ���� �� �� ���ϸ��� ����Ʈ�� �ϳ��� ������.
	// �� ������ ó�� head���� �ǹ� ���� ���� ���� �ȴ�.
	linked_node() : start(-1), end(-1), priority(-1){}
};

#endif