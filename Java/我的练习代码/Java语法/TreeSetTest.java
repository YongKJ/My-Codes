import java.util.*;
public class TreeSetTest{
	public static void main(String[] args){
		Set<Integer> test=new TreeSet<>();
		int a=1,b=8,c=3;
		test.add(a);
		test.add(b);
		test.add(c);
		//遍历集合test   利用foreach遍历
		for(Integer value:test){
			System.out.print(value+" ");
		}
		System.out.println();
		//利用Iterator实现遍历		
		Iterator<Integer> value=test.iterator();
		while(value.hasNext()){
			int s=value.next();
			System.out.print(s+" ");
		}
		System.out.println();
	}
}

/*
1	
add( )         向集合中添加元素

2	
clear( )        去掉集合中所有的元素

3	
contains( )    判断集合中是否包含某一个元素

4	
isEmpty( )    判断集合是否为空

5	
iterator( )    主要用于递归集合，返回一个Iterator()对象

6	
remove( )    从集合中去掉特定的对象

7	
size( )        返回集合的大小
*/
