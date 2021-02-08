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
void Score::setScore(int m, int f) {
  mid_exam = m;
  fin_exam = f;
}
void Score::showScore() {
  cout << "\n期中成绩：" << mid_exam << "\n期末成绩：" << fin_exam
       << "\n总评成绩：" << (int)(0.3 * mid_exam + 0.7 * fin_exam) << endl;
}
int main() {
  Score d1;
  d1.setScore(5, 10);
  d1.showScore();
}
	