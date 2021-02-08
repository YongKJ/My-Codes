public class Person{
	String name;
	int age;
	public Person(String name,int age){
		this.name=name;
		this.age=age;
	}
	public static void main(String[] args){
		Person c=new Person("Peter",17);
		System.out.println(c.name+" is "+c.age+" years old!");
	}
}