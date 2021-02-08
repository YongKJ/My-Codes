package z6;
import java.util.*;
public class E10_MapSort {
	public static void main(String[] args) {
		Map<Integer, String> map1 = new HashMap<Integer, String>(); 
	    Map<Integer, String> map2 = new LinkedHashMap<Integer, String>();
	    for(int i=0;i<10;i++){
	    	double s=Math.random()*100; //产生一个随机数，并将其放入Map中
	    	 map1.put(new Integer((int) s),"第 "+i+" 个放入的元素："+s+"\n");
	    	 map2.put(new Integer((int) s),"第 "+i+" 个放入的元素："+s+"\n");
	    }	    
	    System.out.println("未排序前HashMap："+map1);
	    System.out.println("未排序前LinkedHashMap："+map2);
	    //使用TreeMap来对另外的Map进行重构和排序
	    Map<Integer, String> sortedMap = new TreeMap<Integer, String>(map1);
	    System.out.println("排序后："+sortedMap);
	    System.out.println("排序后："+new TreeMap<Integer, String>(map2));
	}
}