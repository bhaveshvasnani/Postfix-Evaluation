#include<stdio.h>
int stack[50], top=-1;
char post[50];
void push(int tmp);
void calculate(char c);
void push(int tmp){
 stack[++top]=(int)(post[tmp]-48);
}
void calculate(char operator){
 int a,b,ans;
 a=stack[top];
 stack[top--]='\0';
 b=stack[top];
 stack[top--]='\0';
 switch(operator){
  case '+':	ans=b+a;
  break;
  case '-':	ans=b-a;
  break;
  case '*':	ans=b*a;
  break;
  case '/':	ans=b/a;
  break;
  case '^':	ans=b^a;
  break;
  default:	ans=0;
 }
 stack[++top]=ans;
}
void main()
{
 int i;
 printf("\n\t\tPostfix Expression Evaluator\n\n");
 printf(" Insert a Postfix notation for only single digits: \n\t");
 gets(post);
 for(i=0;post[i]!='\0';i++){
  if(post[i]>='0' && post[i]<='9')	push(i);
  else if(post[i]=='+' || post[i]=='-' || post[i]=='*' || post[i]=='/' || post[i]=='^')	calculate(post[i]);
 }
 printf("\n Evaluated Result: \n\t%d",stack[top]);
 getch();
}

