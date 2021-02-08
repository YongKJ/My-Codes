package z5;
public class E1_ExceptionTest {
	public static void main(String[] args) {
		int i=0,n=0,sum = 0;
		int num [] = {1,2,3,4,5,6,7,8,9};			
		while (i <= 9) {
			sum+=num[i]; //java.lang.ArrayIndexOutOfBoundsException
			i++;
		}
		System.out.println ("总分"+sum);
        System.out.println ("均分"+sum/n); //java.lang.ArithmeticException: / by zero
	}
}