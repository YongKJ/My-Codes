package z6;
import java.util.LinkedList;
public class E6_LinkedList {
	public static void main(String[] args) {
		LinkedList<String> queue = new LinkedList<String>();
		queue.addFirst("?");
		queue.addFirst("you");
		queue.addFirst("are");
		queue.addFirst("how");
		queue.addFirst("Hello");
		System.out.println(queue);
		queue.removeLast();
		queue.removeLast();
		System.out.println(queue);
	}
}