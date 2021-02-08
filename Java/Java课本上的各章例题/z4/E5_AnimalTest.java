package z4;
public class E5_AnimalTest {	
	public static void main(String[] args) {
		Animal dog = new Dog("狗","小黑");	
		dog.cry();
	}
}
abstract class Animal {//抽象类	
	String type;		
	Animal(String str)
	{
		type = str;	
	}	
	public abstract void cry();//抽象方法	
}
class Dog extends Animal{		
	String name;		
	Dog(String str,String n) {	
		super(str);		
		name = n;
	}		
	public void cry()  //实现抽象类中的抽象方法
	{				
		System.out.println("我是："+type+"\n我名叫："+name+"\n我的叫声是：汪汪");	
	}
}