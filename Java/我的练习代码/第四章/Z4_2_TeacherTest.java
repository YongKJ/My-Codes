public class Z4_2_TeacherTest{
	public static void main(String[] args) {
		Teacher p1=new Teacher();
		Teacher p2=new Teacher("中山大学");
		p1.name="王明";
		p1.age=32;
		p1.display();
		p1.lesson("Java程序设计","数据结构");
		p2.display();
		p2.lesson("人工智能");
	}
}
class Teacher extends Z4_1Person{
	String college;
	Teacher(){
		college="韶关学院";
	}
	Teacher(String c){
		college=c;
	}
	void display(){
		super.display();
		System.out.println("我在"+college+"任教。");
	}
	void lesson(String kc){
		System.out.println("我今天的课程是："+kc);
	}
	void lesson(String kc,String xxk){
		System.out.println("今天的课程是："+kc+"，选修课是："+xxk);
	}
}