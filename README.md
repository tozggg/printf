# printf
[subject](https://github.com/tozggg/printf/blob/master/subject.pdf)  
stdio.h 라이브러리의 printf 함수 구현하기
<br>
<br>
## Details
```c
//형식
% [flag][width].[precision][서식지정자]

//flag
- : 왼쪽으로 정렬
0 : width를 0으로 채우기

//width
숫자 : 출력값의 최소 너비 (빈공간으로 채운다)
* : 가변인자로 width를 정한다

//precision
정수 : 최대 자리수 (0으로 채운다)
실수 : 소수점 이하의 최대 자리수

//서식지정자
c : char
s : str
p : pointer(주소)
d, i : signed 10진수
u : unsigned 10진수
x, X : unsigned 16진수
% : 문자(%)
```

### 가변인자

- 파라미터의 개수 커스텀
- 고정매개변수가 1개는 있어야됨

```c
#include <stdarg.h>

//가변 파라미터를 위한 데이터타입
va_list

//가변파라미터를 고정파라미터(last)다음으로 초기화해줌
//가변인자의 시작위치
void va_start(va_list ap, last);

//주어진 type만큼읽고 다음가변인자로 이동
type va_arg(va_list ap, type);

//가변인자 변수 사용종료
//함수의 끝에서 의무적으로 넣음
void va_end(va_list ap);

//가변인자 복사
void va_copy(va_list dest, va_list src);
```

### 예외처리

- flag 관련
    - 문자열은 0패딩 무시?
    - 정수 좌측정렬(-)시 0패딩 무시?
    - 정밀도 음수면 무시
    - 0플래그 존재, 정밀도가 양수면 0플래그 무시
- 메모리 할당(malloc) 예외처리

### 함수 나눈거

printf

%~ 개수새고, 처리하는 서브루틴

구조체에 width, prec 재설정하는 함수

서식지정자 처리로 보내는 함수

c, % 서식지정자 처리

d, i 서식지정자 처리

s 서식지정자 처리

p 서식지정차 처리

u, x, X 서식지정자 처리

---

? 구현하지않은 서식지정자가 나올시

⇒ % 뒤에있는애 출력하게끔 함

? malloc 동적할당 실패시 예외처리

? va_arg 함수가 하위함수에서 써도 상위함수로 값이 전달되는 이유

? char 가변인수 받을때 va_arg(int) 하는이유

## 예외처리

- \- flag ⇒ spec이 활성화(0, 1) 되있을시 spec 비활성화(-1)  //  *도 마찬가지
- 0 flag ⇒ width가 0이고 prec이 비활성화(-1) 되있을시에만 제로플래그

- width는 *숫 중복시 마지막에 오는것  //  prec은 *숫 중복시 첫번째 오는것을 잡았다

- ! zero, sign == 1 시에 zero 비활성화(0)
- ! zero, prec활성화(0, 1)시에 zero무효화, 단 c와 %와 s는 제외

- c
    - spec을 신경쓰지 않는다
    - width만 신경 ( width 0 일때도 출력 )
- s
    - spec 활성화시 spec만큼 잘린다

```c
!! num이 0이고 prec이 .만찍혔을때(0) 아무일도 없음

크게나눈다면 
zero == 1 // 이때는 sign이 존재할수도 없고 prec이 존재할수도 없음

sign == 1 // 이때는 prec존재 비존재여부로 0을붙여서 "뒤에 공백을"

sign == 0 // 이때는 prec존재 비존재여부로 0을붙여서 "앞에 공백을"
```

- i, d
    - 음수시 -는 넘칠때는 들어가지만 부족할때는 튀어나온다
- u, x, X
- p
    - 0x를 무조건 붙여서 시작

### 추가 예외처리

s가 null일때 (null)추가

prec에 음수가 *으로 투입됬을때는 -1 그외 올바른게 투입됬을때는 1

d, i에서 "-"를 free 하려고 했었음

num출력시 n이 0이고 prec 활성화되있는데 0이면 빈칸처리

ptr에서 0x는 숫자 바로앞에붙기 / sign플래그 처리

*에 -에들어오면 좌측정렬 x

---

## key point

- ft_printf
    1. format과 spec으로 나눔
    2. ret과 next의 차이
- spec_check
    1. info 구조체 설명 ( prec_state -1 0 1 그림그리면서 )
    2. 서식지정자가 안나왔을때의 예외처리
- set_info
    1. prec이 활성화 됬는데 -가 나온다면 prec을 무효화
    2. zero flag는 항상 그자리
- set_width_prec
    1. width는 덮어쓰기 느낌
    2. prec은 한번 할당시 고정
- info_exception
    1. sign = 1 , zero = 1 시 zero 무효화
    2. prec 활성화 , zero = 1 시 zero 무효화 ( 단, 숫자일때만 )
- char
    - spec신경 x
- str
    - spec에 따라 짤림
    - str == NULL 이면 str을 (null)로 변경
- int
    - 숫자 관련은 num==0 prec이 활성화됬는데 0일시 빈칸 출력(width만큼)
    - neg pos 나눈이유
        - -는 널널하면 들어가고 부족하면 튀어나오기 때문
        - zero플래그 존재시 -는 가장 첫번째에 나온다
- uint
    - unsigned이니 pos로만 해결
    - 어떻게 ? itoa에서 type 나눠서 처리!
- ptr
    - 0x를 붙인다
        - 빈칸출력시 sign플래그에 따라 위치 변경
        - 아니면 0x를 itoa한 str에 붙여서 len+2한담에 pos로
- 마지막 free와 join 설명후 끝
