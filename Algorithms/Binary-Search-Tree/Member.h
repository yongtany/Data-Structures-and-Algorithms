#ifndef ___Member
#define ___Member

typedef struct {
  int no;
  char name[20];
} Member;

#define MEMBER_NO 1   /* 번호를 나타내는 정수값 */
#define MEMBER_NAME 2 /* 이름을 나타내는 정수값 */

/* 회원 번호 비교 함수 */
int MemberNoCmp(const Member *x, const Member *y);


/* 회원 이름 비교 함수 */
int MemberNameCmp(const Member *x, const Member *y);

/* 회원 데이터를 출력(줄 바꿈 없음) */
void PrintMember(const Member *x);

/* 회원 데이터 출력(줄 바꿈 있음) */
void PrintLnMember(const Member *x);

/* 회원 데이터를 읽어 들임 */
Member ScanMember(const char *message, int sw);

#endif
