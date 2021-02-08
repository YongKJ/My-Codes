package z5;
public class E3_NumberFormatException {
	public static void main(String[] args) {
		int num=Integer.parseInt("abcd");
		System.out.println("num="+num);
	}
}