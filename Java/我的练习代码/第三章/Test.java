public class Test{
	public static void main(String args[]){
		new Student("Tom",'m',90,88);
		new Student("Jack",'m',66,89);
		new Student("Mary",'f',76,86);
		System.out.println("name\tsex\tchinese\tenglisg");
		Student.print();
	}
}
class Student{
	protected String name;
	protected char sex;
	protected int chinese;
	protected int english;
	protected Student next;
	static Student list;
	Student(String name,char sex,int chinese,int english){
		this.name=name;
		this.sex=sex;
		this.chinese=chinese;
		this.english=english;
		this.next=list;
		list=this;
	}
	static void print(){
		Student friend=list;
		if(friend==null)
			System.out.println("The list is empty.");
		else{
			do{
				System.out.println(friend.toString());
				friend=friend.next;
			}while(friend!=null);
		}
	}
	public String toString(){
		return new String(name+"\t"+sex+"\t"+chinese+"\t"+english);
	}
}