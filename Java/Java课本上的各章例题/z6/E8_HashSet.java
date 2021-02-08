package z6;
import java.util.*;
public class E8_HashSet {
	public static void main(String[] args) {
		String[] strArray = new  String[]{"one", "world ",  "one",  "dream"};     
        Set<String> s = new HashSet<String>();        
        for (int i=0; i<4; i++)
        	if (!s.add(strArray[i])) //添加strArray元素到集合s中
        		System.out.println("Duplicate detected: " + strArray[i]);
        System.out.println(s.size() + " distinct words: " + s);
	}

}