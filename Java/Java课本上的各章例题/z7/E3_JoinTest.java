package z7;
public class E3_JoinTest {
	public static void main(String[] args) {
		String threadName = Thread.currentThread().getName();
        System.out.println(threadName + "：启动！");
        Thread1 t1 = new Thread1();
        Thread2 t2 = new Thread2(t1);
        try {
            t2.start();            
            t1.start();            
        } catch (Exception e) {
            System.out.println("main 出错了。");
        }
        System.out.println(threadName + "：结束。");
	}
}
class Thread1 extends Thread {
    public Thread1() {
        super("Thread1");
    };
    public void run() {
        String threadName = Thread.currentThread().getName();
        System.out.println(threadName + "：启动！");
        try {
            for (int i = 0; i <3; i++) {
                System.out.println(threadName + "：执行到  " + i);
                Thread.sleep(1000);
            }
            System.out.println(threadName + "：结束。");
        } catch (Exception e) {
            System.out.println(threadName + "出错了。");
        }
    }
}
class Thread2 extends Thread {
    Thread1 t1;
    public Thread2(Thread1 t1) {
        super("Thread2");
        this.t1 = t1;
    }
    public void run() {
        String threadName = Thread.currentThread().getName();
        System.out.println(threadName + "：启动！");
        try {
        	t1.join();
        	for (int i = 0; i <3; i++) {
                System.out.println(threadName + "：执行到  " + i);
                Thread.sleep(1000);
            }            
            System.out.println(threadName + "：结束。");
        } catch (Exception e) {
            System.out.println(threadName + "出错了。");
        }
    }
}