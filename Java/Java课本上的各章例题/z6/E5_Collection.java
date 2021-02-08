package z6;
import java.util.ArrayList;
import java.util.Collection;
public class E5_Collection {
	public static void main(String[] args) {
		Collection<String> c = new ArrayList<String>();
		c.add("hello");
		c.add("world");
		c.add("java");	
		System.out.println("c:" + c);
		System.out.println("size:" + c.size());
		System.out.println("remove hello:" + c.remove("hello"));
		System.out.println("remove javaee:" + c.remove("javaee"));
		System.out.println("contains hello:"+c.contains("hello"));
		System.out.println("contains java:"+c.contains("java"));		
		System.out.println("c:" + c);		
		Collection<String> s = new ArrayList<String>();
		s.add("hello");
		s.add("world");
		System.out.println("s:" + s);
		System.out.println("s retainAll c:"+s.retainAll(c));
        System.out.println("s:" + s);
		s.clear();
		System.out.println("s isEmpty:"+s.isEmpty());			
	}
}