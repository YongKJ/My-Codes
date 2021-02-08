import java.util.*;
public class StackTest{
	public static void main(String[] args){
		Stack<String> stack=new Stack<String>();
		//add方法向栈中添加元素,添加成功返回true
		stack.add("1");
		stack.add("2");
		stack.add("3");
		stack.add("4");
		stack.add("5");
		//push方法向栈中添加元素,返回结果是当前添加的元素
		stack.push("a");
		stack.push("b");
		stack.push("c");
		stack.push("d");
		stack.push("e");
		//push和add都是向栈中添加元素,底层实现也是一样的,都是先将Vector扩容,再添加

		//pop方法移除并返回栈顶元素，如果是空栈，会抛出异常：EmptyStackException
		String pop=stack.pop();
		System.out.println(pop);
		System.out.println(stack);
		//peek方法获取栈顶元素，但并不移除，如果是空栈，会抛出异常：EmptyStackException
		String peek=stack.peek();
		System.out.println(peek);
		System.out.println(stack);
		// empty方法检查栈是否是空栈
		boolean isEmpty=stack.empty();
		System.out.println(isEmpty);
		// empty方法检查栈是否是空栈
		int index=stack.search("1");
		System.out.println(index);
	}
}
