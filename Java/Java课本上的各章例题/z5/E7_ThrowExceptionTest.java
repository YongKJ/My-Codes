package z5;
public class E7_ThrowExceptionTest {
	int div(int x,int y)
	{
		if (y != 0) return x/y;	
        else  throw new MyException("除数不能为0"); // 抛出异常
	}	
	public static void main(String[] args) {
		E7_ThrowExceptionTest e1 = new E7_ThrowExceptionTest();
        int t;
        try{
        	t=e1.div(23,6);
            System.out.println("23/6="+t);
            t=e1.div(12,0);
            System.out.println("12/0="+t);
        }catch (MyException e){
            System.err.println(e.getMessage());
        }
	}
}
//用户定义的异常，由ArithmeticException类派生
class MyException extends ArithmeticException {	
	MyException(String msg) {
		super(msg);
		System.out.println("异常发生了");
	}
}