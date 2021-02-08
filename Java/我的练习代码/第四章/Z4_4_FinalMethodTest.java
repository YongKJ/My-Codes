public class Z4_4_FinalMethodTest extends FinalTest{
	public static void main(String[] args) {
		Z4_4_FinalMethodTest x=new Z4_4_FinalMethodTest();
		x.method();
	}
}
class FinalTest{
	final void method(){
		System.out.println("我是终极方法");
	}
}