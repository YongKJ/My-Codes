package z5;
public class E4_ClassCastException {
	public static void main(String[] args) {
		Object x = new Integer(0);
	    System.out.println((String)x);//java.lang.ClassCastException
	}
}