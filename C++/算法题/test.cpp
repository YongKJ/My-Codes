//哪位大神帮我解决一下清除考生结束允许的问题啊
#include <iostream>
#include <string>
using namespace std;
struct Node {
  string str;
  double sum;
  int id;
  Node *next;
};
int main() {
  Node *head = NULL, *end = NULL, *temp = NULL;
  for (int i=0;i<5;i++){
  Node *p = new Node;
  p->next = NULL;
  
  if (head == NULL)
    head = p;
  else
    end->next = p;
    
  end = p;
  cout << "输入姓名:";
  cin >> p->str;
  
  if (p->str == "清除考生") {
    temp = head;
    int i = 0;
    cout << "输入考生座号:";
    cin >> p->id;
    
    while (1) {
      temp = temp->next;
      if (temp->str == p->str)
        break;
      i++;
    }
    
    int while1 = 0;
    while (while1 < i) {
      temp = temp->next;
    }
    
    cout << "i=:" << i;
    delete temp;
  }
  
  cout << "输入总成绩:";
  cin >> p->sum;
  cout << "输入座号:";
  cin >> p->id;
  }
  while (head != NULL) {
    cout << "1:" << head->str << "2:";
    cout << head->sum << "3:" << head->id << endl;
    head = head->next;
  }
  return 0;
}