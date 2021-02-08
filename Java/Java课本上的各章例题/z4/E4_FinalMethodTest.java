package z4;
public class E4_FinalMethodTest extends FinalTest{
	/* 重写父类的终极方法出错
	public void method(){
        System.out.println("子类重写终极方法");
    }
	*/
	public static void main(String[] args) {
		Z4_4_FinalMethodTest x= new Z4_4_FinalMethodTest();
        x.method();
	}
}
class FinalTest{
    final void method(){
        System.out.println("我是终极方法");
    }
}