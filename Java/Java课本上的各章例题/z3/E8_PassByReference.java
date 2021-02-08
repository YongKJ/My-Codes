package z3;
public class E8_PassByReference {
	static void add1_ByReference(TestDate n)  //按引用传递
  	{
		n.x++;
		System.out.println("在方法add1_ByReference中，n.x+1后，n.x="+n.x);  	
  	}	
	public static void main(String[] args) {
		TestDate  n=new TestDate(1);
		System.out.println("n.x的初值="+n.x);
		add1_ByReference(n);
		System.out.println("调用方法add1_ByReference后，在main中，n.x="+n.x);
	}
}
class TestDate {
	int x=0;
	TestDate(int x){this.x=x;}
}