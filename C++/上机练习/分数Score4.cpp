#include <iostream>
using namespace std;
class Score {
public:
  void setScore(int m, int f);
  void showScore();
private:
  int mid_exam;
  int fin_exam;
};
int main() {
  Score op1, op2;
  op1.setScore(80, 88);
  op2 = op1;
  op2.showScore();
  return 0;
}
void Score::setScore(int m, int f){
  mid_exam = m;
  fin_exam = f;
}
void Score::showScore() {
  cout << "\n期中成绩：" << mid_exam << "\n期末成绩：" << fin_exam << endl;
  cout << "期末总评：" << (int)(0.3 * mid_exam + 0.7 * fin_exam) << endl;
}