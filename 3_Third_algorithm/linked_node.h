#ifndef LINKEDNODE_H
#define LINKEDNODE_H

//링크리스트의 노드입니다.
class linked_node{
public:
	int start, end, priority; //시작 시간, 끝 시간, 우선순위
	linked_node* next = nullptr; // 다음 노드의 주소가 저장될 linked_node 포인터 변수

	// start, end에 저장될 때 그대로 저장 되는 것이 아니라 정수 형태로 가공한다.
	linked_node(float st, float en, int pri) : start((st - 1) / 0.5), end((en - 1) / 0.5), priority (pri) {}

	// 생성자 노드이다.
	// 각 학생이 가지는 시간표를 링크 리스트를 만들 때 각 요일마다 리스트를 하나씩 가진다.
	// 각 요일의 처음 head에는 의미 없는 값이 들어가게 된다.
	linked_node() : start(-1), end(-1), priority(-1){}
};

#endif