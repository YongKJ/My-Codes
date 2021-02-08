public class Z4_1_StudentTest{
	public static void main(String[] args) {
		Student p=new Student();
		p.name="张三";
		p.age=18;
		p.college="韶关学院";
		p.display();
	}
}
class Student extends Z4_1Person{
	String college;
	void display(){
		super.display();
		System.out.println("我就读的学校是："+college);
	}
}