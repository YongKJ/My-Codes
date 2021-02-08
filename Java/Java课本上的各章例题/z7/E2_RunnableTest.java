package z7;
public class E2_RunnableTest implements Runnable {
	public void run() {
		for (int i = 0; i < 4; i++) {
			System.out.println(Thread.currentThread().getName()+ ": " +i);
			try {
				Thread.sleep((int) (Math.random() * 1000));//休眠时间
			} catch (InterruptedException e) {}
		}
		System.out.println(Thread.currentThread().getName()+": 完成! ");//线程结束		
	}	
	public static void main(String[] args) {
		E2_RunnableTest r=new E2_RunnableTest();
        new Thread(r,"线程1").start();
        new Thread(r,"线程2").start();
        new Thread(r,"线程3").start();
	}
}