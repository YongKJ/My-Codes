public class Z4_5_AnimalTest{
	public static void main(String[] args) {
		Animal dog=new Dog("狗","小黑");
		dog.cry();
	}
}
abstract class Animal{
	String type;
	Animal(String str){
		type=str;
	}
	public abstract void cry();
}
class Dog extends Animal{
	String name;
	Dog(String str,String n){
		super(str);
		name=n;
	}
	public void cry(){
		System.out.println("我是："+type+"\n我名叫："+name+"\n我的叫声是：汪汪");
	}
}