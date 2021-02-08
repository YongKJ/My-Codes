package z3;
public class E2_PersonTest {
	public static void main(String[] args) {
		Person p=new Person();
     	p.name="张三";
     	p.age=18;     	
     	p.height=1.7f;
     	p.weight=65;
     	p.display();
	}
}
class Person {
	String name;
	int age;
	float height;
	float weight;
	void display(){
		System.out.println("大家好！我的名字叫："+name);
		System.out.println("今年："+age+"岁");
		System.out.println("身高："+height+"米，体重："+weight+"公斤");
	}	
}