package z3;
public class E7_PassByValue {
	static void add1_value(int n)  //按值传递
  	{
		n++;
		System.out.println("在方法add1_value中，n+1后，n="+n);  	
  	}	
	public static void main(String[] args) {
		int  n=1;
		System.out.println("n的初值="+n);
		add1_value(n);
		System.out.println("调用方法add1_value后，在main中，n="+n);
	}
}