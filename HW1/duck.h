#ifndef DUCK_H
#define DUCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// 구조체 정의
typedef struct node {
    char name[30];  // 데이터를 저장할 멤버 변수
    struct node* next;  // 다음 노드를 가리키는 포인터
} Duck;

//함수 원형 선언
Duck* catch(Duck* head, char name[30]); // 데이터 입력하기(오리 잡기)
void call_all(Duck* head); // 전체 리스트 출력하기(현재 잡혀 있는 오리의 전체 정보 출력)
void call_one(Duck* head, int index); // 특정 노드 출력하기
Duck* kill(Duck* head, int index); // 특정 노드 삭제하기
void print_menu(); //메뉴 출력 함수
void end(Duck* head); //메모리 비우고 프로그램 종료

#endif

