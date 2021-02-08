#include <iostream>
using namespace std;
struct sqqueue {
  int *base, front, rear, tag;
};
int n = 3;
void begin(sqqueue &q) {
  q.base = new int[n];
  q.front = q.rear = q.tag = 0;
}
int in(sqqueue &q,int e){
  int t = 0;
	if(q.tag&&q.front==q.rear)
          cout << "队列已满" << endl;
        else {
          t = 1, q.base[q.rear] = e;
          q.rear = ++q.rear % n;
          if (q.rear == q.front)
            q.tag = 1;
        }
        return t;
}
int out(sqqueue &q){
  int e=0;
  if(!q.tag&&q.front==q.rear)
    cout << "队列为空" << endl;
  else {
    e = q.base[q.front];
    q.front = ++q.front % n;
    if (q.front == q.rear)
      q.tag = 0;
  }
  return e;
}
int main() {
  
  sqqueue q;
  q.base = new int[n];
  q.front = q.rear = q.tag = 0;
  for (int &i = q.rear, j = q.front, &k = q.tag, t = i; !(k && i == j); i = t)
    cin >> q.base[i], t = ++t % n ,k = t != j ? k : !k;
  for (int &i = q.front, j = q.rear, &k = q.tag,t=i; !(!k && i == j); i = t)
    cout << q.base[i], t = ++t % n, cout << (t != j ? " " : "\n"),k = t != j ? k : !k;
  return 0;
}