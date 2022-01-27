// 5_메뉴1

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

// C 언어의 생각 - "구조적 (structural) 프로그래밍"
// 프로그램은 
// 1. main 함수 부터 차례대로 실행되는 실행 흐름이다.
// 2. 실행흐름을 변경하려면 조건문과 반복문을 사용하면 된다.
// 3. 프로그래밍 기능별로 분리하려면 함수를 만들면 된다.

// 객체지향 언어의 생각 (C++)
// 프로그램은 "객체들 간의 관계"이다.

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("3. 국수\n");
	printf("메뉴를 선택하세요 >> ");
	int cmd;
	scanf_s("%d", &cmd);

	switch (cmd)
	{
		// ....
	}
}
