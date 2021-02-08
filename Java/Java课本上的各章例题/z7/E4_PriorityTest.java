package z7;
public class E4_PriorityTest {
	public static void main(String[] args) {
		PriorityTest r=new PriorityTest();
		Thread t1=new Thread(r,"线程1");
        t1.setPriority(Thread.NORM_PRIORITY - 2);// 设置优先级
        t1.start();
        Thread t2=new Thread(r,"线程2");
        t2.setPriority(Thread.NORM_PRIORITY + 2);// 设置优先级
        t2.start();       
	}
}
class PriorityTest implements Runnable {
	public void run() {
		for (int i = 0; i < 10; i++) {
			System.out.println(Thread.currentThread().getName()+ ": " +i);		    
	    }
	    System.out.println(Thread.currentThread().getName()+": 完成! ");//线程结束		
    } 
}