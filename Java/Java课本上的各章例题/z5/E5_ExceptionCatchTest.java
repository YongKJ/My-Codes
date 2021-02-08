package z5;
import java.util.*;
public class E5_ExceptionCatchTest {
	public static void main(String[] args) {
		int n1=0,n2=0;
		int num[] = {1,2,3,4,5,6,7,8,9,0};
		try{
			System.out.print("请输入第1个数组元素的下标：");
            Scanner input=new Scanner(System.in);
            n1=input.nextInt();
            System.out.print("请输入第2个数组元素的下标：");
            input=new Scanner(System.in);
            n2=input.nextInt();
            System.out.println ("元素1/元素2="+num[n1]/num[n2]);
		}catch(InputMismatchException e){ //输入字母时错误
            System.out.println("异常信息："+e.getMessage());
            e.printStackTrace();
        }catch(ArrayIndexOutOfBoundsException e){ //元素的下标大于9时错误
            System.out.println("异常信息："+e.getMessage());
            e.printStackTrace();
        }catch(ArithmeticException e){ //除数为num[9]时错误
            System.out.println("异常信息："+e.getMessage());
            e.printStackTrace();
        }catch(Exception e){
        	System.out.println("异常信息："+e.getMessage());
            e.printStackTrace();
        }
		finally{
			 System.out.println("结束");
		}
	}
}