package z5;
import java.util.Scanner;
public class E9_UserExceptionTest {
	void register(int age) throws AgeException
	{
		if(age<18){
			throw new AgeException("年龄没满18岁。");
        }else{
            System.out.println("注册成功。");
        }
	}
	public static void main(String[] args) {
		E9_UserExceptionTest e1 =new E9_UserExceptionTest();
        System.out.print("用户注册开始，请输入您的年龄：");
        Scanner input=new Scanner(System.in);
        int age=input.nextInt();
        try {
			e1.register(age);
		} catch (AgeException e) {
			System.err.println(e.getMessage());
		}
	}
}
//用户定义的异常，由Exception类派生
class AgeException extends Exception {	
	AgeException(String msg) {
		super(msg);
		System.err.println("年龄不合格。");
	}
}