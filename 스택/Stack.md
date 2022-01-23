# Stack

스택의 핵심 특성은 LIFO 후입선출이다. 가장 마지막에 들어온 자료를 먼저 사용해야 할때 스택 자료구조를 사용한다. 스택은 공백 상태 검사, 포화 상태 검사, 삽입, 삭제, 피크 5개의 함수로 이루어져 있다.

<배열로된 스택 구현>
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element; //데이터 타입
typedef struct {      //스택을 구조체로 선언
	element data[MAX_STACK_SIZE]; //배열로된 스택
	int top;
} StackType;

void init_stack(StackType* s) {  //스택 초기화
	s->top = -1;
}

int is_empty(StackType* s) { 
	return(s->top == -1);
}

int is_full(StackType* s) { 
	return(s->top == (MAX_STACK_SIZE - 1)); 
}

void push(StackType* s, element input) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = input;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1); //에러에의한 종료
	}
	else
		return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[(s->top)];
}

int main(void) {}
```
<포인트>

* Typedef를 활용하여 데이터타입 이름을 통일, 스택을 구조체로 정의 > 자료형이 바뀌더라도 메서드, 알고리즘을 바꾸지않고 사용가능. 
* 매개변수로 포인터를 받아서 구조체와같은 복잡한 자료형을 사용가능하고 call by reference 방식으로 구조체 주소를 전달하기 때문에 여러개의 스택을 동시에 생성 할 수 있다.

```c
int main(void)
{
	StackType a;
	StackType b;
	init_stack(&a);
	init_stack(&b);
	char input[MAX_STACK_SIZE] = {};
	printf("문자열을 입력하시오");
	scanf("%s", input);
	int count_a = 0;
	int count_b = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == 'A' || input[i] == 'a') {
			push(&a, ++count_a);
		}
		if (input[i] == 'B' || input[i] == 'b') {
			push(&b, ++count_b);
		}
	}
	printf("%da%db", pop(&a), pop(&b));
}
```

<괄호검사 알고리즘>

입력으로 왼쪽가로가 들어오면 push 오른쪽가로가 들어오면 pop해서 왼쪽가로와 동일한지 확인 한다. 
```c
int check_matching(const char* in) { //const ->내용을 변경 불가능 하도록
	StackType s;
	char ch, open_ch;
	int n = strlen(in);
	init_stack(&s);

	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '[': case '{':
				push(&s, ch);
				break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(') && (ch != ')') ||
					(open_ch == '[') && (ch != ']') ||
					(open_ch == '{') && (ch != '}'))
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s))
		return 1; 
}

int main(void)
{
	const char* p = "{A(([i000w0;])}";
	if (check_matching(p) == 1)
		printf("%s 괄호검사 성공", p);
	else 
		printf("%s 괄호검사 실패", p);
	return 0;
}
```
<후위표기식 게산 알고리즘>

숫자가 들어오면 push, 연산자가 들어오면 스택에서 2개를 pop해서 연산자에 따라 연산 시행 후 다시 리턴한다. 주의) ab+면 첫번째 pop이 b임으로 2번째 pop + 첫번째pop(후입선출!!!) 
```c
int eval(char exp[]) {
	char ch;
	int num1, num2;
	StackType s;
	init_stack(&s);

	for (int i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			num2 = pop(&s);
			num1 = pop(&s);
			switch (ch) {
			case '+': push(&s, num1 + num2); break;
			case '-': push(&s, num1 - num2); break;
			case '*': push(&s, num1 * num2); break;
			case '/': push(&s, num1 / num2); break;
			}
		}
		else push(&s, (ch - '0'));
	}
	return pop(&s);
}

int main(void) {
	int result;
	result = eval("82/3-32*+");
	printf("%d", result);
}
```

<회문 판별>

```c
bool check_palindrome(StackType *s, char str2[MAX_STACK_SIZE]) {
	for (int i = 0; i < strlen(str2); i++) {
		if (pop(s) != str2[i]) return false;
	}
	return true;
}

int main(void)
{
	StackType s;
	init_stack(&s);

	char str[MAX_STACK_SIZE] = {};
	char str2[MAX_STACK_SIZE] = {};
	int count = 0; 
	printf("문자를 입력하시오");
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (('a' <= str[i] && str[i] <= 'z')) {
			push(&s, str[i]);
			str2[count++] = str[i]; 
		}
		if (('A' <= str[i] && str[i] <= 'Z')) {
			push(&s, (str[i]+32));
			str2[count++] = (str[i] + 32);
		}
	}
	if (check_palindrome(&s, str2)) {
		printf("회문입니다.");
	}
	else printf("회문이 아닙니다."); 
}
```