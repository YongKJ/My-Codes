package z2;
public class E1_Student {
	static String Name="张英";//姓名
    static boolean sex=false;//性别
	static int Age=13;         //年龄	
	public static void main(String[] args) {
		System.out.println("我叫: "+Name );
		if(sex){
			System.out.println("我是男生 " );
		}
		else{
			System.out.println("我是女生 " );
		}		
		System.out.println("我今年"+Age+"岁" );
	}
}