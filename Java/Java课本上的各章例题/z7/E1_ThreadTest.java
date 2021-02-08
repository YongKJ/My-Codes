package z7;
public class E1_ThreadTest extends Thread {
	E1_ThreadTest(String str){
		super(str);		
	}
	public void run() {
		for (int i = 0; i < 4; i++) {
			System.out.println(this.getName()+ ": " +i);
			try {
				sleep((int) (Math.random() * 1000));//休眠时间
			} catch (InterruptedException e) {}
		}
		System.out.println(getName()+": 完成! ");    //线程结束
	}
	public static void main(String[] args) {
		new E1_ThreadTest("线程1").start();
		new E1_ThreadTest("线程2").start();
		new E1_ThreadTest("线程3").start();
	}
}