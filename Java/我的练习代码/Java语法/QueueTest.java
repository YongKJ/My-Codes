import java.util.*;
public class QueueTest{
	public static void main(String[] args){
		Queue<String> queue=new LinkedList<String>();
		//add方法向队列中添加元素,返回布尔值，add方法添加失败时会抛异常,不推荐使用
		queue.add("1");
		queue.add("2");
		queue.add("3");
		queue.add("4");
		queue.add("5");
		//offer方法向队列中添加元素，返回布尔值
		queue.offer("a");
		queue.offer("b");
		queue.offer("c");
		queue.offer("d");
		queue.offer("e");
		// poll方法移除队列首个元素并返回，若队列为空，返回null
		String pollEle=queue.poll();
		System.out.println(pollEle);
		System.out.println(queue+"\n");
		// remove方法移除首个元素并返回,若队列为空,会抛出异常：NoSuchElementException，不推荐使用
		String remove=queue.remove();
		System.out.println(remove);
		System.out.println(queue+"\n");
		// peek方法返回队列首个元素，但不移除，若队列为空，返回null
		String peek=queue.peek();
		System.out.println(peek);
		System.out.println(queue+"\n");
		// element方法返回队列的头元素，但不移除，若队列为空，会抛出异常：NoSuchElementException，不推荐使用
		String element=queue.element();
		System.out.println(element);
		System.out.println(queue+"\n");
		//size()	返回长度
		System.out.println(queue.size());
	}
}
/*
add			增加一个元索				如果队列已满，则抛出一个IIIegaISlabEepeplian异常
remove		移除并返回队列头部的元素		如果队列为空，则抛出一个NoSuchElementException异常
element		返回队列头部的元素			如果队列为空，则抛出一个NoSuchElementException异常
offer		添加一个元素并返回true		如果队列已满，则返回false
poll		移除并返问队列头部的元素		如果队列为空，则返回null
peek		返回队列头部的元素			如果队列为空，则返回null
put			添加一个元素				如果队列满，则阻塞
take		移除并返回队列头部的元素		如果队列为空，则阻塞
size		返回长度
*/