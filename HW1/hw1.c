#include "duck.h"


int main() {
    Duck* head = NULL;  // 리스트의 첫 번째 노드를 가리키는 포인터 변수
    int num;         // 메뉴 선택시 입력받은 값을 저장할 변수
    char name[30];      // 오리의 이름을 저장할 변수
    int index;          // 특정 노드를 출력하거나 삭제할 때 사용되는 변수

    print_menu(); //메뉴출력
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &num);   // 메뉴 선택
 
    while (1) {   // 프로그램 종료까지 실행되는 무한루프

        switch (num) {
        case 1: // 데이터 입력하기
            printf("잡을 오리의 이름을 입력하세요 : ");
            scanf("%s", name);
            head = catch (head, name);  // 입력받은 데이터를 리스트에 추가
            printf("%s를 잡았습니다\n", name);
            printf("\n");
            break;

        case 2: // 전체 리스트 출력하기
            printf("\n잡힌 오리들 명단입니다 \n");
            call_all(head);   // 전체 리스트 출력
            printf("\n");
            break;

        case 3: // 특정 노드 출력하기
            printf("몇 번째 오리를 확인할까요? : ");
            scanf("%d", &index);    // 출력할 노드의 인덱스를 입력
            call_one(head, index);    // 해당 노드를 출력
            printf("\n");
            break;

        case 4: // 특정 노드 삭제하기
            printf("몇 번째 오리를 꺼낼까요? : ");
            scanf("%d", &index);    // 삭제할 노드의 인덱스를 입력
            printf("\n");
            head = kill(head, index);    // 해당 노드를 삭제
            printf("\n남아있는 오리입니다 \n");
            call_all(head);
            printf("\n");
            break;

        case 5: // 프로그램 종료
            end(head);
            break;

        case 6: // 메뉴 출력
            print_menu();
            break;

        default:  // 잘못된 입력을 받을 경우
            printf("1에서 5까지 정수를 입력하세요\n\n");
            break;
        }
        if (num == 5) // 5번을 고른경우 프로그램 종료
            break;

        else { //그렇지 않은 경우 옵션을 입력받음
            printf("메뉴를 선택하세요(메뉴를 확인하시려면 6을 입력하세요) : ");
            scanf("%d", &num);
        }
    }
    return 0;
}

