import java.util.*;
public class HelloWorld{
	public static void main(String[] args){
		Collection c=new ArrayList();
		c.add("hello");
		c.add("world");
		c.add("java");
		System.out.println("size:"+c.size());
		System.out.println("c:"+c);
	}
}