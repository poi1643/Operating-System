#include "duck.h"



// 데이터 입력하기(오리잡기)
Duck* catch (Duck* head, char name[30]) {
    Duck* new_node = (Duck*)malloc(sizeof(Duck));  // 새로운 노드 생성
    strcpy(new_node->name, name); // 새 노드에 데이터 복사
    new_node->next = NULL;  // 새 노드의 다음 노드를 NULL로 설정
    if (head == NULL) {  // 리스트가 비어있는 경우
        head = new_node;  // head에 새 노드를 할당
    }
    else {
        Duck* current = head;  // 현재 노드를 head로 설정
        while (current->next != NULL) { // 마지막 노드를 찾기위한 while문
            current = current->next; //현재 노드를 다음 노드로 이동
        }
        current->next = new_node; // 마지막 노드의 다음 노드에 새 노드 할당
    }
    return head;  // 새로운 head 포인터 반환
}

/*(나중에 잡힌 오리가 리스트의 앞쪽에 위치하는 방식)
Duck* catch (Duck* head, char name[30]) {
    Duck* new_node = (Duck*)malloc(sizeof(Duck));  // 새로운 노드 생성
    strcpy(new_node->name, name);  // 새 노드에 데이터 복사
    new_node->next = NULL;  // 새 노드의 다음 노드를 NULL로 설정
    if (head == NULL) {  // head가 NULL인 경우, 즉 첫번째 노드인 경우
        head = new_node;  // head에 새 노드를 할당
    }
    else {
        new_node->next = head; //그렇지 않을 경우 새 노드의 다음노드를 head로 설정
        head = new_node;  //head에 새 노드를 할당
    }
    return head;  // 새로운 head 포인터 반환
} 
*/


// 전체 리스트 출력하기
void call_all(Duck* head) {
    int index = 1;
    if (head == NULL)
        printf("잡힌 오리가 없습니다.\n");
    else
    {   
        printf("--------------------------\n");
        while (head != NULL) {  // head가 NULL이 아닐 때까지 루프 실행
            printf("[%d번째 오리는 %s입니다.]\n",index++, head->name);  // 현재 노드의 데이터 출력
            head = head->next;  // 다음 노드로 이동
        }
        printf("--------------------------\n");
    }
}

// 특정 노드 출력하기
void call_one(Duck* head, int index) {
    int count = 1;
    while (head != NULL) {  // head가 NULL이 아닐 때까지 루프 실행
        if (count == index) {  // 인덱스가 일치하는 노드인 경우
            printf("\n%d번째 오리는 %s 입니다.\n", index, head->name); // 사용자의 편의를 위해 index와 n번째가 동일하게 맞춤
            return;
        }
        head = head->next;  // 다음 노드로 이동
        count++;  // 노드의 개수 증가
    }
    printf("%d번째 오리가 없습니다.\n", index);  // 해당 인덱스의 노드가 없는 경우
}

// 특정 노드 삭제하기
Duck* kill(Duck* head, int index) {
    int count = 1;
    Duck* current = head;  // 현재 노드를 가리키는 포인터
    Duck* prev = NULL;  // 이전 노드를 가리킬 포인터
    while (current != NULL) {  // current가 NULL이 아닐 때까지 루프 실행
        if (count == index) {  // 주어진 인덱스에 해당하는 노드를 찾으면
            if (index == 1) {  // 삭제할 노드가 헤드 노드일 경우
                printf("%d번째 오리 %s 를 꺼냈습니다\n",index, current->name);
                head = current->next; // 헤드 노드를 변경
            }
            else {
                printf("%d번째 오리 %s 를 꺼냈습니다\n", index, current->name);
                prev->next = current->next;// 그렇지 않으면 이전 노드의 다음 노드를 현재 노드의 다음 노드로 변경
            }
            free(current);
            return head; // 첫번째 노드가 삭제된 경우 새로운 head반환
        }
        else {
            prev = current;
            current = current->next;
            count++;
        }
    }
    printf("\n%d번째 오리가 없습니다.\n", index);// 주어진 인덱스에 해당하는 노드가 없는 경우
    printf("현재 잡힌 오리는 총 %d마리 입니다.\n", count-1);
    return head; 
}


// 메뉴출력 함수
void print_menu() {
    printf("오리잡기 프로그램입니다.\n");
    printf("------------menu------------\n");
    printf("1. 오리잡기\n"); // 데이터 입력하기(문자열을 리스트에 넣기)
    printf("2. 잡힌오리 모두 확인하기\n"); // 전체 리스트 출력하기
    printf("3. n번째 오리 이름 확인하기\n"); // 특정 노드 출력하기
    printf("4. 오리 꺼내기\n"); // 특정 노드 삭제하기
    printf("5. 프로그램 종료\n");
    printf("----------------------------\n");
    printf("메뉴를 고르세요: ");
}

void end(Duck* head) {
    int count = 0;
    printf("\n");
    while (head != NULL) {  // head가 NULL이 아닐 때까지 루프 실행
        Duck* temp = head; //동적할당을 해제하기 위한 임시 포인터
        printf("%s : 살려주셔서 감사합니다!!\n\n", temp->name);
        head = head->next; // head를 다음 노드로 이동
        free(temp); // 기존의 head노드가 가리키던 동적 메모리의 할당 해제
        count++;
    }
    printf("%d마리의 오리를 살려주었습니다. 곧 프로그램이 종료됩니다...\n\n", count);
}

