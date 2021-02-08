package z3;
public class E9_Student {	
	public static void main(String[] args) {
		System.out.println(Student.college+Student.major+"专业的学生信息: ");
		Student s1 = new Student(); 
        Student s2 = new Student("201612001","张三","男",19,560); 
        System.out.println("学生1:\n "+s1);
        System.out.println("学生2:\n "+s2);
	}
}
class Student {
	String no;   //学号
	String name; //姓名
	String sex;  //性别
	int age;     //年龄
	double score;//成绩
	static String college="韶关学院"; //大学
	static String major="软件工程";   //专业 
	Student() 
	{
		this.no="000000000"; //学号
		this.name="无名氏";    //姓名
		this.sex="女";        //性别
		this.age=18;         //年龄
		this.score=0;        //成绩
	}
	Student(String no,String name,String sex,int age,double score) 
	{
		this.no=no;      //学号
		this.name=name;  //姓名
		this.sex=sex;    //性别
		this.age=age;    //年龄
		this.score=score;//成绩
	}
	public String toString() {
		String t;
	    t="学号："+no+"，姓名："+name+"，性别："+sex+"\n";
	    t=t+"年龄："+age+"，成绩："+score+"\n";  
	    t=t+"大学："+college+"，专业："+major; 	    
	    return t;
	}
}
